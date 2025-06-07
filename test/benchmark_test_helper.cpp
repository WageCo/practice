#include "helper.h"
#include <benchmark/benchmark.h>

static void BM_Base_add(benchmark::State &state)
{
    int a = 1;
    int b = 1;
    int sum = 0;
    for (auto _ : state)
    {
        sum = a + b;
    }
}

static void BM_Helper_add(benchmark::State &state)
{
    int a = 1;
    int b = 1;
    int sum = 0;
    for (auto _ : state)
    {
        sum = helper::add(a, b);
    }
}

// Register the function as a benchmark
BENCHMARK(BM_Base_add);
BENCHMARK(BM_Helper_add);

// Run the benchmark
BENCHMARK_MAIN();
