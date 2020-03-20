//
// Created by mlste on 3/19/2020.
//

// https://codeforces.com/contest/1326/problem/B
// paso todos los testcases

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main ()
{

    int runs;
    cin >> runs;

    int max_a = 0;

    for(int run = 1; run <= runs; run++) {
        int bi;
        cin >> bi;
        int ai = bi + max_a;
        cout << ai << " ";
        max_a = max(ai, max_a);
    }
    cout << endl;
    return 0;
}