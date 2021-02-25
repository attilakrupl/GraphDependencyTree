/*!
 * \file      graph.cpp
 * \author    attila.krupl
 * \date      2021/02/25
 */

#include "stdafx.h"

using namespace nGraph;

const bool Graph::IsCyclic()
{
    std::map<char, bool> lVisited;
    std::map<char, bool> lRecursiveStack;

    for ( [[maybe_unused]] const auto& [ lKey, lValue ] : mAdjacencyMap )
    {
        lVisited[ lKey ]        = false;
        lRecursiveStack[ lKey ] = false;
    }

    for ( [[maybe_unused]] const auto& [ lKey, lValue ] : mAdjacencyMap )
    {
        if ( IsCyclicHelper( lKey, lVisited, lRecursiveStack ) )
        {
            return true;
        }
    }

    return false;
}

const bool Graph::IsCyclicHelper( const char            aNode,
                                  std::map<char, bool>& aVisited,
                                  std::map<char, bool>& aRecursiveStack )
{
    if ( aVisited[ aNode ] == false )
    {
        aVisited[ aNode ]        = true;
        aRecursiveStack[ aNode ] = true;

        std::list<char>::iterator lIterator;

        for ( lIterator = mAdjacencyMap[ aNode ].begin(); lIterator != mAdjacencyMap[ aNode ].end(); ++lIterator )
        {
            if ( !aVisited[ *lIterator ]
               && IsCyclicHelper( *lIterator, aVisited, aRecursiveStack ) )
            {
                return true;
            }
            else if ( aRecursiveStack[ *lIterator ] )
            {
                return true;
            }
        }
    }

    aRecursiveStack[ aNode ] = false;
    return false;
}

void Graph::CalculateDepths()
{}

void Graph::AddEdge( const char aFromNode,
                     const char aToNode )
{
    if ( ( ( aFromNode < 'a' )
         || ( aFromNode > 'z' ) )
       || ( ( aToNode < 'a' )
          || ( aToNode > 'z' ) ) )
    {
        throw std::runtime_error( "Invalid character provided as node ID." );
    }

    if ( mDepthMap.find( aFromNode ) == mDepthMap.cend() )
    {
        mDepthMap[ aFromNode ] = 1;
    }

    if ( ( mDepthMap.find( aToNode ) == mDepthMap.cend() )
       || ( mDepthMap.find( aToNode )->second == 1 ) )
    {
        mDepthMap[ aToNode ] = 2;
    }

    mAdjacencyMap[ aFromNode ].push_back( aToNode );
}

void Graph::PrintDependencyTree()
{
    const bool lIsCyclic = IsCyclic();

    if ( lIsCyclic )
    {
        throw std::runtime_error( "Directed Graph is cyclic. Please provide a Directed Acyclic Graph." );
    }

    std::list<char> lIndependents;

    for ( const auto& [ lKey, lValue ] : mDepthMap )
    {
        if ( lValue == 1 )
        {
            lIndependents.push_back( lKey );
        }
    }

    CalculateDepths();

    std::map<int, std::list<char>> lDepthTree;

    for ( const auto& [ lKey, lValue ] : mDepthMap )
    {
        lDepthTree[ lValue ].push_back( lKey );
    }

    std::cout << "Depth\t\t" << "Nodes" << std::endl;

    for ( const auto& [ lDepth, lList ] : lDepthTree )
    {
        std::cout << lDepth << "\t\t";

        for ( const char& lNode : lList )
        {
            std::cout << lNode << " ";
        }

        std::cout << std::endl;
    }
}
