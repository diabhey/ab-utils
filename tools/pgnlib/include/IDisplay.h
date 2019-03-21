#pragma once
/**
*
* @file: IDisplay.h
* @brief Output Interface Class 
*
*/

/*! Headers */

namespace Interface
{
/**
* @brief
* Abstract Base Class(Interface) for the output
*
*	
*/
class IDisplay
{
public:
  virtual ~IDisplay() = default;  // Make dtor virtual
  IDisplay(IDisplay &&) = default; // Support Moving
  IDisplay &operator=(IDisplay &&) = default;
  IDisplay(const IDisplay &) = default; // Support Copying
  IDisplay &operator=(const IDisplay &) = default;
  virtual void test() = 0;
};

}