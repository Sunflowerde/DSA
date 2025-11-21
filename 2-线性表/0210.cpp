#include <iostream>
#include <vector>
#include <string>

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool visited[26] = {false};

int dfs(std::vector<std::string>& matrix, int row, int col, int rows, int cols) {
    int sub_step = 0;
    int char_index = matrix[row][col] - 'A';
    visited[char_index] = true;
    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            int next_char_index = matrix[nr][nc] - 'A';
            if (!visited[next_char_index]) {
                int steps = dfs(matrix, nr, nc, rows, cols);
                if (steps > sub_step) {
                    sub_step = steps;
                }
            }
        }
    }
    visited[char_index] = false;
    return 1 + sub_step;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    std::vector<std::string> matrix(rows);
    for (int i = 0; i < rows; ++i) {
        std::cin >> matrix[i];
    }
    int max_steps = dfs(matrix, 0, 0, rows, cols);
    std::cout << max_steps << std::endl;
    return 0;
}