#include <iostream>
#include <cstdlib>
#include <cstring>

int cache[1000001];

int solution(int x) {
    if (cache[x] == -1) {
        int ret = solution(x - 1);
        div_t temp;

        temp = div(x, 3);

        if (temp.rem == 0) {
            int div3 = solution(temp.quot);
            ret = ret > div3 ? div3 : ret;
        }

        temp = div(x, 2);

        if (temp.rem == 0) {
            int div2 = solution(temp.quot);
            ret = ret > div2 ? div2 : ret;
        }

        cache[x] = ret + 1;
    }

    return cache[x];
}

int main() {
    int x;

    memset(cache, -1, sizeof(cache));

    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;

    std::cin >> x;

    std::cout << solution(x);

    return 0;
}