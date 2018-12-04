#include <iostream>
#include <cstring>

long long cache[91][2];

long long solution(int n, int x) {
    if (cache[n][x] == -1) {
        long long ret = solution(n - 1, 0);
        if (x == 0) {
            ret += solution(n - 1, 1);
        }
        cache[n][x] = ret;
    }

    return cache[n][x];
}

int main() {
    memset(cache, -1, sizeof(cache));

    cache[1][0] = 0;
    cache[1][1] = 1;

    int n;

    std::cin >> n;

    std::cout << solution(n, 0) + solution(n, 1);
    return 0;
}