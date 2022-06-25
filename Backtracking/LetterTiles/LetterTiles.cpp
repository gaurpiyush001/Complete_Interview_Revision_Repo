#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-tile-possibilities/

//kyunki ye ek backtracking approach hai toh, We have to make sure that in every Recursive Call we need to process every character ---> SO THIS REASON OF LOOP

//As every neew charcater is inserted in O/P string then there can be possible REPEATITIONS----> So in order to counter that we have used SET DATA STRUCTURE


void totalTilePoss(string tiles, set<string>& res, map<int, bool>& mp, string& output)
{

    //loop is here for processing every character
    for (int i = 0; i < tiles.length(); i++)
    {
        //below we will check if the current char has been processed or not---(Ishi kaam ke liye MAP Data structure is used)
        if (mp[i] == 0)
        {
            output.push_back(tiles[i]);
            mp[i] = 1;
            res.insert(output);

            totalTilePoss(tiles, res, mp, output);

            //Below two lines shows backtracking
            //if iss recursive call ka result mil gaya and I have to go to another recursive call then firstly , I will undo the changes OR BACKTRACK the changes and then move to further call 
            output.pop_back();
            mp[i] = 0;
        }
    }
}

int main()
{
    string tiles;
    cin >> tiles;

    set<string> res;
    map<int, bool> mp;
    string output = "";

    totalTilePoss(tiles, res, mp, output);
    cout << res.size() << endl;
    return 0;
}