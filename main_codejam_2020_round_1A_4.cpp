//
// Created by mlste on 4/03/2020.
//


#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int N;
        cin >> N;

        vector<vector<int>> mat;
        for (int i = 0; i < N; ++i) {
            mat.push_back(vector<int>(N));
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                mat[i][j] = (i + j + 1) % N;
            }
        }

        vector<int> diag = {1,2,3,3};


        cout << "Case #" << run + 1 << ": ";
    }

    return 0;
}





