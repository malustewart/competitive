//
// Created by mlste on 3/19/2020.
//

// https://codeforces.com/contest/1326/problem/F1
// timeout testcase 7
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n;
map<int, int> counts;
vector<bool> is_it_placed_yet;
vector<vector<bool>> adj;

void calc(int relationships_tracker, int remaining, int last_placed)
{

    if(!remaining)
    {
        counts[relationships_tracker]++;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if(is_it_placed_yet[i]){ continue; }
        is_it_placed_yet[i] = true;
        if(last_placed == -1)
        {
            calc(0, remaining - 1, i);
        } else {
            calc((relationships_tracker << 1) + (int)adj[last_placed][i], remaining - 1, i);
        }
        is_it_placed_yet[i] = false;
    }

}


int main ()
{

    cin >> n;


    vector<bool> row;

    char a;
    for(int i = 0; i < n; i++)
    {
        adj.push_back(row);
        getchar();
        for(int j = 0; j < n; j++)
        {
            a = getchar();
            a == '1' ? adj[i].push_back(true): adj[i].push_back(false);
        }
        is_it_placed_yet.push_back(false);
    }

    calc(0,n,-1);


    int max = 1 << n-1;

    for(int i = 0; i < max; i++)
    {
        cout << counts[i] << " ";
    }
    cout << endl;
    return 0;
}