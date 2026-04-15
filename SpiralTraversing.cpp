#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

// This Problem is similar to boundary Traversal of Matrix, But In Addition to that here we reduce the boundary in each boundary traversal
void printSpiral(vector<vector<int>> &mat, int r, int c)
{
    int sr = 0, er = r - 1; // starting row(sr) and ending row(er)
    int sc = 0, ec = c - 1; // starting column(sc) and ending column(ec)

    int i = sr, j = sr;
    int total = r*c;
    int cnt = 0;

    while (sr <= er)
    {

        for (i = sr, j = sc; j <= ec && cnt<total; j++)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        sr++;

        for (j = ec, i = sr; i <= er && cnt<total; i++)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        ec--;

        for (i = er, j = ec; j >= sc && cnt<total; j--)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        er--;

        for (j = sc, i = er; i >= sr && cnt<total; i--)
        {
            cout << mat[i][j] << " ";
            cnt++;
        }
        sc++;
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