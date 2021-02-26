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
    {
        const int lTestResult = GraphDependencyTreeTest::InitialTestCase();

        if ( lTestResult != 0 )
        {
            return lTestResult;
        }
    }

    {
        const int lTestResult = GraphDependencyTreeTest::CyclicGraphFailingTestCase();

        if ( lTestResult != 0 )
        {
            return lTestResult;
        }
    }

    {
        const int lTestResult = GraphDependencyTreeTest::InvalidNodeIDTestCase();

        if ( lTestResult != 0 )
        {
            return lTestResult;
        }
    }

    {
        const int lTestResult = GraphDependencyTreeTest::ComplexGraphTestCase();

        if ( lTestResult != 0 )
        {
            return lTestResult;
        }
    }

    return 0;
}
