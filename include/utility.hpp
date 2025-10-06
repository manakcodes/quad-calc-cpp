// ========================================================================== //
// HEADER FILES SECTION                                                       //
// ========================================================================== //

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <unistd.h>
#include <chrono>
#include <thread>

// ========================================================================== //
// NAMESPACE SECTION                                                          //            
// ========================================================================== //

/**
 * =============================================================================
 * @namespace COMPARE_DOUBLE
 * @brief provides constants and utility functions to compare double values with
 * precision up to 4 decimal places
 *
 * all comparison functions use `EPSILON` to account for floating-point
 *  inaccuracies
 * =============================================================================
 */
namespace COMPARE_DOUBLE
{
    /**
     * =========================================================================
     * @brief tolerance value for floating-point comparisons
     *
     * used to compare double values up to 4 decimal places
     * =========================================================================
     */
    const double EPSILON = 1E-4;

    /**
     * =========================================================================
     * @brief checks if a `double` is effectively `ZERO`
     * @param x value to check
     * @return `TRUE` if `|x| < EPSILON` , otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_ZERO(double x)
    {
        return std::fabs(x) < EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if a `double` is effectively `ONE
     * @param x value to check
     * @return `TRUE` if `|x - 1| < EPSILON`, otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_ONE(double x)
    {
        return std::fabs(x - 1.0) < EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if a `double` is positive beyond `EPSILON`
     * @param x value to check
     * @return `TRUE` if `x > EPSILON`, otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_POSITIVE(double x)
    {
        return x > EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if a `double` is negative beyond `EPSILON`
     * @param x value to check
     * @return `TRUE` if `x < -EPSILON`, otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_NEGATIVE(double x)
    {
        return x < -EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if two `doubles` are effectively `EQUAL`
     * @param a first value
     * @param b second value
     * @return `TRUE` if `|a - b| < EPSILON`, otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_EQUAL(double a, double b)
    {
        return std::fabs(a - b) < EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if a is greater than b considering `EPSILON`
     * @param a first value
     * @param b second value
     * @return `TRUE` if `(a - b) >= EPSILON`, otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_GREATER(double a, double b)
    {
        return (a - b) >= EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if a is less than b considering `EPSILON`
     * @param a first value
     * @param b second value
     * @return `TRUE` if `(b - a) > EPSILON`, otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_LESS(double a, double b)
    {
        return (b - a) > EPSILON;
    }

    /**
     * =========================================================================
     * @brief checks if a is greater than or equal to b
     * @param a first value
     * @param b second value
     * @return `TRUE` if `a > b OR a is equal to b` within `EPSILON`, 
     * otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_GREATER_THAN_EQUAL_TO(double a, double b)
    {
        return (a > b) || IS_EQUAL(a, b);
    }

    /**
     * =========================================================================
     * @brief checks if a is less than or equal to b
     * @param a first value
     * @param b second value
     * @return `TRUE` if `a < b OR a is equal to b within `EPSILON`, 
     * otherwise `FALSE`
     * =========================================================================
     */
    inline bool IS_LESS_THAN_EQUAL_TO(double a, double b)
    {
        return (a < b) || IS_EQUAL(a, b);
    }
}

namespace STYLE_COLOR
{
    /**
     * =========================================================================
     * @brief `symbol` used to draw `borders` in `terminal`
     * =========================================================================
     */
    const char BORDER_SYMBOL = '=';

    /**
     * =========================================================================
     * @brief `length` of border lines in `terminal`
     * =========================================================================
     */
    const int BORDER_LENGTH = 72;

    /**
     * =========================================================================
     * @brief `symbol` used in `loading bars` in `terminal`
     * =========================================================================
     */
    const char LOADING_SYMBOL = '.';

    /**
     * =========================================================================
     * @brief reset `terminal` text formatting
     * =========================================================================
     */
    const char *RESET = "\033[0m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to `RED`
     * =========================================================================
     */
    const char *RED = "\033[1;31m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to `GREEN`
     * =========================================================================
     */
    const char *GREEN = "\033[1;32m";

    /**
     * =========================================================================
     * @brief set `terminal` text color to `BLUE`
     * =========================================================================
     */
    const char *BLUE = "\033[1;34m";
}