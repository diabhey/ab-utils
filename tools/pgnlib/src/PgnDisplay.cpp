/**
 * @file PgnDisplay.cpp
 * @author bigillu
 * @brief Displays the PGN game map
 * @version 0.1
 * @date 2019-03-21
 *
 * @copyright Copyright (c) 2019
 *
 */

/*! Headers */
#include "PgnDisplay.h"
#include "DataTypes.h"

/*! Namespaces */
using namespace PgnLib;

PgnDisplay::PgnDisplay(PgnMoveMaps *data) : mDisplayData(std::move(data))
{
    PrintGameMaps();
}

PgnDisplay::~PgnDisplay()
{
    mDisplayData.reset();
}

void PgnDisplay::PrintGameMaps() const
{
    auto gameCount = 1;
    for (const auto &itx : *mDisplayData)
    {
        std::cout << "****** Printing Game: " << gameCount << " ******" << std::endl;
        for (const auto &ity : itx)
        {
            std::cout << "[ " << ity.first << ", " << ity.second.first << ": "
                      << ity.second.second << " ] " << std::endl;
        }
        std::cout << '\n';
        gameCount++;
    }
}