/**
 * @file PgnLib.cpp
 * @author bigillu
 * @brief Entry point into PgnLib
 * @version 0.1
 * @date 2019-03-21
 *
 * @copyright Copyright (c) 2019
 *
 */

/*! Headers */
#include <benchmark/benchmark.h>
#include <algorithm>
#include <fstream>
#include "PgnDisplay.h"
#include "PgnExtractor.h"
#include "PgnValidator.h"

using namespace benchmark;

static void BM_PgnLib(benchmark::State& state) {
  while (state.KeepRunning()) {
    std::ifstream istr("SingleGame.pgn");
    PgnLib::PgnExtractor extract(istr);
    PgnLib::PgnValidator validate(extract.GetMoveMaps());
    PgnLib::PgnDisplay display(validate.GetValidatedMoveMaps());
  }
}

BENCHMARK(BM_PgnLib)->Arg(1000);

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: ./PgnLib <pgn file path>" << std::endl;
      return EXIT_FAILURE;
    }
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
  }
  catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
