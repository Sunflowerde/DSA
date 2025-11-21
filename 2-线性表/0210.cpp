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
                int next_step = dfs(matrix, nr, nc, rows, cols);
                if (next_step > sub_step) {
                    sub_step = next_step;
                }
            }
        }
    }
    visited[char_index] = false;
    return 1 + sub_step; 
}

int main() {
    int rows, cols;
    int max_steps = 0;
    std::cin >> rows >> cols;
    std::vector<std::string> matrix(rows);
    for (int i = 0; i < rows; ++i) {
        std::cin >> matrix[i];
    }
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int steps = dfs(matrix, row, col, rows, cols);
            if (steps > max_steps) {
                max_steps = steps;
            }
        }
    }
    std::cout << max_steps << std::endl;
    return 0;
}