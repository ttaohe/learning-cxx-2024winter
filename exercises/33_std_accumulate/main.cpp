﻿#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    // int size =
    size_t num_elements = std::accumulate(shape, shape + 4, 1, std::multiplies<>());
    // 计算张量占用的字节数，假设 DataType 大小为 4 字节
    int size = static_cast<int>(num_elements * sizeof(DataType));
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
