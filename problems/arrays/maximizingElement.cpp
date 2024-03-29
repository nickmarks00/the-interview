/*
 * MAXIMIZING ELEMENT WITH CONSTRAINTS
 * FROM: Hackerrank
 * LANGUAGE: C++
 * Description:
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxElement' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER maxSum
 *  3. INTEGER k
 */
int sum(long x, int cnt) {
    if (x >= cnt) { return (x + x - cnt + 1) * cnt / 2; }
    return (x + 1) * x / 2 + cnt - x;
}

int maxElement(int n, int maxSum, int k) {

    int l = 1;
    int r = maxSum;
    int mid;

    while (l < r) {
        mid = (l + r + 1) >> 1;

        if (sum(mid - 1, k) + sum(mid, n - k - 1) + mid <= maxSum) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string maxSum_temp;
    getline(cin, maxSum_temp);

    int maxSum = stoi(ltrim(rtrim(maxSum_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = maxElement(n, maxSum, k);

    fout << result << "\n";

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
