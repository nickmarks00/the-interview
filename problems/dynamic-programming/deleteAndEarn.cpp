/*
* DELETE AND EARN
* FROM: LeetCode
* NUMBER: 740
* DIFFICULTY: Medium
* LANGUAGE: C++
* Description
    You are given an integer array nums. You want to maximize the number of
points you get by performing the following operation any number of times:

    Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must
delete every element equal to nums[i] - 1 and every element equal to nums[i]
+ 1. Return the maximum number of points you can earn by applying the above
operation some number of times.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {

        vector<int> totals(10001, 0);

        for (auto num : nums) { totals[num] += num; }

        int prevMax = 0;
        int currentMax = totals[0];

        for (unsigned long i = 1; i < totals.size(); i++) {
            int tempMax = max(currentMax, prevMax + totals[i]);
            prevMax = currentMax;
            currentMax = tempMax;
        }

        return currentMax;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> inputs = {{3, 4, 2}, {2, 2, 3, 3, 3, 4}};
    vector<int> outputs = {6, 9};

    for (unsigned long i = 0; i < inputs.size(); i++) {
        cout << "Testing: " << i << " | Expected: " << outputs[i]
             << " | Received: " << solution.deleteAndEarn(inputs[i]) << endl;
    }
}
