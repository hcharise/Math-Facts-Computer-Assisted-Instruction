/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
HW #4 - Exercises 6.57 - 6.61 pg 281-282
2/20/2024
 
DESCRIPTION

Main.CPP

*/

#include <iostream>

using std::cout;
using std::cin;

// Class declaration - quiz?

    // Constructor with operation and difficulty initialized

    // Member Functions

        // Generate question - actually just a setter for each operand?
            // Operands = rand

        // Check answer
            // If (operation = +), then correct = op1 + op2
            // return (user answer == correct answer)

        // Caculate score
            // if (Number Correct / 10 < 75%), then print good job!
            //

        // Print positive message
            // rand and switch

        // Print negative message
            // rand and switch


    // Data Members
        // User Answer
        // Correct Answer
        // First Operand
        // Second Operand
        // Number Total
        // Number Correct
        // Difficulty
        // Operation


int main() {
    int difficulty; // User-chosen difficulty level, ie. the number of digits
    int operation; // User-chosen operation (+, -, *, /, mix)
    
    // Print intro banner
    
    // Prompt user for difficulty and operation
    
    // Loop for each user (difficulty != -1?)
        
        // Loop for each question (10 or fewer times)
            // Print question (What is quiz.getfirstoperand quiz.getoperation quiz.getsecondoperand)
            // Get user's input and set in object
    
            // while check answer == false, then
                // number total++
                // print negative message
                // re-get input
            // number correct++ & number total++
            // print positive message

        // Calcuate total score and print appropriate message
    
        // Reprompt new user for difficulty and operation
    
} // end main
