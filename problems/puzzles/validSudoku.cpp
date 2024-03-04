#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<string>> &board) {
    map<string, int> seen;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != ".") {
          if (seen["r-" + to_string(i) + board[i][j]] > 0) {
            return false;
          }
          if (seen["c-" + to_string(j) + board[i][j]] > 0) {
            return false;
          }
          if (seen["g-" + to_string(i / 3) + to_string(j / 3) + board[i][j]] >
              0) {
            return false;
          }
          seen["r-" + to_string(i) + board[i][j]] = 1;
          seen["c-" + to_string(j) + board[i][j]] = 1;
          seen["g-" + to_string(i / 3) + to_string(j / 3) + board[i][j]] = 1;
        }
      }
    }
    return true;
  }
};

int main() {
  vector<vector<string>> b1 = {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                               {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                               {".", "9", "8", ".", ".", ".", ".", "6", "."},
                               {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                               {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                               {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                               {".", "6", ".", ".", ".", ".", "2", "8", "."},
                               {".", ".", ".", "4", "1", "9", ".", ".", "5"},

                               {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
  vector<vector<string>> b2 = {{"8", "3", ".", ".", "7", ".", ".", ".", "."},
                               {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                               {".", "9", "8", ".", ".", ".", ".", "6", "."},
                               {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                               {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                               {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                               {".", "6", ".", ".", ".", ".", "2", "8", "."},
                               {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                               {".", ".", ".", ".", "8", ".", ".", "7", "9"}};

  Solution *sol = new Solution();
  cout << "Expected true, found " << sol->isValidSudoku(b1) << endl;
  cout << "Expected false, found " << sol->isValidSudoku(b2) << endl;
}
