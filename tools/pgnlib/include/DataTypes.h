#pragma once
/**
*
* @file: DataTypes.h
* @brief Stores the custom data types.   
*
*/

/*!Headers*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
#include <list>

namespace PgnLib
{
/*! Custom types */
using PgnFileSingleRead = std::istream_iterator<std::string>;
using PgnMoveMap = std::map<int, std::pair<std::string, std::string>>;
using PgnMoveMaps = std::vector<PgnMoveMap>;
}

namespace Misc
{
enum ExitType
{
    Success = 0,
    Failed = 1
};
enum Validity
{
    Invalid = false,
    Valid = true
};
}