#include <iostream>
#include <string>
#include <ctype.h>

int main() {
    std::string ISBN;
    std::cin >> ISBN;
    int count = 1;
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        if (isdigit(ISBN[i])) {
            sum += (ISBN[i] - '0') * count;
            ++count;
        }
    }
    int judge = sum % 11;
    if (judge == 10) {
        if (ISBN[12] == 'X') {
            std::cout << "Right" << std::endl;
        } else {
            ISBN[12] = 'X';
            std::cout << ISBN << std::endl;
        }
    } else {
        if (judge == ISBN[12] - '0') {
            std::cout << "Right" << std::endl;
        } else {
            ISBN[12] = judge + '0';
            std::cout << ISBN << std::endl;
        }
    }
    return 0;
}