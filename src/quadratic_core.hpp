// ===========================================================================//
// HEADER FILES SECTION                                                       //
// ========================================================================== //

#pragma once
#include "../include/utility.hpp"
#include "../include/quadratic.hpp"

// ========================================================================== //
// CONSTRUCTOR BODIES SECTION                                                 //
// ========================================================================== //

/**
 * =============================================================================
 * @brief `DEFAULT constructor` for the class `QUADRATIC`
 *
 * creates an object of type `QUADRATIC` by indirectly calling the  the
 * `PARAMETERIZED constructor` with the values`
 * a = b = c = D = 0.0000`
 * =============================================================================
 */
QUADRATIC::QUADRATIC()
{
    this->a = this->b = this->c = this->D = 1.0000;
}

/**
 * =============================================================================
 * @brief `PARAMETERIZED constructor` for the class `QUADRATIC`
 *
 * creates an object of type `QUADRATIC` with values of `a`, `b`, `c` passed to
 * it and calculates the value of `D` using `a`, `b`, `c`
 *
 * @param a coefficient of the quadratic term (i.e the coefficient of x²)
 * @param b coefficient of the linear term (i.e the coefficient of x)
 * @param c constant term (i.e c)
 * =============================================================================
 */
QUADRATIC::QUADRATIC(double a, double b, double c) : a(a), b(b), c(c)
{

    this->D = (b * b) - (4 * a * c);
}

/**
 * =============================================================================
 * @brief `COPY CONSTRUCTOR` for the class `QUADRATIC`
 *
 * creates an object of type `QUADRATIC` by copying the attributes of the object
 * of type `QUADRATIC` passed to it
 *
 * @param other object of type `QUADRATIC` `(datatype -> QUADRATIC)`
 * =============================================================================
 */
QUADRATIC::QUADRATIC(const QUADRATIC &other)
{
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    this->D = other.D;
}

// ========================================================================== //
// GETTER BODIES SECTION                                                      //
// ========================================================================== //

/**
 * =============================================================================
 * @brief `RETURNS` the value of `a` i.e the value of the coefficient of `x²` of
 * the current `QUADRATIC` object
 * @note method type -> `GETTER`
 * @return `double`
 * =============================================================================
 */
inline double QUADRATIC::GetA()
{
    return this->a;
}

/**
 * =============================================================================
 * @brief `RETURNS` the value of `b` i.e the value of the coefficient of `x` of
 * the current `QUADRATIC` object
 * @note method type -> `GETTER`
 * @return `double`
 * =============================================================================
 */
inline double QUADRATIC::GetB()
{
    return this->b;
}

/**
 * =============================================================================
 * @brief `RETURNS` the value of `c` i.e the value of the constant term of the
 * current `QUADRATIC` object
 * @note method type -> `GETTER`
 * @return `double`
 * =============================================================================
 */
inline double QUADRATIC::GetC()
{
    return this->c;
}

/**
 * =============================================================================
 * @brief `RETURNS` the value of `D` i.e the value of the `discriminant` of the
 * current `QUADRATIC` object
 * `D = (b * b) - (4 * a * c)`
 * @note method type -> `GETTER`
 * @return `double`
 * =============================================================================
 */
inline double QUADRATIC::GetD()
{
    return this->D;
}

/**
 * =============================================================================
 * @brief `RETURNS` the value of `root1` of the current `QUADRATIC` object
 * @note method type -> `GETTER`
 * @return `double`
 * =============================================================================
 */
inline double QUADRATIC::GetRoot1()
{
    return this->root1;
}

/**
 * =============================================================================
 * @brief `RETURNS` the value of `root2` of the current `QUADRATIC` object
 * @note method type -> `GETTER`
 * @return `double`
 * =============================================================================
 */
inline double QUADRATIC::GetRoot2()
{
    return this->root2;
}

/**
 * =============================================================================
 * @brief `RETURNS` the value of `nature_of_roots` of the current `QUADRATIC`
 * object
 * @note method type -> `GETTER`
 * @return datatype -> `std::string`
 * =============================================================================
 */
inline std::string QUADRATIC::GetNatureOfRoots()
{
    return this->nature_of_roots;
}

// ========================================================================== //
// SETTER BODIES SECTION                                                      //
// ========================================================================== //
//                         ***** IMPORTANT *****                              //
// NOTE :                                                                     //
// no SETTERS for attributes -> (D, root1, root2, nature_of_roots)            //
// because they are derived attributes                                        //
// ========================================================================== //

/**
 * =============================================================================
 * @brief `SETS` the value of `a` i.e the value of the coefficient of `x²` of the
 * current `QUADRATIC` object to the value of `a` passed to it
 * @note method type -> `SETTER`
 * @param `a` (datatype -> `double`)
 * @return `void`
 * @warning **IF USER TRIES TO SET THE VALUE TO 0 BY PASSING 0 TO THE METHOD
 * THEN THIS METHOD PRINTS A MESSAGE AND ABORTS THE PROGRAM BY CALLING `abort`**
 * =============================================================================
 */
inline void QUADRATIC::SetA(double a)
{
    if (!COMPARE_DOUBLE::IS_ZERO(a))
    {
        this->a = a;
    }
    else
    {
        std::cout << STYLE_COLOR::RED << "\nTHE VALUE OF a CANNOT BE 0\nTHE COEFFICIENT OF x² CANNOT BE 0\n"
                  << STYLE_COLOR::RESET;
        std::cout << STYLE_COLOR::RED << "\nabort() initiated from the method SetA()\n"
                  << STYLE_COLOR::RESET;
        abort();
    }
}

