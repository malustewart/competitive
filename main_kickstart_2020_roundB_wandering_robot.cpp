//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565
// paso todos los testcases

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<double> _logfact(300000,0);
vector<bool>_logfactcalc(300000,false);

double logfact(int n)
{
    if(_logfactcalc[n])
    {
        return _logfact[n];
    }
    if(n == 0)
    {
        _logfactcalc[n] = true;
        return 0;
    }
    _logfact[n] = logfact(n-1) + log2(n);
    _logfactcalc[n] = true;
    return _logfact[n];
}


// Returns value of Binomial Coefficient C(n, k)
double get_prob(int n, int k)
{
    double exponent = logfact(n) - logfact(n-k) - logfact(k) - n;
    return pow(2,exponent);
}



int main ()
{
    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int W, H, L, U, R, D;
        cin >> W >> H >> L >> U >> R >> D;
        W--;
        H--;
        L--;
        U--;
        R--;
        D--;
        double prob = 0.0;
        if(D != H)
        {
            for (int i = 0; i < L; ++i) {
                prob += get_prob(D+L, i);
            }
        }
        if(R != W)
        {
            for (int i = 0; i < U; ++i) {
                prob += get_prob(R+U, i);
            }
        }

        cout << "Case #" << run + 1 << ": " << prob << endl;
    }

    return 0;
}
