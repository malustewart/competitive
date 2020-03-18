// https://www.hackerrank.com/challenges/equal/problem
// paso 15/16 testcases, fallo en el ultimo.

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<int> moves;
vector<bool> done;
vector<int> possible = {5,2,1};

int get_moves(int n);


// Complete the equal function below.
int equal(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int offset = *arr.begin();


    moves.resize((*(arr.end()-1)) + 1, -1);
    done.resize((*(arr.end()-1)) + 1, false);
    done[0] = true;
    done[1] = true;
    done[2] = true;
    done[5] = true;
    moves[0] = 0;
    moves[1] = 1;
    moves[2] = 1;
    moves[5] = 1;
    int totaltotal = INT32_MAX;
    for(int i = 0; i <= offset; i++)
    {
        int total = 0;
        for(auto element : arr)
        {
            element -= i;
            total += get_moves(element);
        }
        totaltotal = min(totaltotal, total);

    }

    return totaltotal;
}

int get_moves(int n)
{
    if(done[n]) return moves[n];

    for(auto p : possible)
    {
        if(p>n) continue;
        done[n] = true;
        moves[n] = get_moves(n-p)+1;
        return moves[n];
    }
    return -1;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
