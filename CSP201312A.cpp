#include <iostream>
#include <vector>
#include <map>

int main() {
    int n;
    int count = 0;
    int ans = -1;
    std::cin >> n;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::map<int, int> map;
    for (int num : s) {
        ++map[num];
    }

    for (auto pair : map) {
        if (pair.second > count) {
            count = pair.second;
            ans = pair.first;
        }
    }

    std::cout << ans << std::endl;
}