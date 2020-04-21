//
// Created by mlste on 4/03/2020.
//

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
// paso todos los testcases

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef struct {
    int first;
    pii second;
    bool J;
}pipii;


bool sortbystart(const pipii &a,
                 const pipii &b);

bool sorttooriginalorder(const pipii &a,
                         const pipii &b);


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

    }

    return 0;
}

bool canput(int number, vector<vector<int>>& mat)
{

}







////
//// Created by mlste on 4/03/2020.
////
//
//
//#include <iostream>
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef pair<int,int> pii;
//typedef struct {
//    int first;
//    pii second;
//    bool J;
//}pipii;
//
//
//bool sortbystart(const pipii &a,
//                 const pipii &b);
//
//bool sorttooriginalorder(const pipii &a,
//                         const pipii &b);
//
//
//int main ()
//{
//
//    int runs;
//    cin >> runs;
//
//    for(int run = 0; run < runs; run++)
//    {
//        bool impossible = false;
//        int N;
//        cin >> N;
//        string answer;
//
//        vector<int> busyJ(2000, false);
//        vector<int> busyC(2000, false);
//
//        vector<pipii> slots;
//
//        for (int i = 0; i < N; ++i) {
//            int start,end;
//            cin >> start >> end;
//            pipii slot{i,pii(start,end), false};
//            slots.push_back(slot);
//        }
//
//        sort(slots.begin(), slots.end(), sortbystart);
//
//        //sort by start
//        for (int i = 0; i < N; ++i)
//        {
//            int start = slots[i].second.first;
//            int end = slots[i].second.second;
//
//            auto it = find(busyJ.begin()+start, busyJ.begin()+end, true);
//
//            if( it == busyJ.begin()+end)
//            {
//                fill(busyJ.begin()+start, busyJ.begin()+end, true);
//                slots[i].J = true;
//            }
//            else if(find(busyC.begin() + start, busyC.begin() + end, true) == busyC.begin()+end)
//            {
//                fill(busyC.begin() + start, busyC.begin() + end, true);
//                slots[i].J = false;
//            }
//            else{
//                impossible = true;
//            }
//        }
//
//
//        sort(slots.begin(), slots.end(), sorttooriginalorder);
//
//
//
//
//        cout << "Case #" << run+1 << ": ";
//        if(impossible)
//        {
//            cout << "IMPOSSIBLE" << endl;
//        } else {
//            for(auto& slot : slots)
//            {
//                slot.J ? cout << "J" : cout << "C";
//            }
//            cout << answer << endl;
//        }
//
//    }
//
//    return 0;
//}
//
//bool sortbystart(const pipii &a,
//               const pipii &b)
//{
//    return (a.second.first < b.second.first);
//}
//
//bool sorttooriginalorder(const pipii &a,
//                           const pipii &b)
//{
//    return a.first < b.first;
//}