//
// Created by mlste on 3/13/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/00000000000698d6
// primero paso, el segundo time limit exceeded


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int N,P;
        cin >> N >> P;

        vi people;
        int skills;
        for(int i = 0; i < N; i++)
        {
            cin >> skills;
            people.push_back(skills);
        }
        sort(people.begin(), people.end());
        for(auto it = people.rbegin(); it != people. rend()-1; it++)
        {
            *it = *it - *(it+1);    //array de diferencias
        }

        unsigned int best = UINT32_MAX;
        for(int i = 1; i <= N - P + 1; i++)
        {
            unsigned int current = 0;
            for(int j = 1; j < P; j++)
            {
                current += people[i+j-1]*j;
            }
            best = min(current, best);

        }
        cout << "Case #" << run + 1 << ": " << best << endl;
    }


    return 0;
}