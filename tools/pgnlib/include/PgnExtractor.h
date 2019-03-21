#pragma once
/**
*
* @file: PgnExtractor.h
* @brief Extracts the game moves from the pgn file
*        and stores it in a vector of maps.   
*
*/

/*! Headers */
#include "DataTypes.h"

namespace PgnLib
{
/**
* @brief
* Extract the pgn file parsed
*
* Detailed description of class.
*	
*/
class PgnExtractor
{
public:
  /**
  * @brief	Constructor that takes a parameter.
  *
  * @param	parameter	Parameter Description.
  */
  PgnExtractor(std::ifstream &istreamReader);

  /**
  * @brief	Destructor that destroys the necessary.
  *
  */
  ~PgnExtractor();

  /**
  * @brief	Processes the contents of the pgn file.
  *
  * @param	std::ifstream&	Input File stream reader
  */
  void PgnFileParser(std::ifstream &istreamReader);

  /**
  * @brief	Get the vector of move maps
  * 
  * @return Pointer of type PgnMoveMaps
  */
  PgnMoveMaps *GetMoveMaps();

private:
  /**
  * @brief Checks the end game pgn detection
  * 
  * @return bool - true if it matches the end game detection
  */
  bool EndGameDetection(PgnFileSingleRead &singleRead) const;

  std::ifstream &mFileReader;
  PgnMoveMap mMoveMap;

protected:
  std::unique_ptr<PgnMoveMaps> mMoveMaps;
};
}
