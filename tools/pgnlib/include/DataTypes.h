#pragma once

/**
 * @file DataTypes.h
 * @author bigillu
 * @brief PgnLib data types.
 * @version 0.1
 * @date 2019-03-23
 *
 * @copyright Copyright (c) 2019
 *
 */

/*!Headers*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace PgnLib {
/*! Custom types */
using PgnFileSingleRead = std::istream_iterator<std::string>;
using PgnMoveMap = std::map<int, std::pair<std::string, std::string>>;
using PgnMoveMaps = std::vector<PgnMoveMap>;
}  // namespace PgnLib
