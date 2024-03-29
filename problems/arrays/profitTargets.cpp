/*
 * PROFIT TARGETS
 * FROM: Hackerrank
 * LANGUAGE: C++
 * Description:
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stockPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY stocksProfit
 *  2. LONG_INTEGER target
 */

int stockPairs(vector<int> stocksProfit, long target) {

    sort(stocksProfit.begin(), stocksProfit.end());

    int n = stocksProfit.size();
    int pairs = 0;

    int i = 0;
    int j = n - 1;

    while (stocksProfit[j] > target) { j--; }

    while (i != j) {
        if (stocksProfit[i] + stocksProfit[j] > target) {
            j--;
        } else if (stocksProfit[i] + stocksProfit[j] < target) {
            i++;
        } else {
            // pair found
            pairs++;
            i++;
            while (i < j && stocksProfit[i] == stocksProfit[i - 1]) { i++; }
            while (i < j && stocksProfit[j] == stocksProfit[j - 1]) { j--; }
        }
    }

    return pairs;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string stocksProfit_count_temp;
    getline(cin, stocksProfit_count_temp);

    int stocksProfit_count = stoi(ltrim(rtrim(stocksProfit_count_temp)));

    vector<int> stocksProfit(stocksProfit_count);

    for (int i = 0; i < stocksProfit_count; i++) {
        string stocksProfit_item_temp;
        getline(cin, stocksProfit_item_temp);

        int stocksProfit_item = stoi(ltrim(rtrim(stocksProfit_item_temp)));

        stocksProfit[i] = stocksProfit_item;
    }

    string target_temp;
    getline(cin, target_temp);

    long target = stol(ltrim(rtrim(target_temp)));

    int result = stockPairs(stocksProfit, target);

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
