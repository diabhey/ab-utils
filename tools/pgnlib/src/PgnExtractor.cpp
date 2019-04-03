/**
 * @file PgnExtractor.cpp
 * @author bigillu
 * @brief Extracts the pgn file
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

/*! Headers */
#include "PgnExtractor.h"
#include "DataTypes.h"

/*! Namespaces */
using namespace PgnLib;

/*! Const data */
std::vector<std::string> EndGameNotation = {"0-1", "1/2-1/2", "1-0"};
const std::string findFirstMove = "1.";

PgnExtractor::PgnExtractor(std::ifstream &iRead)
    : mFileReader(iRead),
      mMoveMap(),
      mMoveMaps(std::make_unique<PgnMoveMaps>()) {
  if (not mFileReader.is_open()) {
    throw std::runtime_error("Failed to open the file \n");
  }
  PgnFileParser(mFileReader);
}

PgnExtractor::~PgnExtractor() { mFileReader.close(); }

PgnMoveMaps *PgnExtractor::GetMoveMaps() { return mMoveMaps.release(); }

void PgnExtractor::PgnFileParser(std::ifstream &iRead) {

  PgnFileSingleRead itr(iRead);
  PgnFileSingleRead eof;
  while (itr != eof) {
    if (!(*itr).find(findFirstMove)) {
      try {
        while (!EndGameDetection(itr)) {
          int moveCount = stoi(*itr);
          auto whiteMove = (*itr).substr((*itr).find(".") + 1);
          auto blackMove = std::next(itr, 1);
          // In certain scenario's the second player might choose
          // not to play. The move by the second player will not
          // be registered and the game will end either in a draw or a loss
          // player. This condition handles that particular scenario else
          // the parser will go nuts.
          if (EndGameDetection(blackMove)) {
            mMoveMap.emplace(moveCount, std::make_pair(whiteMove, ""));
            break;
          } else {
            mMoveMap.emplace(moveCount, std::make_pair(whiteMove, *blackMove));
          }
          itr++;
        }
      } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
      mMoveMaps->emplace_back(mMoveMap);
      mMoveMap.clear();
    }
    itr++;
  }
}

bool PgnExtractor::EndGameDetection(PgnFileSingleRead &itr) const {
  bool gameHasEnded = false;
  auto found =
      std::find_if(EndGameNotation.begin(), EndGameNotation.end(),
                   [&](const std::string &s) -> bool { return s == (*itr); });
  if (found != EndGameNotation.end()) {
    gameHasEnded = true;
  }
  return gameHasEnded;
}
