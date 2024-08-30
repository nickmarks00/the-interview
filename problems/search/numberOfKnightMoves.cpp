/*
 * NUMBER OF MOVES
 * FROM: HackerRank (Andrea's 2023 SWE OA)
 * DIFFICULTY: Medium
 * Language: C++
 * DESCRIPTION:
 * Given an n x n chess board, a starting position A and a final position,
 * calculate the minimum number of moves required by a knight to move from A to
 * B
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cell {
    int x, y;
    int dist;
    cell() {}
    cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isInside(int x, int y, int N) {
    if (x >= 0 && x <= N - 1 && y >= 0 && y <= N - 1) { return true; }
    return false;
}

int minimumMoves(vector<int> &startPos, vector<int> &targetPos, int N) {

    vector<vector<int>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                 {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    queue<cell> q;

    q.push(cell(startPos[0], startPos[1], 0));
    cell t;
    int x, y;
    // vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    bool visit[N][N];

    memset(visit, false, sizeof(visit));
    visit[startPos[0]][startPos[1]] = true;

    while (!q.empty()) {

        t = q.front();
        q.pop();

        if (t.x == targetPos[0] && t.y == targetPos[1]) { return t.dist; }

        for (int i = 0; i < moves.size(); i++) {
            x = t.x + moves[i][0];
            y = t.y + moves[i][1];

            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dist + 1));
            }
        }
    }

    return -1;
}

int main() {

    vector<int> nValues = {9, 10, 6};
    vector<vector<int>> startPosValues = {{4, 4}, {0, 0}, {5, 1}};
    vector<vector<int>> endPosValues = {{4, 8}, {0, 2}, {0, 5}};
    vector<int> answerValues = {2, 2, 3};

    for (int i = 0; i < nValues.size(); ++i) {

        cout << "Test case " << i << ": Expected = " << answerValues[i]
             << " | Actual = "
             << minimumMoves(startPosValues[i], endPosValues[i], nValues[i])
             << endl;
    }

    return 0;
}
