//
// Created by mlste on 3/21/2020.
//

// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050eda/0000000000119866
// paso los dos tests


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main ()
{

    int runs;
    cin >> runs;


    for(int run = 0; run < runs; run++)
    {
        int nletters, nquestions;
        cin >> nletters >> nquestions;

        string letters;
        cin >> letters;

        vector<bitset<26>> banana(nletters + 1);// el bit 0 se togglea cuando aparece una A, el bit 1 cuando aparece una B, etc.
                                                // si agarro dos posiciones y el bit x es igual en ambas, se que se toggleo una
                                                // cantidad par de veces => entre ellas hay una cantidad par de esa letra
        banana[0] = bitset<26>(0);

        for(int i = 0; i < nletters; i++)
        {
            banana[i+1] = banana[i];
            banana[i+1].flip(letters[i]-'A');      // Cada bitset es igual al enterior excepto porque toggle el bit de la letra del input
        }

        int palindromes = 0;
        for(int i = 0; i < nquestions; i++)
        {
            int left,right;
            cin >> left >> right;

            bitset<26> xor_bits = banana[left-1] ^ banana[right];
            int odds = xor_bits.count();
            if((right - left + 1) % 2 == odds)
            {
                palindromes++;
            }

        }


        cout << "Case #" << run+1 << ": " << palindromes << endl;
    }


    return 0;
}