// ========================================================================== //
// HEADER FILES SECTION                                                       //
// ========================================================================== //

#pragma once
#include "utility.hpp"

// ========================================================================== //
// CLASS DEFINITION                                                           //
// ========================================================================== //


/**
 * =============================================================================
 * @brief `class` definition of `class QUADRATIC` with data members
 *
 * `a ->` coefficient of quadratic term (i.e coefficient of x²) (datatype -> `double`)
 * `b ->` coefficient of linear term (i.e coefficient of (x)) (datatype -> `double`)
 * `c ->` constant term (c) (datatype -> `double`)
 * `D ->` discriminant (calculated based on the value of a, b, c) (datatype -> 
 * `double`)
 * `root1 ->` root 1 of the equation (datatype -> `double`)
 * `root2 ->` root 2 of the equation (datatype -> `double`)
 * `nature_of_roots` string to describe the nature of the roots (datatype -> 
 * `std::string`)
 * =============================================================================
 */
class QUADRATIC
{
private:
    // ====================================================================== //
    // CLASS MEMBERS                                                          //
    // ====================================================================== //

    // coefficient of quadratic term (i.e coefficient of x²)
    double a;

    // coefficient of linear term (i.e coefficient of (x))
    double b;

    // constant term (c)
    double c;

    // discriminant (calculated based on the value of a, b, c)
    double D;

    // root 1 of the equation
    double root1;

    // root 2 of the equation
    double root2;

    // string to describe the nature of the roots
    std::string nature_of_roots;

public:
    // ====================================================================== //
    // CONSTRUCTOR PROTOTYPES                                                 //
    // ====================================================================== //

    QUADRATIC();
    QUADRATIC(double a, double b, double c);
    QUADRATIC(const QUADRATIC &other);

    // ====================================================================== //
    // GETTER PROTOTYPES                                                      //
    // ====================================================================== //

    inline double GetA();
    inline double GetB();
    inline double GetC();
    inline double GetD();
    inline double GetRoot1();
    inline double GetRoot2();
    inline std::string GetNatureOfRoots();

    // ====================================================================== //
    // SETTER PROTOTYPES                                                      //
    // ====================================================================== //
    //                         ***** IMPORTANT *****                          //
    // NOTE :                                                                 //
    // no setters for attributes -> (D, root1, root2, nature_of_roots)        //
    // because they are derived attributes                                    //
    // ====================================================================== //

    inline void SetA(double a);
    inline void SetB(double b);
    inline void SetC(double c);

    // ====================================================================== //
    // METHOD PROTOTYPES                                                      //
    // ====================================================================== //

    void CalculateEquationParameters();
    void PrintEquation();
    void PrintEquationParameters();
};

// ========================================================================== //
// FUNCTION PROTOTYPES                                                        //
// ========================================================================== //

void PrintBorder(char border_symbol, int border_length);
void LoadingBar(char LoadingSymbol, int DelayMilliSeconds);
void ClearInputBuffer();
void PrintWelcomeMessage();
QUADRATIC *InputData();
void QUADRATIC_CALCULATOR();
