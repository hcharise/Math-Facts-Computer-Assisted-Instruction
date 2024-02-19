/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
HW #4 - Exercises 6.57 - 6.61 pg 281-282
2/20/2024
 
This program is an example of computer-assisted instruction to quiz students about basic arithmetic. The student (user) is given the option of operation (+, -, *, /, or mixed) and of difficulty (max number of digits), and then is asked 10 questions of their chosen operation and difficulty. The program checks the student's answer after each question and displays a message to let the student know if they were correct. If the student was not correct, they must try again on that question until it is correct (or until they have answered a total of 10 times). The program then prints the student's score as a percentage and repeats for a new user.
 
 
Quiz.CPP

*/

#include <iostream> // Included for printing to and receiving from user
#include <cstdlib> // Includes srand() and rand() functions
#include "Quiz.h" // Includes interface of Quiz object (implementation included here in .cpp)

using std::cout; // Used for printing messages to user
using std::cin; // Used for getting input from user

// PUBLIC MEMBER FUNCTIONS
// -----------------------
// CONSRTUCTOR
// Creates object of type class, nothing initialized (done inside startQuiz)
Quiz::Quiz () {
    // empty body
} // end constructor

// Primary control over quiz
// Calls all other functions to display and grade each student's quiz
void Quiz::startQuiz() {
    
    // Seed rand() function for use generating operands and choosing feedback messages
    srand((unsigned int) time(NULL));

    printIntroBanner(); // Displays intro banner to user, welcoming them to math quiz
    printOperationMenu(); // Displays menu and gets user's input for operation

    // Loop for each user/student, until operation = -1 (then exits)
    while (operation != -1) {
        printDifficultyMenu(); // Displays menu and gets user's input for difficulty
        
        cout << "\nLet's get started!\n\n";

        // Initializes/resets question counts in case another student already went
        answerCount = 0;
        correctCount = 0;
        
        // Loop for up to 10 questions per student
        while (answerCount < 10) {
            
            printQuestion(); // Generate and display question
            cin >> studentAnswer; // Get user's answer and store in private data member
            answerCount++; // Increment number of times student answers (max 10)
            checkQuestion(); // Compares student's answer to correct answer, prints feedback
                        
        } // end each user's 10 questions
        
        calculateScore(); // Determines and displays the student's % with feedback
        
        // End of current user
        cout << "\n----------------------------------------------\n\n";
        // Start of new user
        
        // Reprompt new user for operation to return to start of outer while loop
        printOperationMenu();
    
    } // end loop (all students completed quiz)
} // end startQuiz()

// PRIVATE MEMBER FUNCTIONS
// ------------------------

// Displays welcome to the program
void Quiz::printIntroBanner() {
    cout << "----------------------------------------------\n"
        << "                 Ms. Ashton's                 \n"
        << "              Math Fact Practice              \n"
        << "----------------------------------------------\n\n";
} // end printIntroBanner()

// Displays the options for operation, gets and validate's users input
void Quiz::printOperationMenu() {
    
    // Display options for operation
    cout << "Welcome, student!\n\n"
        << "What operation are you practicing today?\n"
        << "    1: Addition\n"
        << "    2: Subtraction (answers may be negative)\n"
        << "    3: Multiplication\n"
        << "    4: Division (rounded to nearest whole)\n"
        << "    5: All Operations\n"
        << "    Or enter -1 to exit.\n"
        << "Operation: ";
    
    // Gets user's input
    cin >> operation;
    
    // Validates user's input to be -1 or 1 to 5; defaults to 1 if invalid
    if ((operation > 5 || operation < 1) && (operation != -1)) {
        cout << "Invalid operation. Defaulting to addition.\n";
        operation = 1;
    }
    
    cout << "\n";
    
} // end printOperationMenu()

