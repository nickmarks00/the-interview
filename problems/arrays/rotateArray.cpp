/*
 * ROTATE ARRAY
 * FROM: LeetCode
 * NUMBER: 189
 * DIFFICULTY: Medium
 * LANGUAGE: C++
 * DESCRIPTION:
 * Given an integer array nums, rotate the array to the right by k steps, where
 * k is non-negative.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

  private:
    void reverse(vector<int> &nums, int l, int r) {
        while (l < r) swap(nums[l++], nums[r--]);
    }
};

int main() {

    Solution solution;
    vector<vector<int>> inputs = {
        {1, 2, 3, 4, 5, 6, 7}, {-1, 100, 3, 99}, {1, 2}};
    vector<int> kValues = {3, 2, 2};
    vector<vector<int>> outputs = {
        {5, 6, 7, 1, 2, 3, 4}, {3, 99, -1, 100}, {1, 2}};

    for (unsigned long i = 0; i < inputs.size(); i++) {
        cout << "Test case " << i << ": k = " << kValues[i] << endl;
        cout << "Input array: ";
        for (auto num : inputs[i]) { cout << num << " "; }
        cout << endl << "Expected : ";
        for (auto num : outputs[i]) { cout << num << " "; }
        solution.rotate(inputs[i], kValues[i]);
        cout << endl << "Received: ";
        for (auto num : inputs[i]) { cout << num << " "; }
        cout << endl << endl;
    }

    return 0;
}
