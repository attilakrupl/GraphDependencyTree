/*!
 * \file      GraphDependencyTreeTest.cpp
 * \author    attila.krupl
 * \date      2021/02/25
 */

#include "stdafx.h"

using namespace nTests;

int GraphDependencyTreeTest::InitialTestCase()
{
    try
    {
        nGraph::Graph lGraph;

        lGraph.AddEdge( 'a', 'g' );
        lGraph.AddEdge( 'g', 'h' );
        lGraph.AddEdge( 'g', 'i' );
        lGraph.AddEdge( 'b', 'c' );
        lGraph.AddEdge( 'b', 'd' );
        lGraph.AddEdge( 'c', 'e' );
        lGraph.AddEdge( 'd', 'e' );
        lGraph.AddEdge( 'h', 'j' );
        lGraph.AddEdge( 'i', 'j' );
        lGraph.AddEdge( 'e', 'f' );
        lGraph.AddEdge( 'j', 'f' );

        lGraph.PrintDependencyTree();
    }
    catch( const std::runtime_error& aException )
    {
        std::cout << aException.what() << std::endl;
        return -1;
    }
    catch( ... )
    {
        std::cout << "Unexpected error occurred" << std::endl;
        return -2;
    }

    return 0;
}

int GraphDependencyTreeTest::CyclicGraphFailingTestCase()
{
    try
    {
        nGraph::Graph lGraph;

        lGraph.AddEdge( 'a', 'g' );
        lGraph.AddEdge( 'g', 'h' );
        lGraph.AddEdge( 'h', 'a' );

        lGraph.PrintDependencyTree();
    }
    catch( const std::runtime_error& aException )
    {
        return 0;
    }
    catch( ... )
    {
        std::cout << "Unexpected error occurred" << std::endl;
        return -2;
    }

    std::cout << "Test result is false positive" << std::endl;
    return -3;
}

int GraphDependencyTreeTest::InvalidNodeIDTestCase()
{
    try
    {
        nGraph::Graph lGraph;

        lGraph.AddEdge( 'A', 'g' );
    }
    catch( const std::runtime_error& aException )
    {
        return 0;
    }
    catch( ... )
    {
        std::cout << "Unexpected error occurred" << std::endl;
        return -2;
    }

    std::cout << "Test result is false positive" << std::endl;
    return -3;
}

int GraphDependencyTreeTest::ComplexGraphTestCase()
{
    try
    {
        nGraph::Graph lGraph;

        lGraph.AddEdge( 'a', 'e' );
        lGraph.AddEdge( 'b', 'e' );
        lGraph.AddEdge( 'e', 'h' );
        lGraph.AddEdge( 'h', 'i' );
        lGraph.AddEdge( 'e', 'f' );
        lGraph.AddEdge( 'c', 'f' );
        lGraph.AddEdge( 'f', 'g' );
        lGraph.AddEdge( 'd', 'g' );
        lGraph.AddEdge( 'g', 'h' );
        lGraph.AddEdge( 'n', 'm' );
        lGraph.AddEdge( 'm', 'l' );
        lGraph.AddEdge( 'l', 'k' );
        lGraph.AddEdge( 'k', 'j' );
        lGraph.AddEdge( 'j', 'i' );

        lGraph.PrintDependencyTree();
    }
    catch( const std::runtime_error& aException )
    {
        std::cout << aException.what() << std::endl;
        return -1;
    }
    catch( ... )
    {
        std::cout << "Unexpected error occurred" << std::endl;
        return -2;
    }

    return 0;
}