// Displays the options for difficulty, gets and validate's users input
void Quiz::printDifficultyMenu() {
    
    // Display options for difficulty
    cout << "What difficulty level is right for you?\n"
    << "    1: Up to One-Digit Numbers\n"
    << "    2: Up to Two-Digit Numbers\n"
    << "    3: Up to Three-Digit Numbers\n"
    << "    4: Up to Four-Digit Numbers\n"
    << "    5: Up to Five-Digit Numbers\n"
    << "Difficulty: ";
    
    // Gets user's input
    cin >> difficulty;
    
    // Validate's user's input to be 1 to 5; defaults to 1 if invalid
    if (difficulty > 5 || difficulty < 1) {
        cout << "Invalid difficulty. Defaulting to one-digit numbers.\n";
        difficulty = 1;
    }
    
} // end printDifficultyMenu()

// Chooses random value for each operand based on difficulty level
int Quiz::generateOperand() {
    
    if (difficulty == 1) {
        return rand() % 10; // up to 1 digit numbers
    } else if (difficulty == 2) {
        return rand() % 100; // up to 2 digit numbers
    } else if (difficulty == 3) {
        return rand() % 1000; // up to 3 digit numbers
    } else if (difficulty == 4) {
        return rand() % 10000; // up to 4 digit numbers
    } else {
        return rand() % 100000; // up to 5 digit numbers
    }
} // end generateOperand()

// Prints question, using generateOperand() for values and switch for operation
void Quiz::printQuestion() {
    
    // Gets random numbers for operands based on difficulty (# of digits)
    firstOperand = generateOperand();
    secondOperand = generateOperand();
    
    // If user chose op = "5: mixed", choose random "current operation" for question (1 to 4)
    if (operation == 5) {
        currentOperation = (rand() % 4) + 1;
    } else {
        currentOperation = operation; // Otherwise, use user-inputted operation
    }
    
    // Print question start and first value
    cout << "What is " << firstOperand;
    
    // Print operation using switch statement on currentOperation (1 to 4)
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
    
    // Print second value and rest of question
    cout << secondOperand << "? ";
    
} // end printQuestion()

// After taking in user's answer, check to see if it is true or false
bool Quiz::checkAnswer() {
    
    // Uses switch on current operation (1 to 4) from question to calculate correct answer
    // If correct answer matches student's answer, return true
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
            // Division rounds to the nearest whole number (.5 and higher rounds up)
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

// Facilitates checking answer and printing appropriate feedback messages
void Quiz::checkQuestion() {
    
    // Check if answer is correct and if student has hit max number of answers (10)
    while (checkAnswer() == false && answerCount <= 10) {
        // If student hasn't hit max number of answers
        if (answerCount < 10) {
            printNegativeMessage(); // Provide feedback that answer is wrong
            cin >> studentAnswer; // Get user's new input
            answerCount++; // Increment number of times student has answered
        } else { // Student has already answered 10 times
            // Error message for final question (not prompting for new response)
            cout << "   Still not quite.\n";
            break;
        }
        
    }
    
    // If student answered correctly
    if (checkAnswer() == true) {
        printPositiveMessage(); // Provide feedback that answer is correct
        correctCount++; // Increment number of correct answers
    }
    
} // end checkQuestion()

// Displays random feedback when student answers correctly
void Quiz::printPositiveMessage() {
    
    // Switch on random number 0-3 to choose random statement
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

// Displays random feedback when student answers incorrectly
void Quiz::printNegativeMessage() {
    
    // Switch on random number 0-3 to choose random statement
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

// Determines and display's user's final score with feeedback note
void Quiz::calculateScore() {
    
    // Determine and display score as percentage
    cout << "\nYour final score is " << (correctCount * 100 / answerCount) << "%.\n";
    
    // If user scored under 75%, go to teacher
    if (((float)correctCount / answerCount) < 0.75) {
        cout << "Please ask your teacher for extra help.\n";
    } else { // Otherwise, try next level
        cout << "Congratulations, you are ready to go to the next level!\n";
    }
} // end calculateScore()
