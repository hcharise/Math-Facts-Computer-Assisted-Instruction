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
#include <cstdlib>

using std::cout;
using std::cin;

// Class declaration - quiz?
class Quiz {
public: // NEED: CAN MORE OF THESE BE PRIVATE?
    // CONSRTUCTOR
    // with qustion counts initialized
    Quiz () {
        // empty body
    } // end constructor
    
    // Print into banner
    void printIntroBanner() {
        // Print intro banner
        cout << "----------------------------------------------\n"
            << "                 Ms. Ashton's                 \n"
            << "              Math Fact Practice              \n"
            << "----------------------------------------------\n\n";
        
    } // end printIntroBanner()
    
    void printOperationMenu() {
        
        // Prompt user for operation
        cout << "Welcome, student!\n\n"
            << "What operation are you practicing today?\n"
            << "    1: Addition\n"
            << "    2: Subtraction (answers may be negative)\n"
            << "    3: Multiplication\n"
            << "    4: Division (rounded to nearest whole)\n"
            << "    5: All Operations\n"
            << "    Or enter -1 to exit.\n"
            << "Operation: ";
        cin >> operation;
        if ((operation > 5 || operation < 1) && (operation != -1)) {
                    cout << "Invalid operation. Defaulting to addition.\n";
                    operation = 1;
                }
        cout << "\n";
        
    } // end printOperationMenu()
    
    void printDifficultyMenu() {
        cout << "What difficulty level is right for you?\n"
        << "    1: Up to One-Digit Numbers\n"
        << "    2: Up to Two-Digit Numbers\n"
        << "    3: Up to Three-Digit Numbers\n"
        << "    4: Up to Four-Digit Numbers\n"
        << "    5: Up to Five-Digit Numbers\n"
        << "Difficulty: ";
        cin >> difficulty;
        
        // check for invalid input
        if (difficulty > 5 || difficulty < 1) {
            cout << "Invalid difficulty. Defaulting to one-digit numbers.\n";
            difficulty = 1;
        }
        
    } // end printDifficultyMenu()
    
    void startQuiz() {
        
        printIntroBanner();
        printOperationMenu();

        // Loop for each user (operation != -1?)
        while (operation != -1) {
            printDifficultyMenu();
            
            cout << "\nLet's get started!\n\n";

            // Resent question counts
            answerCount = 0;
            correctCount = 0;
            
            // Loop for each question (total num < 10)
            while (answerCount < 10) {
                
                // Print question
                printQuestion();
                // Get user's input and set in object
                cin >> studentAnswer;
                answerCount++;
                checkQuestion();
                            
            } // end each user's 10 questions
            calculateScore();
            
            cout << "\n----------------------------------------------\n\n";

            // Reprompt new user for operation
            printOperationMenu();
                        
        } // end loop (all students completed quiz)
    }
    
    // Print question
    void printQuestion() {
        firstOperand = generateOperand();
        secondOperand = generateOperand();
        
        // If operation is mixed, choose random operation
        if (operation == 5) {
            currentOperation = (rand() % 4) + 1;
        } else {
            currentOperation = operation;
        }
        
        cout << "What is " << firstOperand;
        switch (currentOperation) {
            case (1):
                cout << " plus ";
                break;
            case (2):
                cout << " minus ";
                break;
            case (3):
                cout << " times ";
                break;
            case (4):
                cout << " divided by ";
                break;
            default:
                cout << " INVALID OPERATION ";
                break;
        }
        cout << secondOperand << "? ";
    } // end printQuestion()
    
    // Check answer
    bool checkAnswer() {
        switch (currentOperation) {
            case (1):
                if (studentAnswer == (firstOperand + secondOperand)) {
                    return true;
                }
                break;
            case (2):
                if (studentAnswer == (firstOperand - secondOperand)) {
                    return true;
                }
                break;
            case (3):
                if (studentAnswer == (firstOperand * secondOperand)) {
                    return true;
                }
                break;
            case (4):
                // Rounds to the nearest whole number (.5 and higher rounds up)
                if (studentAnswer == ((firstOperand + (secondOperand / 2)) / secondOperand)) {
                    return true;
                }
                break;
            default:
                cout << " CANNOT CHECK ANSWER. ";
                break;
        }
        // If hasn't already returned true, answer is incorrect
        return false;
    } // end checkAnswer()
    
    void checkQuestion() {
        
        // while (check answer == false && total num < 10), then
        while (checkAnswer() == false && answerCount <= 10) {
            if (answerCount < 10) {
                printNegativeMessage();
                cin >> studentAnswer;
                answerCount++;
            } else {
                // Error message for final question (not prompting for new response)
                cout << "   Still not quite.\n";
                break;
            }
            
        }
        
        if (checkAnswer() == true) {
            printPositiveMessage();
            correctCount++;
        }
        
    } // end checkQuestion()
    
    void calculateScore() {
        cout << "\nYour final score is " << (correctCount * 100 / answerCount) << "%.\n";
        if (((float)correctCount / answerCount) < 0.75) {
            cout << "Please ask your teacher for extra help.\n";
        } else {
            cout << "Congratulations, you are ready to go to the next level!\n";
        }
    } // end calculateScore
    
    void printPositiveMessage() {
        switch(rand() % 4) {
            case (0):
                cout << "   Very good!\n";
                break;
            case (1):
                cout << "   Excellent!\n";
                break;
            case (2):
                cout << "   Nice work!\n";
                break;
            default:
                cout << "   Keep up the good work!\n";
                break;
        }
    } // end printPositiveMessage()
    
    // Print negative message
    void printNegativeMessage() {
        switch(rand() % 4) {
            case (0):
                cout << "   No. Please try again. ";
                break;
            case (1):
                cout << "   Wrong. Try once more. ";
                break;
            case (2):
                cout << "   Don't give up! ";
                break;
            default:
                cout << "   No. Keep trying. ";
                break;
        }
    } // end printNegativeMessage()
    
private:
    
    // Determine operand
    int generateOperand() {
        if (difficulty == 1) {
            return rand() % 10;
        } else if (difficulty == 2) {
            return rand() % 100;
        } else if (difficulty == 3) {
            return rand() % 1000;
        } else if (difficulty == 4) {
            return rand() % 10000;
        } else {
            return rand() % 100000;
        }
    } // end generateOperand()

    int studentAnswer;
    
    int firstOperand;
    int secondOperand;
    int currentOperation;
    
    int answerCount;
    int correctCount;
    
    int difficulty;
    int operation;
};

int main() {
    srand((unsigned int) time(NULL));
        
    // Create quiz object
    Quiz quiz1;
    
    // Pass control to class objet
    quiz1.startQuiz();

} // end main
