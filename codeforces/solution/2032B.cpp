#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

typedef std::vector<uint32_t> result;
typedef std::vector<result> resluts;

// get left on [left, ..., k, ..., right]
uint32_t get_left(const uint32_t n, const uint32_t k, const uint32_t length) {
    // printf("test: n: %u, k: %u, length: %u\n", n, k, length);

    // Check split
    const uint32_t split = (n - length) % 2;
    if (0 == split && k > length / 2) {
        // can split 3 subarrays
        const uint32_t left = k - length / 2;
        const uint32_t right = k + length / 2;

        // [1, ..., left - 1], [left, ..., k, ..., right], [right + 1, ..., n]
        // [left, ..., k, ..., right]
        if ((left <= k <= right && left > 1 && right < n) ||
            (left == 1 && right == n)) {
            // printf("success: left: %u\n", left);
            return left;
        }
    }

    if (1 == length) {
        // Failure
        return 0;
    }

    return get_left(n, k, length - 2);
}

uint32_t get_m(const uint32_t left1, const uint32_t right1,
               const uint32_t left2, const uint32_t right2, uint32_t length1,
               int32_t length2) {
    const uint32_t size1 = right1 - left1 + 1;
    const uint32_t size2 = right2 - left2 + 1;
    const uint32_t split1 = size1 % length1;
    const uint32_t split2 = size2 % length2;
    const uint32_t odd1 = size1 / length1;
    const uint32_t odd2 = size2 / length2;
    // printf("test: %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u\n", left1,
    //        right1, left2, right2, length1, length2, size1, size2, split1,
    //        split2, odd1, odd2);
    if (0 == split1 && 0 == split2 && odd1 == odd2) {
        // Success
        return odd1;
    }

    if (1 == length1 || 1 == length2) {
        // Failure
        return 0;
    }

    return get_m(left1, right1, left2, right2, length1 - 2, length2 - 2);
}

result test() {
    result ret;

    // Read N and K
    uint32_t N = 0;
    uint32_t K = 0;
    std::cin >> N >> K;

    // Choose an odd positive integer M and to split Array[n] into M
    // Subarrays(b1, b2, ... , bm) Array[N] And Median(Median(b1),
    // Median(b2),..., Median(bm) = K

    // Default length is N, is the length of median subarray of m subarrays.
    uint32_t Left = get_left(N, K, N);
    if (0 == Left) {
        return {};
    }

    uint32_t m = 0;
    uint32_t value = 1;
    uint32_t right = 2 * K - Left + 1;
    if (Left > 1) {
        // [1, ..., left - 1], [left, ..., k, ..., right], [right + 1, ..., n]
        //
        // split [1, ..., left - 1]
        value = 1;
        m = get_m(1, Left - 1, right, N, Left - 1, N - right + 1);
        for (auto i = 0; i < m; ++i) {
            ret.push_back(value);
            value = value + Left / m * 2;
        }

        // [left, ..., k, ..., right]
        ret.push_back(Left);

        // split [right + 1, ..., n]
        value = 2 * K - Left + 1;
        for (auto i = 0; i < m; ++i) {
            ret.push_back(value);
            value = value + (N - value + 1) / m * 2;
        }
    } else {
        // Left == 1
        // [left, ..., k, ..., right]
        ret.push_back(Left);
    }

    return ret;
}

void print_resluts(const resluts &rets) {
    for (auto &ret : rets) {
        if (ret.empty()) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << ret.size() << std::endl;
            for (auto &left : ret) {
                std::cout << left << " ";
            }
            std::cout << std::endl;
        }
    }
}

int tests() {
    // Read lines.
    size_t lines = 0;
    std::cin >> lines;

    // Allocate a vector of result.
    resluts rets;

    // Read parameters.
    for (auto i = 0; i < lines; ++i) {
        // Exec median
        rets.push_back(test());
    }

    // Print resluts.
    print_resluts(rets);
    return 0;
}

int main(int argc, char *argv[]) { return tests(); }
