/*!
 * \file      GraphDependencyTreeTest.h
 * \author    attila.krupl
 * \date      2021/02/25
 */

#pragma once

namespace nTests
{
    class GraphDependencyTreeTest final
    {
    private:
        GraphDependencyTreeTest() = delete;

    public:
        /*!
         * The initial test case provided in the homework description
         *
         * \return a negative error code in case of error, 0 otherwise
         */
        static int InitialTestCase();
    };
}
