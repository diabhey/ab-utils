#pragma once
/**
*
* @file: PgnValidator.h
* @brief Validates the pgn    
*
*/

/*! Headers */
#include <string>
#include "DataTypes.h"

namespace PgnLib
{
/**
* @brief
* Validates the pgn of the game
*
* Detailed description of class.
*	
*/
class PgnValidator
{
public:
  /**
  * @brief	Constructs the PgnValidator instance.
  *
  * @param	Pointer to PgnMoveMaps
  */
  PgnValidator(PgnMoveMaps *data);

  /**
  * @brief	Destroys the PgnValidator instance.
  *
  */
  ~PgnValidator();

  /**
  * @brief Validates the contents of the pgn file.
  *
  * @return void
  */
  void PgnValidate() const;

  /**
  * @brief	Returns the Validated PgnMoveMaps
  *
  * @return	Pointer to the PgnMoveMaps
  */
  PgnMoveMaps *GetValidatedMoveMaps();

private:
  /**
  * @brief Checks the validity of the pgn
  *
  * @param	const string reference to the pgn string
  *
  * @return bool
  */
  Misc::Validity Validate(const std::string &pgn) const;

  std::unique_ptr<PgnMoveMaps> mValidateData;
};
}
