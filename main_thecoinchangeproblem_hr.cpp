//https://www.hackerrank.com/challenges/coin-change/problem
//paso todos los test cases <3

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

typedef vector<long> vecl;
typedef vector<vecl> matl;
typedef vector<bool> vecb;

long getWays(int n, vector<long> c) {
    static bool first = true;
    static matl solution;
    static vecb ready;

    if(first)
    {
        first = false;
        solution.resize(n+1);
        for(auto& s : solution)
        {
            s.resize(c.size()+1,0);
        }
        solution[0][0] = 1;

        ready.resize(n+1, false);
        ready[0] = true;
    }

    long total_ways = 0;
    for(int i = 0; i < c.size(); i++)
    {
        long ways = 0;
        long coin = c[i];
        if(n-coin < 0) continue;    //si hago sort puedo poner break
        if(!ready[n-coin])
        {
            getWays(n-coin,c);
            //           cout << "Solution for n = " << n-coin << ": " << solution[n-coin][i] << endl;
        }
        for(int j = 0; j <=i; j++)
        {
            ways += solution[n-coin][j];
        }
        solution[n][i] = ways;
        total_ways+=ways;
    }
    ready[n] = true;


    cout << "n = " << n << ", total_ways = " << total_ways << "\n";
    return total_ways;
}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    fout << ways << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}