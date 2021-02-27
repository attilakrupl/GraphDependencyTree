/*!
 * \file   graph.cpp
 * \author Attila Krüpl dr.
 * \date   27/02/2021
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
        if ( IsCyclicDFS( lKey, lVisited, lRecursiveStack ) )
        {
            return true;
        }
    }

    return false;
}

const bool Graph::IsCyclicDFS( const char            aNode,
                               std::map<char, bool>& aVisited,
                               std::map<char, bool>& aRecursiveStack )
{
    if ( aVisited[ aNode ] == false )
    {
        aVisited[ aNode ]        = true;
        aRecursiveStack[ aNode ] = true;

        for ( auto lIterator = mAdjacencyMap[ aNode ].cbegin(); lIterator != mAdjacencyMap[ aNode ].cend(); ++lIterator )
        {
            if ( !aVisited[ *lIterator ]
               && IsCyclicDFS( *lIterator, aVisited, aRecursiveStack ) )
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

void Graph::CalculateDepths( StackDescriptor& aInitialIndependents )
{
    const int lInitialDepthValue = 2;
    CalculateDepthsBFS( aInitialIndependents, lInitialDepthValue );
}

void Graph::CalculateDepthsBFS( StackDescriptor& aStackDescriptor,
                                const int        aDepthValue )
{
    if ( aStackDescriptor.first == 0 )
    {
        return;
    }

    int       lNewStackSizeAddition    = 0;
    const int lInitialCurrentStackSize = aStackDescriptor.first;

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

void Graph::FindIndependentNodes( StackDescriptor& aIndependents ) const
{
    for ( const auto& [ lKey, lValue ] : mDepthMap )
    {
        if ( lValue == 1 )
        {
            aIndependents.second.push( lKey );
            ++aIndependents.first;
        }
    }
}

void Graph::CreateDepthResultTree( DepthResultTree& aDepthResultTree ) const
{
    for ( const auto& [ lKey, lValue ] : mDepthMap )
    {
        aDepthResultTree[ lValue ].push_back( lKey );
    }
}

void Graph::DoPrint( const DepthResultTree& aDepthResultTree ) const
{
    std::cout << "Depth\t\t" << "Nodes" << std::endl;

    for ( const auto& [ lDepth, lList ] : aDepthResultTree )
    {
        std::cout << lDepth << "\t\t";

        for ( const char& lNode : lList )
        {
            std::cout << lNode << " ";
        }

        std::cout << std::endl;
    }
}

const bool Graph::IsLowercaseLetter( const char aLetter ) const
{
    return( ( aLetter >= 'a' )
          && ( aLetter <= 'z' ) );
}

void Graph::AddEdge( const char aFromNode,
                     const char aToNode )
{
    if ( !IsLowercaseLetter( aFromNode )
       || !IsLowercaseLetter( aToNode ) )
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

    StackDescriptor lStackDescriptor;

    FindIndependentNodes( lStackDescriptor );

    if ( lStackDescriptor.first == 0 )
    {
        throw std::runtime_error( "No independent nodes found. Graph either has got no nodes, or graph is cyclic." );
    }

    CalculateDepths( lStackDescriptor );

    DepthResultTree lDepthTree;

    CreateDepthResultTree( lDepthTree );

    DoPrint( lDepthTree );
}
