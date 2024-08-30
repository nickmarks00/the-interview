/*
 * BAG OF TOKENS
 * FROM: LeetCode
 * NUMBER: 948
 * LANGUAGE: C++
 * Description: You start with an initial power of power, an initial score of 0,
and a bag of tokens given as an integer array tokens, where each tokens[i]
denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens.
In one move, you can play an unplayed token in one of the two ways (but not both
for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni,
losing tokens[i] power and gaining 1 score. Face-down: If your current score is
at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of
tokens.
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
  public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int score = 0;
        int maxScore = score;
        unsigned long l = 0;
        unsigned long r = tokens.size() - 1;
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

    for (unsigned long i = 0; i < tokenCases.size(); i++) {
        int result = s.bagOfTokensScore(tokenCases[i], powerCases[i]);
        if (result == solutions[i]) {
            printf("Test case %lu PASSED\n", i);
        } else {
            printf("Test case %lu FAILED\n", i);
        }
    }

    return 0;
}
