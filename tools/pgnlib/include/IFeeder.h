#pragma once
/**
*
* @file: IFeeder.h
* @brief Input Interface Class 
*
*/

/*! Headers */

namespace Interface
{
/**
* @brief
* Abstract Base Class(Interface) for the input
*
*	
*/
class IFeeder
{
public:
  virtual ~IFeeder() = default;  // Make dtor virtual
  IFeeder(IFeeder &&) = default; // Support Moving
  IFeeder &operator=(IFeeder &&) = default;
  IFeeder(const IFeeder &) = default; // Support Copying
  IFeeder &operator=(const IFeeder &) = default;
  virtual void test() = 0;
};

}