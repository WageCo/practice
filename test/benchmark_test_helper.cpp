#include "helper.h"
#include <benchmark/benchmark.h>

static void BM_Base_add(benchmark::State &state)
{
    auto add = [](int a, int b) { return a + b; };
    int sum = 0;
    for (auto _ : state)
    {
        sum = add(1, 1);
    }
}

static void BM_Helper_add(benchmark::State &state)
{
    int sum = 0;
    for (auto _ : state)
    {
        sum = helper::add(1, 1);
    }
}

// Register the function as a benchmark
BENCHMARK(BM_Base_add);
BENCHMARK(BM_Helper_add);

// Run the benchmark
BENCHMARK_MAIN();
