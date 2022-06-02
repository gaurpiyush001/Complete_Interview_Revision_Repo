#include <bits/stdc++.h>
using namespace std;

int extremeOcc(vector<int> arr, int n, int x, bool flag){
        
        int ans = -1;
        int start = 0, end = n-1;
        int mid = start + (end-start)/2;
        
        while(start <= end){
            
            if(arr[mid] == x){
                ans = mid;
                if(flag){
                    end = mid-1;
                } else{
                    start = mid+1;
                }
            }
            
            else if( x < arr[mid] ){
                end = mid -1;
            }
            
            else {
                start = mid+1;
            }
            
            mid = start + (end-start)/2;
            
        }
        
        return ans;
        
        
    }
  
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        vector<int> v;
        
        v.push_back(extremeOcc(arr, n, x, true));
        if(v[0]==-1){
            return v;
        }
        v.push_back(extremeOcc(arr, n, x, false));
        
        return v;
        
    }
int main()
{
    int n, x;
    cin >> x >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> v = firstAndLast(arr, n ,x);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<< " ";
    }

    // cout<<v[0]<<" "<<v[1]<<" "<<v.size()<<endl;

    return 0;
}