/*
 * MAJORITY ELEMENT
 * FROM: LeetCode
 * NUMBER: 169
 * DIFFICULTY: Easy
 * LANGUAGE: C++
 * DESCRIPTION:
 * Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {

        // from
        // https://www.enjoyalgorithms.com/blog/find-the-majority-element-in-an-array

        int majority = 0;
        int count = 0;

        for (auto num : nums) {
            if (num == majority) {
                count++;
            } else if (count == 0) {
                majority = num;
            } else {
                count--;
            }
        }
        return majority;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> inputs = {{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}};
    vector<int> answers = {3, 2};

    for (unsigned long i = 0; i < inputs.size(); i++) {
        cout << "Test Case " << i << ": Expected: " << answers[i]
             << " | Got: " << solution.majorityElement(inputs[i]) << endl;
    }
}
