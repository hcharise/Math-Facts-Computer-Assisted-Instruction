/*
Hannah Ashton

Professor Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++

Syracuse University
HW #4 - Exercises 6.57 - 6.61 pg 281-282
2/20/2024
 
This program is an example of computer-assisted instruction to quiz students about basic arithmetic. The student (user) is given the option of operation (+, -, *, /, or mixed) and of difficulty (max number of digits), and then is asked 10 questions of their chosen operation and difficulty. The program checks the student's answer after each question and displays a message to let the student know if they were correct. If the student was not correct, they must try again on that question until it is correct (or until they have answered a total of 10 times). The program then prints the student's score as a percentage and repeats for a new user.
 
 
Main.CPP

*/

#include "Quiz.h" // Includes interface of Quiz class

// Test program for Quiz class
int main() {
        
    // Create quiz object
    Quiz quiz1;
    
    // Pass control to quiz's startQuiz function, which displays and grades the quiz
    quiz1.startQuiz();

} // end main
