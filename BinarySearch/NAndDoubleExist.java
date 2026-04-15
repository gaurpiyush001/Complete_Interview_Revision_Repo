package basePackage;

import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public  boolean checkIfExist(int[] arr) {
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            if(binarySearch(arr,i)){
                return true;
            }
        }
        return false;
    }
//    Long to avoid stack overflow
    boolean binarySearch(int [] arr, int index){
        int start = 0;
        int end = arr.length -1;
        while(start <= end){
            int mid = start + (end - start)/2;
//            If 0 exists once so it will return true, so we need to check that we are not at the same index.
            if(index!= mid && (long)(arr[index] * 2) == (long)arr[mid]){
                return true;
            } else if((long)(arr[index] * 2) > (long)arr[mid]) {
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
}

public class NAndDoubleExist {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution s = new Solution();
		int n;
		Scanner sc= new Scanner(System.in); 
		n = sc.nextInt();
		int[] arr = new int[n];
		for(int i = 0 ; i <n;i++) {
			sc= new Scanner(System.in);
			arr[i] = sc.nextInt();
		}
		sc.close();
		System.out.println(s.checkIfExist(arr));
	}

}
