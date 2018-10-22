#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pal.h"


void start_game(int initialNumber)
{
    int* listOfNumbers = 0;
    int positionOfCursor = 0;
    int numberOfGoes = 0;
    int number_of_digits = initialiseArray(&listOfNumbers, initialNumber);

    setCursorRandom(&positionOfCursor, 0, number_of_digits - 1);
    displayState(listOfNumbers, positionOfCursor, number_of_digits, numberOfGoes);

    while(is_palindrome(listOfNumbers, number_of_digits) != True)
    {
        char command = get_command();
        processCommand(listOfNumbers, number_of_digits, &positionOfCursor, command, &numberOfGoes);
        displayState(listOfNumbers, positionOfCursor, number_of_digits, numberOfGoes);
        is_palindrome(listOfNumbers, number_of_digits);
    }

    printf("The number is a palindrome, you win!!!\nNumber of goes: %d\n", numberOfGoes);
    free(listOfNumbers);

}

int main(int argc, char **argv)
{
    srand(time(0));
    int random = rand() % (9999999 + 1 - 0);
    random = rand() % (9999999 + 1 - 0);
   // int initialNumber = 123671;
    start_game(random);
    return 0;

}



