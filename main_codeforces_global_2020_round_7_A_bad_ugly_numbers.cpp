//
// Created by mlste on 3/19/2020.
//

// https://codeforces.com/contest/1326/problem/A
// paso todos los testcases

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main ()
{

    int runs;
    cin >> runs;


    for(int run = 0; run < runs; run++) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "-1" << endl;
            continue;
        }
        if(n == 2)
        {
            cout << "23" << endl;
            continue;
        }

        for (int i = 1; i <= n - 2; i++) {
            cout << '2';
        }
        (n - 1) % 3 ? cout << "2" : cout << "3";
        cout << "3" << endl;

    }
    return 0;
}