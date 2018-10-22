#include "pal.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayState(int* pListOfNumbers,  int  positionOfCursor, int number_of_digits, int numberOfGoes)
{
    printf("------ Game State ------\n\n");

    printf("< ");
    for(int i=0; i < number_of_digits; i++)
    {
    printf("%d",  pListOfNumbers[i]);
    }
    printf(" >\n");

    printf("  ");
	for(int i = 0; i < number_of_digits; i++)
	{
		if (i == positionOfCursor)
		{
			printf("^\n");
			break;
		}
		else
		{
			printf(" ");
		}
	}
	printf("Goes: %d\n", numberOfGoes);

    printf("\n------------------------\n");

}

int initialiseArray(int** pListOfNumbers, int initialNumber)
{
    int initialNumberCopy = initialNumber;
	int digits;
	for (digits = 1; initialNumberCopy /= 10; digits++);

	*pListOfNumbers = malloc(digits * sizeof(int));

	for (int i = 0; i < digits; i++)
	{
		int divisor = (int)pow(10, digits - i - 1);
		int cur_digit = initialNumber / divisor;
		initialNumber = initialNumber - (divisor * cur_digit);

		(*pListOfNumbers)[i] = cur_digit;
	}

	return digits;
}

char get_command()
{
	 char  validCharacters[] = {'a','d', 'w', 'x'};

	 while(True)
     {
         printf("Enter a valid command by keyword(");
         for(int i=0; i < sizeof(validCharacters); i++)
         {
             printf(" %c", validCharacters[i]);
         }
         printf(" ): ");

         char input = my_get_char();
         for(int i=0; i < sizeof(validCharacters); i++)
         {
             if(input == validCharacters[i])
             {
                 return input;
             }
         }
     }
}

void processCommand(int* pList, int size, int* pPositionOfCursor, char command, int* pNumberOfGoes)
{
    if(command == 'a')
    {
        moveCursorLeft(pPositionOfCursor, 0, pNumberOfGoes);
    }
    else if(command == 'd')
    {
        moveCursorRight(pPositionOfCursor, size-1, pNumberOfGoes);
    }
    else if(command == 'w')
    {
        incrementDigitInListAtPos(pList, *pPositionOfCursor, pNumberOfGoes);
    }
    else if(command == 'x')
    {
        decrementDigitInListAtPos(pList, *pPositionOfCursor, pNumberOfGoes);
    }
}

void setCursorRandom(int* pPosOfCursor, int min, int max)
{
	*pPosOfCursor = rand() % (max + 1 - min) + min;
}

void moveCursorRight( int* pPosOfCursor, int max, int* pNumberOfGoes)
{
	(*pPosOfCursor)++;
	if (*pPosOfCursor > max)
	{
		*pPosOfCursor = max;
	}
	else
	{
		(*pNumberOfGoes)++;
	}
}

void moveCursorLeft( int* pPosOfCursor, int min, int* pNumberOfGoes)
{
	(*pPosOfCursor)--;
	if (*pPosOfCursor < min)
	{
		*pPosOfCursor = min;
	}
	else
	{
		(*pNumberOfGoes)++;
	}
}

void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor, int* pNumberOfGoes)
{
	pListOfNumbers[positionOfCursor]++;
	if (pListOfNumbers[positionOfCursor] > 9)
	{
		pListOfNumbers[positionOfCursor] = 0;
	}
	(*pNumberOfGoes)++;
}

void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor, int* pNumberOfGoes)
{
	pListOfNumbers[positionOfCursor]--;
	if (pListOfNumbers[positionOfCursor] < 0)
	{
		pListOfNumbers[positionOfCursor] = 9;
	}
	(*pNumberOfGoes)++;

}

boolean is_palindrome(int* plist_of_numbers, int size)
{

	for (int i = 0; i < size / 2; i++)
	{
		if (plist_of_numbers[i] != plist_of_numbers[size - i - 1])
        {
            return False;
        }
	}
	return True;
}




