#include <iostream>
#include <memory>

int main() {
    std::ios::sync_with_stdio(false);

    size_t n;

    std::cin >> n;

    size_t length = ((3 * n * n + n) >> 1) + 1;

    auto buffer = std::make_unique<char[]>(length);
    size_t cur = 0;

    // 1 ~ n line
    for (auto i = 1; i <= n; i++) {
        for (auto j = n - 1; j >= i; j--) {
            buffer[cur++] = ' ';
        }

        auto temp = i * 2 - 1;

        for (auto j = 0; j < temp; j++) {
            if (j % 2 == 0) {
                buffer[cur++] = '*';
            } else {
                buffer[cur++] = ' ';
            }
        }

        buffer[cur++] = '\n';
    }

    buffer[cur] = '\0';

    std::cout << buffer.get() << std::endl;

    return 0;
}