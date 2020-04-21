//
// Created by mlste on 4/03/2020.
//

// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034
// paso todos los testcases

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool compareInterval(string s1, string s2)
{
    return s1.length() < s2.length();
}

bool ordenar_last(vector<string> & words_last)
{
    sort(words_last.begin(), words_last.end(), compareInterval);
    bool good = true;
    for(int i = 0; i < words_last.size()-1; i++)
    {
        if(words_last[i].compare(0, string::npos, words_last[i+1],
            words_last[i+1].length() - words_last[i].length(), string::npos))
        {
            good = false;
            break;
        }
    }
    return good;
}


bool ordenar_first(vector<string> & words_first)
{
    sort(words_first.begin(), words_first.end(), compareInterval);
    bool good = true;
    for(int i = 0; i < words_first.size()-1; i++)
    {
        if(words_first[i].compare(0, string::npos, words_first[i+1],
                                 0, words_first[i].length()))
        {
            good = false;
            break;
        }
    }
    return good;
}


int main ()
{

    int runs;
    cin >> runs;

    for(int run = 0; run < runs; run++)
    {
        int N;
        cin >> N;
        vector<string> words_first;
        vector<string> words_last;
        vector<string> words_middle;

        size_t old_asterisk = -1, asterisk = 0;

        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;

//            int asterisk = s.find('*');
//            words_first.push_back(s.substr(0, asterisk));
//            words_last.push_back(s.substr(asterisk+1, string::npos));
//


            do
            {
                asterisk = s.find('*', old_asterisk + 1);
                string subs = s.substr(old_asterisk + 1,asterisk - (old_asterisk + 1));
                if(old_asterisk == -1){
                    words_first.push_back(subs);
                }
                else if(asterisk == string::npos){
                    words_last.push_back(subs);
                } else {
                    words_middle.push_back(subs);
                }
                old_asterisk = asterisk;
            }
            while(asterisk != string::npos);

        }
        string answer = "*";

        cout << "Case #" << run + 1 << ": ";
        if(!ordenar_first(words_first) || !ordenar_last(words_last))
        {
            cout << "*" << endl;
        } else {
            cout << words_first[N-1];
            for(auto& word : words_middle)
            {
                cout << word;
            }
            cout << words_last[N-1] << endl;
        }


    }

    return 0;
}





