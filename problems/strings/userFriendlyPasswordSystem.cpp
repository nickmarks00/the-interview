/*
 * USER FRIENDLY PASSWORD SYSTEM
 * FROM: Hackerrank
 * LANGUAGE: C++
 * Description:
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'authEvents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY events as parameter.
 */

int p = 131;
int m = 1000000007;

int hash_string(string password) {
    int n = password.length();
    long sum = 0;
    for (int i = 0; i < n; i++) { sum = (sum * p + password[i]) % m; }

    return (int)sum;
}

int authorize(long correctHash, long inputHash) {
    if (correctHash == inputHash) { return 1; }
    correctHash = (correctHash * p) % m;

    for (int i = '0'; i <= '9'; i++) {
        if ((correctHash + i) % m == inputHash) { return 1; }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if ((correctHash + i) % m == inputHash) { return 1; }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if ((correctHash + i) % m == inputHash) { return 1; }
    }
    return 0;
}

vector<int> authEvents(vector<vector<string>> events) {
    vector<int> results = {};
    string password;
    long hash_value;
    for (auto event : events) {
        if (event[0] == "setPassword") {
            password = event[1];
            hash_value = hash_string(password);
        } else {
            results.push_back(authorize(hash_value, stol(event[1])));
        }
    }
    return results;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string events_rows_temp;
    getline(cin, events_rows_temp);

    int events_rows = stoi(ltrim(rtrim(events_rows_temp)));

    string events_columns_temp;
    getline(cin, events_columns_temp);

    int events_columns = stoi(ltrim(rtrim(events_columns_temp)));

    vector<vector<string>> events(events_rows);

    for (int i = 0; i < events_rows; i++) {
        events[i].resize(events_columns);

        string events_row_temp_temp;

        getline(cin, events_row_temp_temp);

        vector<string> events_row_temp = split(rtrim(events_row_temp_temp));

        for (int j = 0; j < events_columns; j++) {
            string events_row_item = events_row_temp[j];

            events[i][j] = events_row_item;
        }
    }

    vector<int> result = authEvents(events);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) { fout << "\n"; }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

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
