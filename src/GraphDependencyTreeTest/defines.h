/*!
 * \file   defines.h
 * \author Attila Krüpl dr.
 * \date   27/02/2021
 */

#pragma once

/* *INDENT-OFF* */
#define EVALUATE_TEST_RESULT( aResult, aTestName )                                                              \
        if ( lTestResult != 0 )                                                                                 \
        {                                                                                                       \
            std::cout << aTestName << " test FAILED with error: " << aResult << "\n" << std::endl;              \
            return lTestResult;                                                                                 \
        }                                                                                                       \
        else                                                                                                    \
        {                                                                                                       \
            std::cout << aTestName << " test finished SUCCESSFULLY.\n" << std::endl;                            \
        }
/* *INDENT-ON* */
