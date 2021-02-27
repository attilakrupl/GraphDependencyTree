/*!
 * \file   main.cpp
 * \author Attila Krüpl dr.
 * \date   27/02/2021
 */

#include "stdafx.h"

using namespace nTests;

int main( [[maybe_unused]] int    argc,
          [[maybe_unused]] char** argv )
{
    {
        const int lTestResult = GraphDependencyTreeTest::InitialTestCase();
        EVALUATE_TEST_RESULT( lTestResult, "InitialTestCase" );
    }

    {
        const int lTestResult = GraphDependencyTreeTest::CyclicGraphFailingTestCase();
        EVALUATE_TEST_RESULT( lTestResult, "CyclicGraphFailingTestCase" );
    }

    {
        const int lTestResult = GraphDependencyTreeTest::InvalidNodeIDTestCase();
        EVALUATE_TEST_RESULT( lTestResult, "InvalidNodeIDTestCase" );
    }

    {
        const int lTestResult = GraphDependencyTreeTest::ComplexGraphTestCase();
        EVALUATE_TEST_RESULT( lTestResult, "ComplexGraphTestCase" );
    }

    return 0;
}
