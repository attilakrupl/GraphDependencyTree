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
        std::map<char, int>             mDepthMap;                                                                                         /*!< The depth map of the nodes                                          */

    private:
        /*!
         * Tells whether the directed graph is cyclic or not
         *
         * \return  true if the digraph is cyclic, false otherwise
         */
        const bool IsCyclic();

        /*!
         * The function that implements the DFS logic
         *
         * \param  aNode             the node in question
         * \param  aVisited          the visited flag container
         * \param  aRecursiveStack   the recursive stack container
         * \return true is graph is cyclic, false otherwise
         */
        const bool IsCyclicHelper( const char            aNode,
                                   std::map<char, bool>& aVisited,
                                   std::map<char, bool>& aRecursiveStack );

        /*!
         * Calculates the node depths using BFS
         */
        void CalculateDepths();

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
