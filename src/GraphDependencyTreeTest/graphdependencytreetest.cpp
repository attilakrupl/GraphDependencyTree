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
