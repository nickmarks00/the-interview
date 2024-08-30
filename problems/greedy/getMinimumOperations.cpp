
#include <iostream>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Helper function to print vectors (used in error messages)
string vectorToString(const std::vector<int> &vec) {
    std::ostringstream oss;
    oss << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i < vec.size() - 1) { oss << ", "; }
    }
    oss << " }";
    return oss.str();
}

void queueToString(priority_queue<int> q) {
    cout << "Queue contents: ";
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

// Template function to run tests
template <typename F>
void runTests(const std::vector<vector<int>> &executionTimes,
              const vector<vector<int>> &xyPairs,
              const std::vector<int> &expectedOutputs, F func) {
    // Ensure the input and expected output vectors have the same size
    if (executionTimes.size() != expectedOutputs.size()) {
        throw std::invalid_argument(
            "Input and expected output vectors must have the same size.");
    }

    for (size_t i = 0; i < executionTimes.size(); ++i) {
        // Apply the function to the current input
        int result = func(executionTimes[i], xyPairs[i][0], xyPairs[i][1]);

        // Check if the result matches the expected output
        if (result == expectedOutputs[i]) {
            std::cout << "Test " << i + 1 << " passed.\n";
        } else {
            // If it doesn't match, raise a runtime error with detailed
            // information
            std::ostringstream errorMsg;
            errorMsg << "\nTest " << i + 1 << " failed.\n"
                     << "Input: " << vectorToString(executionTimes[i])
                     << " x: " << xyPairs[i][0] << " y: " << xyPairs[i][1]
                     << "\n"
                     << "Output: " << result << "\n"
                     << "Expected: " << expectedOutputs[i] << "\n";
            throw std::runtime_error(errorMsg.str());
        }
    }
}

int getMinimumOperations(const vector<int> &executionTime, int x, int y) {

    priority_queue<int> queue;

    for (int num : executionTime) { queue.push(num); }

    int operations = 0;
    int cumulativeY = 0;

    while (!queue.empty()) {
        int maxValue = queue.top();
        queue.pop();

        if (maxValue - cumulativeY <= 0) { break; }

        maxValue -= (cumulativeY + x);
        cumulativeY += y;

        operations++;

        if (maxValue > 0) { queue.push(maxValue + cumulativeY); }
    }

    return operations;
}

int main() {

    vector<vector<int>> executionTimes = {
        {3, 4, 1, 7, 6}, {3, 3, 6, 3, 9}, {2, 3, 5}};
    vector<vector<int>> xyPairs = {{4, 2}, {3, 2}, {3, 1}};
    vector<int> answers = {3, 3, 3};

    try {
        runTests(executionTimes, xyPairs, answers, getMinimumOperations);
        size_t testCases = executionTimes.size();
        cout << "Passed: " << testCases << "/" << testCases << " (100%)"
             << endl;
    } catch (const exception &e) { cerr << e.what(); }

    return 0;
}
