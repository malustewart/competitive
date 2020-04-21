//
// Created by mlste on 4/03/2020.
//

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
// paso todos los testcases

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int setBitNumber(int n)
{
    if (n == 0)
        return 0;

    int msb = 0;
    while (n != 0) {
        n = n / 2;
        msb++;
    }

    return (msb-1);
}

int countzerosuntil(int N, int max_bit)
{
    if(!max_bit) return 0;
    int zeroes = 0;
    for (int i = 0; i < max_bit; ++i) {
        if(!(N & (1<<i))) zeroes++;
    }
    return zeroes;
}

int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++) {
        int N;
        cin >> N;
        int max_bit = setBitNumber(N);
        int zeroes = countzerosuntil(N, max_bit);
        int n = N;
        while (zeroes > (N - n))
        {
            n = n-zeroes;
            max_bit = setBitNumber(n);
            zeroes = countzerosuntil(n, max_bit);

        }

        cout << "Case #" << run + 1 << ": " << endl;

        bool amleft = true;
        int row = 0;
        for (int i = 0; i <= max_bit; ++i) {
            row = i+1;
            if(n & (1<<i))  // si recorro fila:
            {
                if(amleft)
                {
                    for (int col = 1; col <= row; ++col) {
                        cout << row << " " << col << endl;
                    }

                } else {
                    for (int col = row; col ; --col) {
                        cout << row << " " << col << endl;
                    }
                }
                amleft = !amleft;
            }
            else {
                int col = amleft ? 1 : row;
                cout << row << " " << col << endl;
            }
        }

        for (int i = 0; i < N - n - zeroes; ++i) {
            ++row;
            if(amleft)
            {
                cout << row << " " << 1 << endl;
            } else{
                cout << row << " " << row << endl;
            }
        }
    }

    return 0;
}





