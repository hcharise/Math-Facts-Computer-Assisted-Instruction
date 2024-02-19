/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
HW #4 - Exercises 6.57 - 6.61 pg 281-282
2/20/2024
 
This program is an example of computer-assisted instruction to quiz students about basic arithmetic. The student (user) is given the option of operation (+, -, *, /, or mixed) and of difficulty (max number of digits), and then is asked 10 questions of their chosen operation and difficulty. The program checks the student's answer after each question and displays a message to let the student know if they were correct. If the student was not correct, they must try again on that question until it is correct (or until they have answered a total of 10 times). The program then prints the student's score as a percentage and repeats for a new user.
 
 
Quiz.H

*/

// Include Guard
#ifndef QUIZ_H
#define QUIZ_H

// Declaration of class Quiz
class Quiz {
public:
    // CONSRTUCTOR
    // Creates an object of type Quiz, no data members initialized
    Quiz ();
    
    // Executes majority of program, calling other functions to display and grade each quiz
    void startQuiz();
    
private:
    
    // Displays initial message to user that quiz program is starting
    void printIntroBanner();
    
    // Displays menu and gets and validates user's input for the operation
    void printOperationMenu();
    
    // Displays menu and gets and validates user's input for the difficulty level
    void printDifficultyMenu();
    
    // Chooses random number for operand using difficulty to determine number of digits
    int generateOperand();
    
    // Displays question to the user from generated operands (ex. What is 1 + 4?)
    void printQuestion();
    
    // Returns boolean indicating if user answered correctly or not
    bool checkAnswer();
    
    // Calls checkAnswer, calls appropriate feedback and reprompts user if incorrect
    void checkQuestion();
        
    // Chooses 1 of 4 random positive feeedback messages to display when correct
    void printPositiveMessage();
    
    // Chooses 1 of 4 random negative feedback messages to display when incorrect
    void printNegativeMessage();
    
    // Calculates the user's overall score and displays as percentage with ending message
    void calculateScore();

    // DATA MEMBERS
    int studentAnswer; // Holds user's input when answering a question
    
    int firstOperand; // First value to be used in current question (ex. 5 in 5 + 3)
    int secondOperand; // Second value to be used in current question (ex. 3 in 5 + 3)
    int currentOperation; // Operation for current question (necessary is operation is mixed)
    
    int answerCount; // Number of answers for current user total (correct and incorrect)
    int correctCount; // Number of answers for current user that have been correct
    
    int difficulty; // Holds user's input of desired difficulty (number of digits)
    int operation; // Holds user's input of desired operation (+, -, *, /, or mixed)
};

// End include guard
#endif
