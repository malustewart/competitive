//
// Created by mlste on 3/19/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/000000000006987d
// no terminado RIP

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef struct parcel{
    int r;
    int c;
    parcel()
    {
        r = 0;
        c = 0;
    }
    parcel(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
} parcel;

unsigned int distance(parcel first, parcel second)
{
    return abs(first.r - second.r) + abs(first.c - second.c);
}

//Buscar office mas cerca a cada esquina
//top_right

parcel find_closest(vector<parcel>& parcels, parcel center)
{
    unsigned int best_distance = UINT32_MAX;
    parcel closest;
    for(auto it = parcels.begin(); it < parcels.end(); it++) {
        unsigned int dist = distance(center, *it);
        if (dist < best_distance) {
            best_distance = dist;
            closest = *it;
        }
    }
    return closest;
}




int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int R,C;
        cin >> R >> C;

        vector<parcel> offices;
        int is_office_here;
        int ** distances = new int * [R];


        for(int r = 0; r < R; r++)
        {
            getchar();
            for(int c = 0; c < C; c++)
            {
                char ch = getchar();
                if(ch == '1') offices.push_back(parcel(r,c));
            }
            distances[r] = new int[C];
        }




        //Matriz de R por C con la minima distancia a una office
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                distances[r][c] = distance(find_closest(offices, parcel(r,c)), parcel(r,c));

            }
        }

    }


//    for(int run = 0; run < runs; run++)
//    {
//        int R,C;
//        cin >> R >> C;
//
//        vector<parcel> offices;
//        int is_office_here;
//        for(int r = 0; r < R; r++)
//        {
//            getchar();
//            for(int c = 0; c < C; c++)
//            {
//                char ch = getchar();
//                if(ch == '1') offices.push_back(parcel(r,c));
//            }
//        }
//
//        //Buscar office mas cerca a cada esquina
//
//        vector<parcel> image_offices;
//        // top left
//        parcel closest = find_closest(offices, parcel(0,0));
//        image_offices.push_back(parcel(-distance(closest, parcel(0,0)), 0));
//        // top right
//        closest = find_closest(offices, parcel(0,C-1));
//        image_offices.push_back(parcel(-distance(closest, parcel(0,C-1)), C-1));
//        // bottom left
//        closest = find_closest(offices, parcel(R-1,0));
//        image_offices.push_back(parcel(R - 1 + distance(closest, parcel(R-1,0)), 0));
//        // top left
//        closest = find_closest(offices, parcel(R-1,C-1));
//        image_offices.push_back(parcel(R - 1 + distance(closest, parcel(R-1,C-1)), C-1));
//
//        offices.insert(offices.end(), image_offices.begin(), image_offices.end());
//
//    }


    return 0;
}