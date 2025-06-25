#include<stdio.h> // It is a standard input-output header file in C that allows us to use functions like printf and scanf. By using this header file through #include, we're instructing the compiler to include the standard input-output library in our program, enabling us to perform input and output operations.
int number = 10; // Global variable : Global variables are declared outside of any function and can be accessed by any function in the program.

int main() // The main function is the entry point of the program. It is where the execution of the program begins. By opening the main function, we are telling the compiler that this is where the program starts and telling to check all the possible functions within stdio 
{
    printf("\n The value of the global variable number is : %d", number);
    return 0; // The return statement is used to exit the main function and return a value to the operating system. In this case, it returns 0, indicating that the program has executed successfully.
}