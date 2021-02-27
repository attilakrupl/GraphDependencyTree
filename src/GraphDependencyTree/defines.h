/*!
 * \file   defines.h
 * \author Attila Krüpl dr.
 * \date   27/02/2021
 */

#pragma once

#ifdef GRAPH_EXPORTS
    #define GRAPH_EXPORT __declspec( dllexport )
#else
    #define GRAPH_EXPORT
#endif
