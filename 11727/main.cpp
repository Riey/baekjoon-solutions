#include <iostream>
#include <cstring>

int cache[1001];

int solution(int n) {
    if (cache[n] == -1) {
        int ret = solution(n - 1);
        ret += solution(n - 2) * 2;
        cache[n] = ret % 10007;
    }

    return cache[n];
}

int main() {
    int n;
    memset(cache, -1, sizeof(cache));

    std::cin >> n;

    cache[1] = 1;
    cache[2] = 3;

    std::cout << solution(n);

    return 0;
}