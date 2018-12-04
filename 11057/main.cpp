#include <iostream>
#include <cstring>

int cache[1001][10];

int solution(int n, int x) {

    if (cache[n][x] == -1) {
        if (x == 9) {
            cache[n][x] = 1;
        } else {
            int ret = 0;

            for (int i = x; i < 10; i++) {
                ret += solution(n - 1, i);
            }

            cache[n][x] = ret % 10007;
        }
    }

    return cache[n][x];
}

int main() {
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < 10; i++) {
        cache[1][i] = 1;
    }

    int n;

    std::cin >> n;

    int ret = 0;

    for (int i = 0; i < 10; i++) {
        ret += solution(n, i);
    }

    std::cout << ret % 10007;

    return 0;
}