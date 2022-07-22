//------------------easy question hai bilkul-----------------------///

////////----: Kuch questions tha mere mann m--:
//Q1.) Is this not a backtracking problem?? can we solve by it---> hn bhai solve toh kr skta hai But Time Complexity bhot Zyada aajayegi --> N!
//But agar mein isse Single Source Shortest Path(Dijkstra Algo) se kru tb effecient solution ho jayega ---> NLogn ka, because ek loop priority Queue ka hi chlega

//Q2.) Why can't we apply dp on this ?? (hint -: 2 path mein hi jb possibility ho tb lgg jaati hai DP)

#include <bits/stdc++.h>
using namespace std;

//This is a utility function, Just checking while moving we are Withing the boundary of grid OR not
bool isValidPos(pair<int, int> pos, int n)
{
    int x = pos.first;
    int y = pos.second;

    if (x >= 0 and x < n and y >= 0 and y < n)
    {
        return true;
    }
    return false;
}


int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();

    // Why this?? ---> because ab mujhe cost maintain rkhni hai (x,y) coordinate ki toh priority queue mein {Cost, {x,y}} ye rkkha jayega
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;//comparator isliye pass kiya hai bcz by default in cpp priority_quque makes a MAX_HEAP, But we want MIN_HEAP

    //As in Dijkstra Algo, I uslually uses a space for Distance Vector, bottom right cell which is final destination holds the Final Answer (i.e (n-1,n-1) cell)
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

    //ye bs mere possible moves ki array as from (i,j) i can move to --> (i+1,j) or (i-1,j) or (i,j+1) or (i,j-1)  
    vector<pair<int, int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    pq.push({grid[0][0], {0, 0}});//pushing the starting point to priority_queue
    distance[0][0] = grid[0][0];//intitalizing the starting position in distance vector

    while (!pq.empty())
    {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int dist = curr.first;
        pair<int, int> pos = curr.second;

        int x = pos.first;
        int y = pos.second;

        for (pair<int, int> move : moves)
        {
            int nx = x + move.first;
            int ny = y + move.second;

            if (isValidPos({nx, ny}, n) and distance[nx][ny] > dist + grid[nx][ny])
            {
                distance[nx][ny] = dist + grid[nx][ny];
                pq.push({distance[nx][ny], {nx, ny}});
            }
        }
    }

    return distance[n - 1][n - 1];
}

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

    int ans = minimumCostPath(grid);
    cout << ans << "\n";
    return 0;
}
