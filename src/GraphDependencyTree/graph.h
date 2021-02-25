/*!
 * \file      graph.h
 * \author    attila.krupl
 * \date      2021/02/25
 */

#pragma once

namespace nGraph
{
    /*!
     * \class Graph
     * \brief the class representing a graph
     */
    class GRAPH_EXPORT Graph final
    {
    private:
        std::map<char, std::list<char>> mAdjacencyMap;                                                                                     /*!< The adjacency map                                                   */
        std::set<char>                  mFromNodes;                                                                                        /*!< The nodes from which there is at least one edge directed to another */
        std::set<char>                  mToNodes;                                                                                          /*!< The nodes to which there is at least one adge directed from another */

    public:
        /*!
         * Adds edge to the graph
         *
         * \param  aFromNode  the starting node
         * \param  aToNode    the end node
         */
        void AddEdge( const char aFromNode,
                      const char aToNode );

        /*!
         * Prints the dependency tree of the grph
         */
        void PrintDependencyTree();
    };
}
