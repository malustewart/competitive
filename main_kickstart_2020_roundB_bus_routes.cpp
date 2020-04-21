//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
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
        long long int N,D;
        cin >> N >> D;
        vector<long long int> delays;
        for (long long int i = 0; i < N; ++i) {
            long long int X;
            cin >> X;
            delays.push_back(X);
        }
        long long int start = D;
        for(long long int i = N-1; i >=0; i--)
        {
            start -= start % delays[i];
        }

        cout << "Case #" << run + 1 << ": " << start << endl;
    }

    return 0;
}
