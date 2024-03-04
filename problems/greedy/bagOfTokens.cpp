#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
  public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int score = 0;
        int maxScore = score;
        int l = 0;
        int r = tokens.size() - 1;
        sort(begin(tokens), end(tokens));

        while (l <= r) {
            if (tokens[l] <= power) {
                power -= tokens[l];
                score++;
                l++;
            } else if (score > 0) {
                power += tokens[r];
                score--;
                r--;
            } else {
                l++;
            }

            if (score > maxScore) { maxScore = score; }
        }

        return maxScore;
    }
};

int main() {

    Solution s;

    vector<vector<int>> tokenCases = {{100}, {200, 100}, {100, 200, 300, 400}};
    vector<int> powerCases = {50, 150, 200};
    vector<int> solutions = {0, 1, 2};

    for (int i = 0; i < tokenCases.size(); i++) {
        int result = s.bagOfTokensScore(tokenCases[i], powerCases[i]);
        if (result == solutions[i]) {
            printf("Test case %d PASSED\n", i);
        } else {
            printf("Test case %d FAILED\n", i);
        }
    }

    return 0;
}