/**
 * =============================================================================
 * @brief `SETS` the value of `b` i.e the value of the coefficient of `x` of the
 * current `QUADRATIC` object to the value of `b` passed to it
 * @note method type -> `SETTER`
 * @param `b` (datatype -> `double`)
 * @return `void`
 * =============================================================================
 */
inline void QUADRATIC::SetB(double b)
{
    this->b = b;
}

/**
 * =============================================================================
 * @brief `SETS` the value of `c` i.e the value of constant term of the equation
 * of the current `QUADRATIC` object to the value of `c` passed to it
 * @note method type -> `SETTER`
 * @param `c` (datatype -> `double`)
 * @return `void`
 * =============================================================================
 */
inline void QUADRATIC::SetC(double c)
{
    this->c = c;
}

// ========================================================================== //
// METHOD BODIES SECTION                                                      //
// ========================================================================== //

/**
 * =============================================================================
 * @brief calculates the `roots` and sets the `nature_of_roots` based on the
 * `discriminant -> D` of the current `QUADRATIC` object
 * @param `void`
 * @return `void`
 * =============================================================================
 */
void QUADRATIC::CalculateEquationParameters()
{
    // CASE : D >= 0
    if (COMPARE_DOUBLE::IS_GREATER_THAN_EQUAL_TO(this->D, 0.0000))
    {
        // compute the roots of the equation
        this->root1 = (-this->b + sqrt(this->D)) / (2 * this->a);
        this->root2 = (-this->b - sqrt(this->D)) / (2 * this->a);

        // CASE : D == 0
        if (COMPARE_DOUBLE::IS_ZERO(this->D))
        {
            // set the nature of roots
            this->nature_of_roots = "TWO REAL AND EQUAL ROOTS";
        }

        // CASE D > 0
        if (COMPARE_DOUBLE::IS_GREATER(this->D, 0.0000))
        {
            // set the nature of roots
            this->nature_of_roots = "TWO REAL AND DISTINCT ROOTS";
        }
    }

    // CASE : D < 0
    else
    {
        // set the roots to INFINITY
        this->root2 = INFINITY;
        this->root1 = INFINITY;

        // set the nature of roots
        this->nature_of_roots = "TWO IMAGINARY ROOTS";
    }
}

/**
 * =============================================================================
 * @brief PRINTS the equation with the sign of the coefficients in the format
 * `ax² + bx + c = 0` of the current `QUADRATIC` object
 * @param `void`
 * @return `void`
 * =============================================================================
 */
void QUADRATIC::PrintEquation()
{
    // C++ command to print the number with their sign
    std::cout << std::showpos;

    std::cout << STYLE_COLOR::BLUE << "EQUATION : " << this->a << "x²" << "" << this->b << "x" << this->c << " = 0\n\n"
              << STYLE_COLOR::RESET;
    std::cout << STYLE_COLOR::BLUE << "a -> coefficient of quadratic term (x²) : " << this->a << "\n"
              << STYLE_COLOR::RESET;
    std::cout << STYLE_COLOR::BLUE << "b -> coefficient of linear term (x)     : " << this->b << "\n"
              << STYLE_COLOR::RESET;
    std::cout << STYLE_COLOR::BLUE << "c -> constant term                      : " << this->c << "\n"
              << STYLE_COLOR::RESET;

    // C++ command to reset the print with signs command
    std::cout << std::noshowpos;
}

/**
 * =============================================================================
 * @brief PRINTS the value of `Discriminant (D)`, `nature_of_roots`,
 * `root1` and `root2` of the current `QUADRATIC` object
 *
 * `(datatype(Discriminant) -> : double)`
 * `(datatype(nature_of_roots) -> : std::string)`
 * `(datatype(root1) -> : double)`
 * `(datatype(root2) -> : double)`
 * @param `void`
 * @return `void`
 * =============================================================================
 */
void QUADRATIC::PrintEquationParameters()
{
    // C++ command to print the numbers with their signs
    std::cout << std::showpos;

    // print the nature of roots
    std::cout << STYLE_COLOR::BLUE << "\nNATURE OF ROOTS                         : " << this->nature_of_roots << "\n\n"
              << STYLE_COLOR::RESET;

    // print the discriminant of the equation
    std::cout << STYLE_COLOR::BLUE << "D -> discriminant                       : " << this->D << "\n\n"
              << STYLE_COLOR::RESET;

    // CASE : D < 0 -> PRINT a message
    if (this->nature_of_roots == "TWO IMAGINARY ROOTS")
    {
        std::cout << STYLE_COLOR::BLUE << "x -> root 1                             : " << "NOT DEFINED" << "\n"
                  << STYLE_COLOR::RESET;
        std::cout << STYLE_COLOR::BLUE << "x -> root 2                             : " << "NOT DEFINED" << "\n"
                  << STYLE_COLOR::RESET;
    }

    // CASE : D >= 0
    else
    {
        std::cout << STYLE_COLOR::BLUE << "x -> root 1                             : " << this->root1 << "\n"
                  << STYLE_COLOR::RESET;
        std::cout << STYLE_COLOR::BLUE << "x -> root 2                             : " << this->root2 << "\n"
                  << STYLE_COLOR::RESET;
    }

    // C++ command to reset the show sign command
    std::cout << std::noshowpos;
}
