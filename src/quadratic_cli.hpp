// ========================================================================== //
// HEADER FILES SECTION                                                       //
// ========================================================================== //

#pragma once
#include "../include/utility.hpp"
#include "../include/quadratic.hpp"
#include "quadratic_core.hpp"

// ========================================================================== //
// FUNCTION BODIES SECTION                                                    //
// ========================================================================== //

/**
 * =============================================================================
 * @brief PRINTS a border of the specified character
 *
 * this function prints a border made of the specified character 
 * (`border_symbol`) repeated (`border_length`) times and prints a 
 * newline character `\n` after the border
 *
 * @param border_symbol the character to use for the border `(datatype -> char)`
 * @param border_length The number of times the character should be 
 * repeated `(datatype -> int)`
 * @return `void`
 * =============================================================================
 */
void PrintBorder(char border_symbol, int border_length)
{
    for (int i = 0; i < border_length; i++)
    {
        std::cout << STYLE_COLOR::RED << border_symbol << STYLE_COLOR::RESET;
    }
    std::cout << "\n";
}

/**
 * =============================================================================
 * @brief PRINTS a loading bar of the character specified with the delay 
 * specified in the console
 *
 * displays a loading bar in the console of the specified symbol, updating 
 * it step by step with a delay between each step, the bar has a fixed length 
 * defined by the  `const int BORDER_LENGTH` defined in 
 * the `namespace STYLE_COLOR`
 *
 * @param LoadingSymbol the character to use in the loading 
 * bar `(datatype -> char)`
 * @param DelayMilliSeconds the delay (in milliseconds) between each step of 
 * the loading bar `(datatype -> int)`
 * @return `void`
 * =============================================================================
 */
void LoadingBar(char LoadingSymbol, int DelayMilliSeconds)
{
    for (int i = 1; i <= STYLE_COLOR::BORDER_LENGTH; i++)
    {
        std::cout << STYLE_COLOR::BLUE << "\r[" << STYLE_COLOR::RESET;
        for (int j = 0; j < i; j++)
        {
            std::cout << STYLE_COLOR::GREEN << LoadingSymbol << STYLE_COLOR::RESET;
        }
        for (int j = i; j < STYLE_COLOR::BORDER_LENGTH; j++)
        {
            std::cout << STYLE_COLOR::GREEN << " " << STYLE_COLOR::RESET;
        }
        std::cout << STYLE_COLOR::BLUE << "]" << STYLE_COLOR::RESET << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(DelayMilliSeconds));
    }

    std::cout << "\n\n";
}

/**
 * =============================================================================
 * @brief CLEARS the `INPUT BUFFER` from the console, in case user enters 
 * something extra to the console
 * @return `void`
 * =============================================================================
 */
void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        //
    }
}

/**
 * =============================================================================
 * @brief PRINTS a welcome message and a basic guide for the project
 *
 * PRINTS project information, usage guidance, and equation format with proper 
 * borders, padding, and formatting for
 * readability
 * @param `void`
 * @return `void`
 * =============================================================================
 */
void PrintWelcomeMessage()
{
    PrintBorder(STYLE_COLOR::BORDER_SYMBOL, STYLE_COLOR::BORDER_LENGTH);

    std::string title = "QUADRATIC CALCULATOR USING C++";
    int padding = (STYLE_COLOR::BORDER_LENGTH - title.length()) / 2;
    std::cout << std::setw(padding + title.length()) << title << std::endl;

    std::cout << "this CLI based tool solves quadratic equations of the form of : \n";
    std::cout << "                  ax² + bx + c = 0             \n";
    std::cout << "NOTE : this tool accounts for precision till 4 decimal places (0.0000)\n";

    PrintBorder(STYLE_COLOR::BORDER_SYMBOL, STYLE_COLOR::BORDER_LENGTH);
}

/**
 * =============================================================================
 * @brief `PROMPTS` the user to enter the value of `a`, `b`, `c` and then 
 * validates the value of `a`, `b`, `c` entered by the user and then
 * `RETURNS` a `POINTER` to an object of type `QUADRATIC`
 * @param `void`
 * @return `POINTER` to an object of type `QUADRATIC` 
 * `(data type -> QUADRATIC *)`
 * =============================================================================
 */
