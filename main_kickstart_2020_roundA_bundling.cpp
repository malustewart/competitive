//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
// wrong answer :(


#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int N,K;
        cin >> N >> K;

        vector<string> s;
        int maxlen = 0;
        for (int i = 0; i < N; ++i) {
            string in;
            cin >>in;
            s.push_back(in);
            maxlen = max((int)in.length(), maxlen);
        }


        sort(s.begin(), s.end());
        vector<unsigned int> preflens;
        preflens.push_back(0);
        for (int i = 0; i < N-1; ++i) {
            int preflen = 0;
            while(s[i][preflen] == s[i+1][preflen]
            && preflen + 1 < s[i].length()
            && preflen + 1 < s[i+1].length())
            {
                preflen++;
            }
            preflens.push_back(preflen);
        }
        int h = 0;
        //cout << "Case #" << run + 1 << ": " << max_beauty << endl;
    }

    return 0;
}




////
//// Created by mlste on 3/22/2020.
////
//
//
//#include <iostream>
//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//
//int banana (unsigned int plates_left, unsigned int stacks_left, int beauty, vector<vector<int>>::iterator stack, int max_beauty)
//{
//    if(stacks_left == 1)
//    {
//        beauty += (*stack)[min((unsigned int)((*stack).size()-1) , plates_left)];
//        return max(max_beauty, beauty);
//    }
//    if(!plates_left)
//    {
//        return max_beauty;
//    }
//    for(int i = 0; i <= plates_left && i < (*stack).size(); i++)
//    {
//        max_beauty = banana(plates_left - i, stacks_left - 1, beauty + (*stack)[i], stack+1, max_beauty);
//    }
//    return max_beauty;
//}
//
//int main ()
//{
//
//    int runs;
//    cin >> runs;
//
//    for(int run = 0; run < runs; run++)
//    {
//        int N,K,P;
//        cin >> N >> K >> P;
//
//
//        cout << "Case #" << run + 1 << ": " << max_beauty << endl;
//    }
//
//    return 0;
//}
//

