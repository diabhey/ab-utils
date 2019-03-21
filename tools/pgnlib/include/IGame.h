#pragma once
/**
*
* @file: IGame.h
* @brief Game Interface Class 
*
*/

/*! Headers */
#include "IFeeder.h"
#include "IDisplay.h"

namespace Interface
{
/**
* @brief
* Abstract Base Class(Interface) for the game
*
*	
*/
class IGame
{
public:
  virtual ~IGame() = default;  // Make dtor virtual
  IGame(IGame &&) = default; // Support Moving
  IGame &operator=(IGame &&) = default;
  IGame(const IGame &) = default; // Support Copying
  IGame &operator=(const IGame &) = default;
  virtual void test() = 0;
};

}