"""
COUNT KNIGHT STRINGS
FROM: TikTok LiveNet Backend R&D Engineer Final Interview
LANGUAGE: Python

Consider a 4x4 grid containing characters 'a' to 'p'. Given a starting location
(i, j) on the grid and a password length L, calculate the number of possible
passwords that can be generated of length L.

You can only move between letters in the way a chess knight does - two squares
vertically/horizontally, then one square horizontall/vertically.
"""


def count_knight_strings(start_i, start_j, L):
    # Define the knight moves
    moves = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

    # Initialize DP table
    dp = [[[0 for _ in range(L + 1)] for _ in range(4)] for _ in range(4)]

    # Base case: length 1
    for x in range(4):
        for y in range(4):
            dp[x][y][1] = 1

    # Fill DP table for lengths from 2 to L
    for l in range(2, L + 1):
        for x in range(4):
            for y in range(4):
                dp[x][y][l] = 0
                for dx, dy in moves:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < 4 and 0 <= ny < 4:
                        dp[x][y][l] += dp[nx][ny][l - 1]

    # Result is the number of strings of length L starting from (start_i, start_j)
    return dp[start_i][start_j][L]


if __name__ == "__main__":
    tests = [(0, 0, 1), (0, 0, 2), (0, 0, 3)]
    answers = [1, 2, 8]

    for test, answer in zip(tests, answers):
        try:
            i, j, L = test
            res = count_knight_strings(i, j, L)
            assert res == answer
        except AssertionError as e:
            print(f"Failed test {test}: {e}")
