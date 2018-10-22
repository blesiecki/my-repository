#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED

#include "useful.h"

void displayState(int* pListOfNumbers,  int  positionOfCursor, int number_of_digits, int numberOfGoes);

int initialiseArray(int** pListOfNumbers, int initialNumber);


char get_command();
void processCommand(int* pList, int size, int* pPositionOfCursor, char command, int* pNumberOfGoes);
boolean is_palindrome(int* plist_of_numbers, int size);

void setCursorRandom(int* pPosOfCursor, int min, int max);
void moveCursorRight ( int* pPosOfCursor, int max, int* pNumberOfGoes);
void moveCursorLeft(int* pPosOfCursor, int min, int* pNumberOfGoes);

void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor, int* pNumberOfGoes);
void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor, int* pNumberOfGoes);


#endif // PAL_H_INCLUDED
