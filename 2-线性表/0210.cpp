#include <iostream>
#include <vector>
#include <string>

int search(std::vector<std::string>& matrix, int row, int col, int rows, int cols) {
    int count = 0;
    char c = matrix[row][col];
    if (row - 1 >= 0 && c == matrix[row - 1][col]) {
        ++count;
    }
    if (row + 1 < rows && c == matrix[row + 1][col]) {
        ++count;
    }
    if (col - 1 >= 0 && c == matrix[row][col - 1]) {
        ++count;
    }
    if (col + 1 < cols && c == matrix[row][col + 1]) {
        ++count;
    }
    return count;
}

int main() {
    int rows, cols;
    int count = 0;
    std::cin >> rows >> cols;
    std::vector<std::string> matrix(rows);
    for (int i = 0; i < rows; ++i) {
        std::cin >> matrix[i];
    }
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            count += search(matrix, row, col, rows, cols);
        }
    }
    return count;
}