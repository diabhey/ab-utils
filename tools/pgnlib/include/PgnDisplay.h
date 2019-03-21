#pragma once
/**
*
* @file: PgnDisplay.h
* @brief Displays the game moves
*
*/

/*! Headers */
#include "DataTypes.h"

namespace PgnLib
{
/**
* @brief
* Displays the extracted the pgn move maps
*
* Detailed description of class.
*	
*/
class PgnDisplay
{
public:
  /**
  * @brief	Constructor that takes a parameter.
  *
  * @param	parameter	Parameter Description.
  */
  PgnDisplay(PgnMoveMaps* data);

  /**
  * @brief	Destructor that destroys the necessary.
  *
  */
  ~PgnDisplay();

  /**
  * @brief	Print the move maps of all the games 
  * in the pgn file. 
  * 
  * @return void
  */
  void PrintGameMaps() const;

private:
  std::unique_ptr<PgnMoveMaps> mDisplayData;
};
}