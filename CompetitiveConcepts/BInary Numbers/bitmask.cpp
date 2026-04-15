#include <bits/stdc++.h>
using namespace std;

int main()
{

    // ----------------------------------------------------------------------------------------------------------------------------------------

    // BITMASKING ---> ek aisa mask jo bits ke mask se bana huya hai

    // Consider this problem: There are N≤5000
    // workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30]
    // , representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.

    // You can compute the intersection of two workers (two sets) in O(30)
    // by using e.g. two pointers for two sorted sequences. Doing that for every pair of workers is O(N2⋅30)
    // , slightly too slow.

    // We can think about the availability of a worker as a binary string of length 30
    // , which can be stored in a single int. With this representation, we can count the intersection size in O(1)
    // by using __builtin_popcount(x[i] & x[j]). The complexity becomes O(N2)
    // , fast enough.

    int n;
    cin >> n;

    //ye hai aam zindagi -> O()

/*
    vector<int> days[n];

    for(int i = 0 ; i < n; i++){
        int num_workers;
        cin >> num_workers;

        for(int j=0; j < num_workers; j++){
            int day;
            cin >> day;
            days[i].push_back(day);
        }

    } 

    for(int i =0 ; i < n; i++){
        for(int j =i+1; j < n ; j++){
            //days[i], days[j]
        }
    }

    // T.C -> O(N^2 * 30)
*/

    //ab vectors ki jagah mask store krunga
    vector<int> masks(n, 0);
    for(int i = 0 ; i < n; i++){
        int num_workers;
        cin >> num_workers;
        int mask = 0;
        for(int j=0; j < num_workers; j++){
            int day;
            cin >> day;
            mask = (mask | (1<<day));
        }

        masks[i] = mask;

    } 

    int max_days = 0;
    for(int i =0 ; i < n; i++){
        for(int j =i+1; j < n ; j++){
            int intersection = (masks[i] & masks[j]);
            int common_days = __builtin_popcount(intersection);
            max_days = max(max_days, common_days);
            cout << i << " " << j << " " << common_days << endl;
        }
    }

    // now T.C --> O(N^2)



    return 0;
}