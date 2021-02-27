/*!
 * \file   graph.h
 * \author Attila Krüpl dr.
 * \date   27/02/2021
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
        using AdjacencyMap    = std::map<char, std::list<char>>;                                                                           /*! Alias for adjacency map                                              */
        using DepthMap        = std::map<char, int>;                                                                                       /*! Alias for depth map                                                  */
        using StackDescriptor = std::pair<int, std::queue<char>>;                                                                          /*! Alias for stack descriptor structure                                 */
        using DepthResultTree = std::map<int, std::list<char>>;                                                                            /*! Alias for depth result tree                                          */

    private:
        AdjacencyMap mAdjacencyMap;                                                                                                        /*!< The adjacency map                                                   */
        DepthMap     mDepthMap;                                                                                                            /*!< The depth map of the nodes                                          */

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
        const bool IsCyclicDFS( const char            aNode,
                                std::map<char, bool>& aVisited,
                                std::map<char, bool>& aRecursiveStack );

        /*!
         * Calculates the node depths using BFS
         *
         * \param   aInitialIndependents   the initial independent nodes
         */
        void CalculateDepths( StackDescriptor& aInitialIndependents );

        /*!
         * Traverses the graph with BFS algorithm and calculates depths of the nodes
         *
         * \param   aStackDescriptor   the stack descriptor containing the stack to unwind and the size of the current depth level
         * \param   aDepthValue        the depth value of the nodes unwinding in current iteration
         */
        void CalculateDepthsBFS( StackDescriptor& aStackDescriptor,
                                 const int        aDepthValue );

        /*!
         * Finds independent nodes in graph
         *
         * \param   aIndependents  the independent node list
         */
        void FindIndependentNodes( StackDescriptor& aIndependents ) const;

        /*!
         * Creates depth tree to be printed
         *
         * \param  aDepthTree  the depth tree
         */
        void CreateDepthResultTree( DepthResultTree& aDepthResultTree ) const;

        /*!
         * Does the depth tree printing
         *
         * \param   aDepthTree  the depth tree to be printed
         */
        void DoPrint( const DepthResultTree& aDepthResultTree ) const;

        /*!
         * Tells whether input argument is a lowercase letter or not
         *
         * \param   character representation of input
         * \return  true if character is lowercase letter, false otherwise
         */
        const bool IsLowercaseLetter( const char aLetter ) const;

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
