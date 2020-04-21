//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
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
        int N,B;
        cin >> N >> B;

        vector<int> prices;

        for(int i = 0; i < N; i++)
        {
            int price;
            cin >> price;
            prices.push_back(price);
        }
        sort(prices.begin(), prices.end());

        int money_spent = 0;
        int houses = 0;
        for(int i = 0; i < N; i++)
        {
            money_spent +=prices[i];
            if(money_spent <= B)
            {
                houses++;
            } else break;
        }
        cout << "Case #" << run+1 << ": " << houses << endl;


    }

    return 0;
}
