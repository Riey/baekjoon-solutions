#include <iostream>
#include <cstring>

int cache[12];

int solution(int n) {
    if (cache[n] == -1) {
        int ret = solution(n - 1);
        ret += solution(n - 2);
        ret += solution(n - 3);
        cache[n] = ret;
    }

    return cache[n];
}

int main() {
    int t, n;

    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n;
        std::cout << solution(n) << std::endl;
    }

    return 0;
}