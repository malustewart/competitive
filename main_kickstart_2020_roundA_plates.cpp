//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
// No anda RIP


#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int N,K,P;
        cin >> N >> K >> P;

        vector<vector<int>> stackCumSum(N);
        for(int i = 0; i < N; i++)
        {
            stackCumSum[i].resize(K+1);
            stackCumSum[i][0] = 0;
            for (int j = 0; j < K; ++j)
            {
                int beauty;
                cin >> beauty;
                stackCumSum[i][j+1] = stackCumSum[i][j] + beauty;
            }
        }

        vector<vector<int>> partAnswer(N);
        for (int i = 0; i < N; ++i) {
            partAnswer[i].resize(P + 1);
        }
        int maxPlatesPerStack = min(K,P);
        for(int i = 0; i <= maxPlatesPerStack; i++)
        {
            partAnswer[0][i] = stackCumSum[0][i];
        }


        for (int i = 1; i < N; ++i) {
            for (int j = 0; j <= P; ++j) {
                partAnswer[i][j] = 0;
                for (int k = 0; k < min(j,K); ++k) {
                    partAnswer[i][j] = max(partAnswer[i][j], partAnswer[i - 1][j - k] + stackCumSum[i][k]);
                }
            }
        }


        cout << "Case #" << run + 1 << ": " << partAnswer[N-1][P] << endl;
    }

    return 0;
}
