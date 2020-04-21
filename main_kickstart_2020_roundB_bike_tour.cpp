//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
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
        long long int N;
        cin >> N;
        vector<int> h;
        for (int i = 0; i < N; ++i) {
            int height;
            cin >> height;
            h.push_back(height);
        }

        bool ishigher = false;
        int count = 0;
        for (int j = 0; j < N-1; ++j) {
            if(ishigher && h[j] > h[j+1])
            {
                count++;
                ishigher = false;
            }
            ishigher = h[j] < h[j+1];
        }

        cout << "Case #" << run + 1 << ": " << count << endl;
    }

    return 0;
}
