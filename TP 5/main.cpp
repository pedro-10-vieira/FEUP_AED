#include "gtest/gtest.h"
#include "benchmark/benchmark.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    benchmark::Initialize(&argc, argv);
    std::cout << "AED 2023/2024 - Recitation 5" << std::endl;
    int res = RUN_ALL_TESTS();

    //NOTE: remove comments from respective BENCHMARKs at the end of the 'tests.cpp' file to run complexity analysis
    benchmark::RunSpecifiedBenchmarks();
    return res;
}