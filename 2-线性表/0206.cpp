#include <iostream>
#include <vector>
#define mod 65536;

bool check(int num, int i) {
    return (num >> i) & 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        char OP;
        std::cin >> OP;
        if (OP == 'Q') {
            int i;
            int count = 0;
            std::cin >> i;
            for (int x : v) {
                if (check(x, i)) {
                    ++count;
                }
            }
            std::cout << count << std::endl;
        } else if (OP == 'C') {
            int d;
            std::cin >> d;
            for (int j = 0; j < n; ++j) {
                v[j] = (v[j] + d) % mod;
            }
        }
    }
    return 0;
}