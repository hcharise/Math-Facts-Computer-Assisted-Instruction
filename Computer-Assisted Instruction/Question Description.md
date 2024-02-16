# Computer-Assisted Instruction
## Problem Description

 6.57 - 6.61 pg 281-282
 
 Write a program that uses the rand function to product two positive one-digit integers. The program should then prompt the user with a question, such as "How much is 6 times 7?". The student then inputs the answer. Next, the program checks the student's answer. If it's correct, display the message "Very good!" and ask another multiplication question. If the answer is wrong, display the message "No. Please try again." and let the student try the same question repeatedly until the student finally gets it right. A separate function should be used to generate eeach new question. This function should be called once when the applciation begins execution and each time the user answers the question correctly.
 
 Modify the program so that various comments are displayed for each ansewr as follows:
 Possible responses to a correct answer: Very good! Excellent! Nice work! Keep up the good work!
 Possible reponses to an incorrect answer: No. Please try again. Wrong. Try once more. Don't give up! No. Keep trying.
 Use random number generation to choose a number from 1 to 4 that will be used to select one of the four appropriate responses to each correct or incorrect answer. Use a switch statement to issue the responses.
 
 Modify the program to count the number of correect and incorrect responses typed by the student. After the student types 10 answers, your program should calculate the percentage that are correct. If the percentage is lower than 75%, display "Please ask your teacher for extra help.", then reset the program so another student can try it. If the percentage is 75% or higher, display "Congratulations, you are ready to go to the next level!", then reset the program so another student can try it.
 
 Modify the program to allow the user to enter a difficulty level. At a difficulty level of 1, the program should use only single-digit numbers in the problems; at a difficulty level of 2, numbers as large as two digits, and so on.
 
 Modify the program to allow the user to pick a type of arithmetic problem to study. An option of 1 means addition problems only, 2 means subtraction problems only, 3 means multiplication only, 4 means division problems only, and 5 means a random mixture of all these types.
 
 */