QUADRATIC *InputData()
{
    // INPUT the value of a from the user
    double a = 0.0000;
    std::cout << STYLE_COLOR::GREEN << "enter a -> (coefficient of quadratic term  i.e coefficient of (x²)) : " << STYLE_COLOR::RESET;
    std::cin >> a;

    // clear input buffer after taking input from the user
    ClearInputBuffer();

    // CASE : if user enters a = 0, then PRINT a message and ask the user to enter the value of a again
    while (COMPARE_DOUBLE::IS_ZERO(a))
    {
        std::cout << STYLE_COLOR::RED << "\nTHE VALUE OF a CANNOT BE 0\nTHE COEFFICIENT OF x² CANNOT BE 0\n"
                  << STYLE_COLOR::RESET;

        std::cout << STYLE_COLOR::GREEN << "enter a -> (coefficient of quadratic term  i.e coefficient of (x²)) : " << STYLE_COLOR::RESET;
        std::cin >> a;

        // clear input buffer after taking input from the user
        ClearInputBuffer();
    }

    // INPUT the value of b from the user
    double b = 0.0000;
    std::cout << STYLE_COLOR::GREEN << "enter b -> (coefficient of linear term  i.e coefficient of (x))     : " << STYLE_COLOR::RESET;
    std::cin >> b;

    // clear input buffer after taking input from the user
    ClearInputBuffer();

    // INPUT the value of c from the user
    double c = 0.0000;
    std::cout << STYLE_COLOR::GREEN << "enter c -> (constant term)                                          : " << STYLE_COLOR::RESET;
    std::cin >> c;

    // clear input buffer after taking input from the user
    ClearInputBuffer();

    // return a POINTER to an object of type QUADRATIC
    return new QUADRATIC(a, b, c);
}

/**
 * =============================================================================
 *  @brief Runs the Quadratic Equation Calculator in a CLI-based, 
 * menu-driven interface
 *
 * this function handles the complete flow of the calculator:
 *  - prints a welcome message with project information and a basic user guide
 *  - continuously prompts the user to input quadratic equation data using a 
 * `while (true)` loop
 *  - calculates equation parameters, prints the equation, and displays the 
 * roots in a formatted manner
 *  - uses a loading bar and border formatting for enhanced CLI visualization
 *  - validates user input for continuation
 *  - properly deletes dynamically allocated objects to avoid memory leaks
 * the loop continues until the user chooses to exit by entering a valid choice
 *
 * @param `void`
 *
 * @return `void`
 *
 * @note Make sure the terminal supports ANSI escape codes for colored output
 * =============================================================================
 */
void QUADRATIC_CALCULATOR()
{
    // PRINTS a welcome message that guides the usr through the project
    PrintWelcomeMessage();

    // INFINITE LOOP to keep the project running till the user wants to run it
    while (true)
    {
        // create an object of type QUADRATIC
        QUADRATIC *Q = InputData();

        // print the border
        PrintBorder(STYLE_COLOR::BORDER_SYMBOL, STYLE_COLOR::BORDER_LENGTH);

        // print a message to simulate processing in the console
        std::cout << "\nFETCHING RESULTS ...\n";

        // display a loading bar to simulate processing in the console
        LoadingBar(STYLE_COLOR::LOADING_SYMBOL, 15);

        // calculate the parameters of the equation
        Q->CalculateEquationParameters();

        // print the equation
        Q->PrintEquation();

        // print the equation parameters
        Q->PrintEquationParameters();

        // print the border
        PrintBorder(STYLE_COLOR::BORDER_SYMBOL, STYLE_COLOR::BORDER_LENGTH);

        // var to ask the user for choice if usr wants to continue or exit the project
        char choice = 'x';

        // INFINITE LOOP -> in case user enters invalid choice
        while (true)
        {
            // INPUT the choice from the user whether user want to continue the project or exit the project
            std::cout << "do you want to continue ? [YES -> y | NO -> n] : ";
            std::cin >> choice;

            // clear input buffer after taking input from the user
            ClearInputBuffer();

            // CASE : user enters valid choice
            if (choice == 'y' || choice == 'n')
            {
                break; // valid input, exit inner loop
            }

            // CASE : user enters invalid choice
            else
            {
                std::cout << STYLE_COLOR::RED << "INVALID CHOICE !! Please enter 'y' or 'n'\n"
                          << STYLE_COLOR::RESET;
            }
        }

        // DELETE the created object
        delete Q;

        // CASE : user wants to EXIT, PRINT a message and break out of the loop
        if (choice == 'n')
        {
            std::cout << "\n";
            std::cout << STYLE_COLOR::RED << "EXITING...\n"
                      << STYLE_COLOR::RESET;
            LoadingBar('.', 10);
            std::cout << STYLE_COLOR::RED << "EXIT\n"
                      << STYLE_COLOR::RESET << std::endl;
            PrintBorder(STYLE_COLOR::BORDER_SYMBOL, STYLE_COLOR::BORDER_LENGTH);
            break;
        }

        // CASE : user wants to continue the project, move the control to the start of the loop
        if (choice == 'y')
        {
            continue;
        }
    }
}