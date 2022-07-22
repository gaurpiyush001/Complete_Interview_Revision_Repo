#define ss second
#define ff first
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
/*class prio {

    public:
    //we are using a comparator for priority queue for storing elements with minmum cost
    bool operator()(pair<int, pair<int,int>> &p1, pair<int, pair<int,int>> &p2){
        return p1.ss.ss > p2.ss.ss;
    }

};*/

// Utility Function
//  from (i,j) to (i+1,j) or (i-1,j) or (i,j+1) or (i,j-1)
//  --> But Within the grid, so at each step of moving
// I will check Is it within the boundry
bool valid(int i, int j, int n)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}

// Function to return the minimum cost to react at bottom
// right cell from top left cell.
int minimumCostPath(vector<vector<int>> &grid)
{
    // Code here

    // pehle mujhe Adjacency List taiyaar->nhi krni bhai
    int gridSize = grid.size();

    // bwelow Data structure maintians the track of Visiting nodes
    vector<vector<int>> vis(505, vector<int>(505, 0));

    // final data structure for maintaining Minimum cost to reach each edge
    // Intializing it by maximum cost, as in Dijkstra we will be keep on
    // relaxing these cost
    vector<vector<int>> dis(505, vector<int>(505, 10e8));

    // storing x-axis, y-axis and cost
    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty())
    {

        pair<int, pair<int, int>> tp = pq.top();

        pq.pop();

        int x = tp.ss.ff, y = tp.ss.ss;

        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {

            if (valid(x + dx[i], y + dy[i], 4))
            {

                if (dis[x + dx[i]][y + dy[i]] > dis[x][y] + grid[x + dx[i]][y + dy[i]])
                {
                    dis[x + dx[i]][y + dy[i]] = dis[x][y] + grid[x + dx[i]][y + dy[i]];
                    pq.push({dis[x + dx[i]][y + dy[i]], {x + dx[i], y + dy[i]}});
                }
            }
        }
    }

    return dis[gridSize - 1][gridSize - 1];
}

// { Driver Code Starts.
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    // Solution obj;
    int ans = minimumCostPath(grid);
    cout << ans << "\n";

    return 0;
} // } Driver Code Ends