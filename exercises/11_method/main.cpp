#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        // 如果请求的斐波那契数已经在缓存中，直接返回
        if (i < cached) {
            return cache[i];
        }

        // 初始化缓存的前两个值
        if (cached < 1) {
            cache[0] = 0;
            cached = 1;
        }
        if (cached < 2) {
            cache[1] = 1;
            cached = 2;
        }
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib{{0}, 0};
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
