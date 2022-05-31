#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

// This Problem is similar to boundary Traversal of Matrix, But In Addition to that here we reduce the boundary in each circular traversal
void printSpiral(vector<vector<int>>& mat, int r, int c)
{
    int sr = 0, er = r;
    int sc = 0, ec = c;

    int i = sr, j = sr;

    while (1)
    {

        if (sr == j)
        {
            i = sr;
            if (i < er)
            {
                for (j = sc; j < ec; j++)
                {
                    cout << mat[i][j] << " ";
                }
                sr++;
            }
            else {
                break;
            }
            // cout<<"I executed 1st"<<endl;
        }

        else if (j == ec)
        {
            i = ec - 1;
            if (i >= sc)
            {
                for (j = sr; j < er; j++)
                {
                    cout << mat[j][i] << " ";
                }
                ec--;
            }            else {
                break;
            }
            // cout<<"I executed 2st"<<endl;
        }

        else if (j == er)
        {
            i = er - 1;
            if (i >= sr)
            {
                for (j = ec - 1; j >= sc; j--)
                {
                    cout << mat[i][j] << " ";
                }
                er--;
                j++;
            }            else {
                break;
            }
            // cout<<"I executed 3rd"<<endl;
        }

        else if (j == sc)
        {
            i = sc;
            if (i <= ec)
            {
                for (j = er - 1; j >= sr; j--)
                {
                    cout << mat[j][i] << " ";
                }
                sc++;
                j++;
            }            else {
                break;
            }
            // cout<<"I executed 4th"<<endl;

        }

        else
            break;
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    int x;

    vector<vector<int>> mat(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> x;
            mat[i][j] = x;
        }
    }

    printSpiral(mat, r, c);

    return 0;
}