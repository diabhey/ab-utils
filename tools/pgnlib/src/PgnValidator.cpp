/**
 * @file PgnValidator.cpp
 * @author bigillu
 * @brief Pgn Validator
 * @version 0.1
 * @date 2019-03-21
 *
 * @copyright Copyright (c) 2019
 *
 */

/*! Headers */
#include "PgnValidator.h"
#include <regex>
#include <string>
#include <type_traits>

PgnLib::PgnValidator::PgnValidator(PgnMoveMaps *data)
    : mValidateData(std::move(data)) {
  PgnValidate();
}

PgnLib::PgnValidator::~PgnValidator() { mValidateData.reset(); }

void PgnLib::PgnValidator::PgnValidate() const {
  auto gameCount = 1;
  for (const auto &itx : *mValidateData) {
    std::cout << "****** Validating Game: " << gameCount << " ******"
              << std::endl;

    for (const auto &ity : itx) {
      std::cout << " Move --> [ " << ity.first << ", "
                << Validate(ity.second.first) << " : "
                << Validate(ity.second.second) << " ] " << std::endl;
    }
    std::cout << '\n';
    gameCount++;
  }
}

bool PgnLib::PgnValidator::Validate(const std::string &pgn) const {
  std::smatch mSmatch;
  // Simple regular expression matching and extraction
  std::regex game_notation(
      "([RNBKQP]?)([a-h]|[1-8]?)([x]?)([a-h])"
      "([1-8])([+|#]?)|(O-O-O)|(O-O)");

  return (std::regex_match(pgn, mSmatch, game_notation)) ? true : false;
}

PgnLib::PgnMoveMaps *PgnLib::PgnValidator::GetValidatedMoveMaps() {
  return mValidateData.release();
}