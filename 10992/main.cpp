#include <iostream>
#include <memory>

int main() {
    std::ios::sync_with_stdio(false);

    size_t n;

    std::cin >> n;

    auto length = ((3 * n * n + n) >> 1);

    auto buffer = std::make_unique<char[]>(length);
    size_t cur = 0;

    // first line
    for (auto i = 1; i < n; i++) {
        buffer[cur++] = ' ';
    }
    buffer[cur++] = '*';
    buffer[cur++] = '\n';

    size_t to = n - 1;

    // 2 ~ n-1 line
    for (auto i = 1; i < to; i++) {
        for (auto j = to; j > i; j--) {
            buffer[cur++] = ' ';
        }
        buffer[cur++] = '*';

        auto temp = 2 * i - 1;
        for (auto j = 0; j < temp; j++) {
            buffer[cur++] = ' ';
        }

        buffer[cur++] = '*';
        buffer[cur++] = '\n';
    }

    if (n > 1) {
        auto l = 2 * n - 1;

        // last line
        for (int i = 0; i < l; i++) {
            buffer[cur++] = '*';
        }
    }

    buffer[cur++] = '\0';

    std::cout << buffer.get() << std::endl;

    return 0;
}