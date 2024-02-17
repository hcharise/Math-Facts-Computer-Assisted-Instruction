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
    Quiz ()
    : answerCount(0), correctCount(0) {
        // empty body
    } // end constructor
    
    // GETTERS
    int getOperation() {
        return operation;
    } // end getOperation()
    
    int getAnswerCount() {
        return answerCount;
    } // end getanswerCount()
    
    // SETTERS
    void setOperation(int userOperation) {
        operation = userOperation;
        if (operation > 5 || operation < 1) {
            cout << "Invalid operation. Defaulting to addition.\n";
            operation = 1;
        }
    } // end setOperation()
    
    void setDifficulty(int userDifficulty) {
        difficulty = userDifficulty;
        if (userDifficulty > 5 || userDifficulty < 1) {
            cout << "Invalid difficulty. Defaulting to one-digit numbers.\n";
            difficulty = 1;
        }
    } // end setDifficulty()
    
    void setAnswerCount(int newanswerCount) {
        answerCount = newanswerCount;
    }
    
    void setStudentAnswer(int userAnswer) {
        studentAnswer = userAnswer;
    }
        
    // Increment num total/num correct
    void incrementAnswerCount() {
        answerCount++;
    }
    
    void incrementCorrectCount() {
        correctCount++;
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
    // HOW TO HANDLE DIVISION DECIMALS???
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
                if (studentAnswer == (firstOperand / secondOperand)) {
                    return true;
                }
                break;
            default:
                cout << " INVALID OPERATION ";
                break;
        }
        // If hasn't already returned true, answer is incorrect
        return false;
    } // end checkAnswer()
    
    void checkQuestion() {
        
        // while (check answer == false && total num < 10), then
        while (checkAnswer() == false && getAnswerCount() < 10) {
            printNegativeMessage();
            cin >> studentAnswer;
            incrementAnswerCount();
            checkAnswer();
        }
        printPositiveMessage();
        incrementCorrectCount();
    } // end checkQuestion()
    
    // NEED: Caculate score
        // if (Number Correct / 10 < 75%), then print good job!
        // else print "see teaacher"
    
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
            return rand() % 10000; // NEED: IS IT OKAY THAT THESE ARE UP TO 5 DIGITS??
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

    int difficulty; // User-chosen difficulty level, ie. the number of digits
    int operation; // User-chosen operation (+, -, *, /, mix)
    int userAnswer;
    
    // Print intro banner
    cout << "----------------------------------------------\n"
        << "                 Ms. Ashton's                 \n"
        << "              Math Fact Practice              \n"
        << "----------------------------------------------\n\n";
    
    // Create quiz object
    Quiz quiz1;
    
    // Prompt user for operation
    cout << "Welcome, student!\n\n"
        << "What operation are you practicing today?\n"
        << "    1: Addition\n"
        << "    2: Subtraction\n"
        << "    3: Multiplication\n"
        << "    4: Division\n"
        << "    5: All Operations\n"
        << "    Or enter -1 to exit.\n"
        << "Operation: ";
    cin >> operation;
    cout << "\n";
    
    // Loop for each user (operation != -1?)
    while (operation != -1) {
        quiz1.setOperation(operation);
        cout << "What difficulty level is right for you?\n"
            << "    1: One-Digit Numbers\n"
            << "    2: Two-Digit Numbers\n"
            << "    3: Three-Digit Numbers\n"
            << "    4: Four-Digit Numbers\n"
            << "    5: Five-Digit Numbers\n"
            << "Difficulty: ";
        cin >> difficulty;
        quiz1.setDifficulty(difficulty);
        cout << "\nLet's get started!\n\n";

        // Resent question count
        quiz1.setAnswerCount(0);
        
        // Loop for each question (total num < 10)
        while (quiz1.getAnswerCount() < 10) {
            
            // Print question
            quiz1.printQuestion();
            // Get user's input and set in object
            cin >> userAnswer;
            quiz1.setStudentAnswer(userAnswer);
            quiz1.incrementAnswerCount();
            quiz1.checkQuestion();
            
            // NEED: Calcuate total score and print appropriate message
            
        } // end each user's 10 questions


        // Reprompt new user for operation
        cout << "\n   ----------------------------------------   \n\n"
            << "Welcome, student!\n\n"
            << "What operation are you practicing today?\n"
            << "    1: Addition\n"
            << "    2: Subtraction\n"
            << "    3: Multiplication\n"
            << "    4: Division\n"
            << "    5: All Operations\n"
            << "    Or enter -1 to exit.\n"
            << "Operation: ";
        cin >> operation;
        cout << "\n";
                    
    } // end loop (all students completed quiz)
    
} // end main
