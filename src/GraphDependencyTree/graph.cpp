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

void Graph::CalculateDepths( const std::list<char>& aInitialIndependents )
{
    std::pair<int, std::queue<char>> lStackDescriptor;
    int                              lCurrentDepthValue = 1;

    for ( const char& lNode : aInitialIndependents )
    {
        lStackDescriptor.second.push( lNode );
        ++lStackDescriptor.first;
    }

    CalculateDepthsBFS( lStackDescriptor, ++lCurrentDepthValue );
}

void Graph::CalculateDepthsBFS( std::pair<int, std::queue<char>>& aStackDescriptor,
                                const int                         aDepthValue )
{
    if ( aStackDescriptor.first == 0 )
    {
        return;
    }

    int lNewStackSizeAddition    = 0;
    int lInitialCurrentStackSize = aStackDescriptor.first;

    for ( int i = 0; i < lInitialCurrentStackSize; ++i )
    {
        const char lCurrentNode = aStackDescriptor.second.front();
        aStackDescriptor.second.pop();
        --aStackDescriptor.first;

        for ( const char lNode : mAdjacencyMap[ lCurrentNode ] )
        {
            aStackDescriptor.second.push( lNode );
            mDepthMap[ lNode ] = mDepthMap[ lNode ] < aDepthValue
                                 ? aDepthValue
                                 : mDepthMap[ lNode ];
            ++lNewStackSizeAddition;
        }
    }

    aStackDescriptor.first += lNewStackSizeAddition;

    return CalculateDepthsBFS( aStackDescriptor, aDepthValue + 1 );
}

void Graph::FindIndependentNodes( std::list<char>& aIndependents )
{
    for ( const auto& [ lKey, lValue ] : mDepthMap )
    {
        if ( lValue == 1 )
        {
            aIndependents.push_back( lKey );
        }
    }
}

void Graph::CreateDepthTree( std::map<int, std::list<char>>& aDepthTree )
{
    for ( const auto& [ lKey, lValue ] : mDepthMap )
    {
        aDepthTree[ lValue ].push_back( lKey );
    }
}

void Graph::DoPrint( const std::map<int, std::list<char>>& aDepthTree )
{
    std::cout << "Depth\t\t" << "Nodes" << std::endl;

    for ( const auto& [ lDepth, lList ] : aDepthTree )
    {
        std::cout << lDepth << "\t\t";

        for ( const char& lNode : lList )
        {
            std::cout << lNode << " ";
        }

        std::cout << std::endl;
    }
}

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

    FindIndependentNodes( lIndependents );

    if ( lIndependents.empty() )
    {
        throw std::runtime_error( "No independent nodes found. Graph either has got no nodes, or graph is cyclic." );
    }

    CalculateDepths( lIndependents );

    std::map<int, std::list<char>> lDepthTree;

    CreateDepthTree( lDepthTree );

    DoPrint( lDepthTree );
}
