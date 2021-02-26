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
         *
         * \param   aInitialIndependents   the initial independent nodes
         */
        void CalculateDepths( const std::list<char>& aInitialIndependents );

        /*!
         * Traverses the graph with BFS algorithm and calculates depths of the nodes
         *
         * \param   aStackDescriptor   the stack descriptor containing the stack to unwind and the size of the current depth level
         * \param   aDepthValue        the depth value of the nodes unwinding in current iteration
         */
        void CalculateDepthsBFS( std::pair<int, std::queue<char>>& aStackDescriptor,
                                 const int                         aDepthValue );

        /*!
         * Finds independent nodes in graph
         *
         * \param   aIndependents  the independent node list
         */
        void FindIndependentNodes( std::list<char>& aIndependents );

        /*!
         * Creates depth tree to be printed
         *
         * \param  aDepthTree  the depth tree
         */
        void CreateDepthTree( std::map<int, std::list<char>>& aDepthTree );

        /*!
         * Does the depth tree printing
         *
         * \param   aDepthTree  the depth tree to be printed
         */
        void DoPrint( const std::map<int, std::list<char>>& aDepthTree );

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
         * Prints the dependency tree of the graph
         */
        void PrintDependencyTree();
    };
}
