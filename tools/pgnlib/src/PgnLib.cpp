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
#include <fstream>
#include "PgnDisplay.h"
#include "PgnExtractor.h"
#include "PgnValidator.h"

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: ./PgnLib <pgn file path>" << std::endl;
      return EXIT_FAILURE;
    }

    std::ifstream istr(argv[1]);
    PgnLib::PgnExtractor extract(istr);
    PgnLib::PgnValidator validate(extract.GetMoveMaps());
    PgnLib::PgnDisplay display(validate.GetValidatedMoveMaps());

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
