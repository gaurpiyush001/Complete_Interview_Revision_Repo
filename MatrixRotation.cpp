#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
// For 180 degree rotation -: 
//method 1->we will have to print the given matrix in a reverse manner.
//method 2 => There are four steps : 
/*1- Find transpose of a matrix. 
2- Reverse columns of the transpose. 
3- Find transpose of a matrix. 
4- Reverse columns of the transpose*/
////////////////////////////////////////////////////////////////////////////////////////////////

//Naive approach --> O(N^2) time and O(N^2) space
//last coloumn becomes the first row and 2nd last coloumn becomes 2nd row....and so on...

//O(N^2) time with O(1) space ---> 2 times traversal of matrix
//Simple Approach for Anti-Clockwise Matrix Rotation by 90degree is ---->first by "finding the Transpose" and then "Reversing the coloumns" 
//Simple Approach for Clockwise Matrix Rotation by 90degree is ---->first by "finding the Transpose" and then "Reversing the rows" 


//O(N^2) time with O(1)Space ---> Onlyt 1 time traversal of array
// Function to rotate matrix anticlockwise by 90 degrees.
/*
void rotateby90(int arr[R][C])
{
    int n = R; // n=size of the square matrix
    int a = 0, b = 0, c = 0, d = 0;
 
    // iterate over all the boundaries of the matrix
    for (int i = 0; i <= n / 2 - 1; i++) {
 
        // for each boundary, keep on taking 4 elements (one
        // each along the 4 edges) and swap them in
        // anticlockwise manner
        for (int j = 0; j <= n - 2 * i - 2; j++) {
            a = arr[i + j][i];
            b = arr[n - 1 - i][i + j];
            c = arr[n - 1 - i - j][n - 1 - i];
            d = arr[i][n - 1 - i - j];
 
            arr[i + j][i] = d;
            arr[n - 1 - i][i + j] = a;
            arr[n - 1 - i - j][n - 1 - i] = b;
            arr[i][n - 1 - i - j] = c;
        }
    }
}
*/

void rotate90(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    //1.) Tranpose
    for(int i = 0 ; i < row; i++)	{
        for(int j = 0 ; j < col; j++)	{
            if(j>=i){
                swap(matrix[i][j], matrix[j][i]);
            }   
        }
    }

    //2.) Reversing coloumns
    for(int j = 0 ; j < col; j++)	{
        int p = 0, q = row-1;
        while(q>=p){
            swap(matrix[p][j], matrix[q][j]);
            p++;
            q--;
        }
    }

} 

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i = 0 ; i < n; i++)	{
        for(int j = 0 ; j < n; j++){
            cin>>matrix[i][j];
        }
    } 

    rotate90(matrix);

    for(int i = 0 ; i < n; i++)	{
        for(int j = 0 ; j < n; j++)	{
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}