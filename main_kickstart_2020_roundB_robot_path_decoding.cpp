//
// Created by mlste on 3/22/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
// paso todos los testcases

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class pos
{
public:
    ll r,c;
    pos(int _r, int _c) {r=_r%1000000000; c=_c%1000000000;}
    pos() {r = 0; c = 0;}
    pos operator+(const pos& p2)
    {
        return pos((r+p2.r)%1000000000, (c+p2.c)%1000000000);
    }
};
pos displacement(char ** s2p);

int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        string s;
        cin >> s;

        char * ss = (char*)s.c_str();
        pos dis = displacement(&ss);

        cout << "Case #" << run + 1 << ": " << dis.c + 1 << " " << dis.r + 1 << endl;
    }

    return 0;
}

pos displacement(char ** s2p)
{
    static int a = 0;
    pos p;
    while((**s2p) != ')' && ((**s2p) != 0))
    {
        switch(**s2p) {
            case 'N':
                p = p + pos(1000000000-1, 0);
                break;
            case 'W':
                p = p + pos(0, 1000000000-1);
                break;
            case 'S':
                p = p + pos(1, 0);
                break;
            case 'E':
                p = p + pos(0, 1);
                break;
            default:
                int mul = **s2p - '0';
                *s2p+=2;
                pos disp = displacement(s2p);
                p= p + pos(((disp.r%1000000000) * mul)%1000000000, ((disp.c%1000000000)*mul)%1000000000);
                p.r = p.r%1000000000;
                p.c = p.c%1000000000;
        }
        p.r = p.r%1000000000;
        p.c = p.c%1000000000;
        (*s2p)++;
    }
    p.r = p.r%1000000000;
    p.c = p.c%1000000000;
    return p;
}