/*!
 * \file      main.cpp
 * \author    attila.krupl
 * \date      2021/02/24
 */

#include "stdafx.h"

using namespace std;
using namespace nTests;

int main( [[maybe_unused]] int    argc,
          [[maybe_unused]] char** argv )
{
    const int lInitialTestCaseResult = GraphDependencyTreeTest::InitialTestCase();

    if ( lInitialTestCaseResult != 0 )
    {
        return lInitialTestCaseResult;
    }

    return 0;
}
