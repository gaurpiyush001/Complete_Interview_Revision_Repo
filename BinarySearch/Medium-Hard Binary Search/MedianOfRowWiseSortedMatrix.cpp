//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1


//---->Nesting of binary search
int median(int arr[][], int r, int c) {
        
        
        int low = arr[0][0] ; 
        int high=0; 
        int leftpart = (r*c)/2;
        
        
        /*
         The matrix is row wise sorted : means
         Highest elemet will be in LAST column of any row
         Lowest element will be in FIRST column of any for
        */
        
        for( int row=0 ; row<arr.length ; row++){  
            high = Math.max( high , arr[row][arr[0].length-1]);
            low = Math.min( low , arr[row][0] );
        }
        
        int ans=-1;
        
        while( low<=high ){
            
            int mid = (low+high)/2;
            int count = findcount( arr , mid);
          
            if( count <= leftpart) {
                low = mid+1;
                ans = mid;
            }
            else high = mid-1;
            
        }
        return ans;
        
    }
    
    
    static int findcount( int[][] arr , int mid ){
        
        int count=0;
        
        /*
        sending individual rows for countring elements less than mid;
        The adding total count;
        */
        
        for( int row=0; row<arr.length ; row++){
            
            count+= findInSingleRow( arr , row , mid); 
            
        }
        return count;
    }
    
    static int findInSingleRow( int[][] arr , int row , int mid){ // 
        
        /* 
        Using Binary Search to find the count of element less than our MID
        */
        
        int start=0; int end = arr[0].length-1;
        
        int count = 0;
        while( start<=end){
            int center = (start+end)/2; 
        
            if( arr[row][center] < mid ){
                start = center+1;
                count = center +1 ;
            }
            else{
                end = center-1;
            }
        }
        
        return count;
        
    }

//------------------> Above method can also be implemented by STL using upper Boound function to get the count of element less than current element
int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
 
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than or equal to mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

//Just for refernce
Input : 10 20 30 40 50
Output : upper_bound for element 45 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 60 is at index 5