/*!
 * \file      graph.cpp
 * \author    attila.krupl
 * \date      2021/02/25
 */

#include "stdafx.h"

using namespace nGraph;

void Graph::AddEdge( const char aFromNode,
                     const char aToNode )
{
    mFromNodes.insert( aFromNode );
    mToNodes.insert( aToNode );

    mAdjacencyMap[ aFromNode ].push_back( aToNode );
}

void Graph::PrintDependencyTree()
{
    std::cout << "Depth\t\t" << "Nodes" << std::endl;
}
