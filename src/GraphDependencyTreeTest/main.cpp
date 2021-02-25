/*!
 * \file      main.cpp
 * \author    attila.krupl
 * \date      2021/02/24
 */

#include "stdafx.h"

using namespace std;
using namespace nGraph;

int main( [[maybe_unused]] int    argc,
          [[maybe_unused]] char** argv )
{
    try
    {
        Graph<char> lGraph( 10 );

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
        cout << aException.what() << endl;
        return -1;
    }
    catch( ... )
    {
        cout << "Unexpected error occurred" << endl;
        return -2;
    }

    return 0;
}
