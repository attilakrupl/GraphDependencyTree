/*!
 * \file   graphdependencytreetest.h
 * \author Attila Krüpl dr.
 * \date   27/02/2021
 */

#pragma once

namespace nTests
{
    /*!
     * \class GraphDependencyTreeTest
     * \brief The graph dependency tree generator library's test functions
     */
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

        /*!
         * Cyclic graph check test
         *
         * \return a negative error code in case of error, 0 otherwise
         */
        static int CyclicGraphFailingTestCase();

        /*!
         * Invalid node ID test
         *
         * \return a negative error code in case of error, 0 otherwise
         */
        static int InvalidNodeIDTestCase();

        /*!
         * Complex graph test case
         *
         * \return a negative error code in case of error, 0 otherwise
         */
        static int ComplexGraphTestCase();
    };
}
