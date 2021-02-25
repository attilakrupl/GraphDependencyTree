/*!
 * \file      defines.h
 * \author    attila.krupl
 * \date      2021/02/24
 */

#ifdef GRAPH_EXPORTS
    #define GRAPH_EXPORT __declspec( dllexport )
#else
    #define GRAPH_EXPORT
#endif
