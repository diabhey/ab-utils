/**************************************************************************/ /**
* @file: PgnExtractor.cpp 
* @author: Bigillu
* @version: 2.0
* @brief: Extracts the pgn file
******************************************************************************/

// TODO
// template functions
// overloaded stream operator to print the pgn or map...
// custom return types and error types

/*! Headers */
#include "PgnExtractor.h"
#include "DataTypes.h"

/*! Namespaces */
using namespace PgnLib;
using namespace Misc;

/*! Const data */
std::list<std::string> EndGameNotation = {"0-1", "1/2-1/2", "1-0"};

PgnExtractor::PgnExtractor(std::ifstream &iRead) : mFileReader(iRead),
                                                   mMoveMap(),
                                                   mMoveMaps(std::make_unique<PgnMoveMaps>())
{
    if (!iRead.good())
    {
        std::cerr << "FILE ERROR" << std::endl;
    }
    PgnFileParser(mFileReader);
}

PgnExtractor::~PgnExtractor()
{
    mFileReader.close();
}

PgnMoveMaps *PgnExtractor::GetMoveMaps()
{
    return mMoveMaps.release();
}

void PgnExtractor::PgnFileParser(std::ifstream &iRead)
{
    const std::string findFirstMove = "1.";
    PgnFileSingleRead itr(iRead);
    PgnFileSingleRead eof;
    while (itr != eof)
    {
        if (!(*itr).find(findFirstMove))
        {
            try
            {
                while (!EndGameDetection(itr))
                {
                    int moveCount = stoi(*itr);
                    auto whiteMove = (*itr).substr((*itr).find(".") + 1);
                    auto blackMove = std::next(itr, 1);
                    // In certain scenario's the second player might choose
                    // not to play. The move by the second player will not 
                    // be registered and the game will end either in a draw or a loss
                    // player. This condition handles that particular scenario else
                    // the parser will go nuts. 
                    if (EndGameDetection(blackMove))
                    {
                        mMoveMap.emplace(moveCount, std::make_pair(whiteMove, ""));
                        break;
                    }
                    else
                    {
                        mMoveMap.emplace(moveCount, std::make_pair(whiteMove, *blackMove));
                    }
                    itr++;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
            mMoveMaps->push_back(mMoveMap);
            mMoveMap.clear();
        }
        itr++;
    }
}

bool PgnExtractor::EndGameDetection(PgnFileSingleRead &itr) const
{
    bool gameHasEnded = false;
    auto found = std::find_if(EndGameNotation.begin(), EndGameNotation.end(),
                            [&](const std::string &s) -> bool {
                                return s == (*itr);
                            });
    if (found != EndGameNotation.end())
    {
        gameHasEnded = true;
    }
    return gameHasEnded;
}
