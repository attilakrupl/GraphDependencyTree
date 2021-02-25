/*!
 * \file      graph.h
 * \author    attila.krupl
 * \date      2021/02/24
 */

#pragma once

namespace nGraph
{
    /*!
     * \class Graph
     * \brief represents the graph object
     */
    template<typename T>
    class __declspec( dllexport )Graph final
    {
    private:
        int                       mVertexCount;                                                                                            /*!< The number of vertices                                        */
        std::map<T, std::list<T>> mEdges;                                                                                                  /*!< The edges between the vertices                                */
        std::set<T>               mVerticesControlSet;                                                                                     /*!< The vertex number control set                                 */
        std::set<T>               mStartVertices;                                                                                          /*!< The vertices from which an edge is pointed to another vertex  */
        std::set<T>               mEndVertices;                                                                                            /*!< The vertices to which an edge is pointed from another vertex  */

    private:
        ddff void TarjanCheck();

    public:
        /*!
         * Constructor
         *
         * \param   aNumberOfVertices   the number of vertices the graph consists of
         */
        inline Graph( const int aNumberOfVertices );

    public:
        /*!
         * Adds directed edge between two vertices
         *
         * \param  aFrom  the source vertex
         * \param  aTo    the destination vertex
         */
        inline void AddEdge( const T aFrom,
                             const T aTo );

        /*!
         * Prints dependency tree of the given graph
         */
        inline void PrintDependencyTree();
    };

    template<typename T>
    inline Graph<T>::Graph( const int aNumberOfVertices )
        : mVertexCount( aNumberOfVertices )
    {
        const bool lIsStreamable = IsStreamable<std::stringstream, T>::value;

        if ( !lIsStreamable )
        {
            throw std::runtime_error( "Graph Vertex Type is not output stream capable. Please provide a primitive type or make sure output stream operator is provided." );
        }
    }

    template<typename T>
    inline void Graph<T>::AddEdge( const T aFrom,
                                   const T aTo )
    {
        mVerticesControlSet.insert( aFrom );
        mVerticesControlSet.insert( aTo );

        if ( mVerticesControlSet.size() > mVertexCount )
        {
            throw std::runtime_error( "Inconsistent Edge Addition: vertex count exceeds initial vertex count." );
        }

        mEdges[ aFrom ].push_back( aTo );
    }

    template<typename T>
    void Graph<T>::PrintDependencyTree()
    {
        TarjanCheck();
    }
}
