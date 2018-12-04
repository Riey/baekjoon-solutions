#include <iostream>
#include <cstring>

long long cache[101][10];

long long solution(int n, int x) {
    if (cache[n][x] == -1) {
        long long ret;
        if (x == 0) {
            ret = solution(n - 1, 1);
        } else if (x == 9) {
            ret = solution(n - 1, 8);
        } else {
            ret = solution(n - 1, x - 1) + solution(n - 1, x + 1);
        }

        cache[n][x] = ret % 1000000000;
    }

    return cache[n][x];
}

int main() {

    int n;

    std::cin >> n;


    memset(cache, -1, sizeof(cache));

    cache[1][0] = 0;

    for (int i = 1; i < 10; i++) {
        cache[1][i] = 1;
    }

    long long ret = 0;

    for (int i = 0; i < 10; i++) {
        ret += solution(n, i);
    }

    std::cout << ret % 1000000000;

    return 0;
}