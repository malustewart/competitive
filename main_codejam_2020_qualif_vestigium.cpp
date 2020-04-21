//
// Created by mlste on 4/03/2020.
//

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
// paso todos los testcases

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

        vector<vector<bool>> rows(N);
        vector<vector<bool>> cols(N);


        for(auto& row : rows)
        {
            row = vector<bool>(N+1, false); //En el bool N guardo si la fila esta mal
        }

        for(auto& col : cols)
        {
            col = vector<bool>(N+1, false); //En el bool N guardo si la col esta mal
        }

        int trace = 0;

        for (int i = 0; i < N; ++i) {   //rows
            for (int j = 0; j < N; ++j) { //cols
                int n;
                cin >> n;
                if(i == j)
                {
                    trace += n;
                }
                n--;
                if(rows[i][n]) {
                    rows[i][N] = true;
                }
                rows[i][n] = true;


                if(cols[j][n]) {
                    cols[j][N] = true;
                }
                cols[j][n] = true;
            }
        }

        int countc = 0;
        int countr = 0;
        for (int i = 0; i < N; ++i) {
            if(rows[i][N]) countr++;
            if(cols[i][N]) countc++;
        }

        cout << "Case #" << run + 1 << ": " << trace << " " << countr << " " << countc << endl;
    }

    return 0;
}
