#include <iostream>
#include <vector>

// https://codeforces.com/problemset/problem/2030/C
//

void test_case() {
    // Read integer n and string s
    size_t n = 0;
    std::string s = "";
    std::cin >> n;
    std::cin >> s;

    std::vector<bool> v;
    for (auto i = 0; i < s.size(); ++i) {
        v.push_back(s.at(i) == '1');
    }

    bool win = false;

    do {
        if (v[0] || v[s.size() - 1]) {
            win = true;
        }

        for (auto i = 1; i < s.size(); ++i) {
            if (v[i] && v[i - 1]) {
                win = true;
            }
        }
    } while (false);
    if (win) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto test_cases = 0;
    std::cin >> test_cases;

    for (auto i = 0; i < test_cases; ++i) {
        test_case();
    }

    return 0;
}
