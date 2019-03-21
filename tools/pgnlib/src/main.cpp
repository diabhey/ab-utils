/**
 * @file main.cpp
 * @author bigillu
 * @brief Entry point into the PgnLib
 * @version 0.1
 * @date 2019-03-21
 *
 * @copyright Copyright (c) 2019
 *
 */

/*! Headers */
#include <fstream>
#include "PgnExtractor.h"
#include "PgnValidator.h"
#include "PgnDisplay.h"
#include "DataTypes.h"

/* Namespaces */
using namespace std;
using namespace PgnLib;

int main(int argc, char *argv[])
{
    if (!(argc > 1))
    {
        cerr << "Expected argument: Full path to the pgn file!" << endl;
        return Misc::ExitType::Failed;
    }

    ifstream istr(argv[1]);
    PgnExtractor extract(istr);
    PgnValidator validate(extract.GetMoveMaps());
    PgnDisplay display(validate.GetValidatedMoveMaps());

    return Misc::ExitType::Success;
}
