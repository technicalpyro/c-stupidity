#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <Windows.h>				// required for clear screen ("cls") command
#include <conio.h>
#include <string.h>					// required for fgets command
#include <math.h>
#include <stdbool.h>

/*******************************************************************************
Lab 08 A input and validation
********************************************************************************
Developed by: Sean Booth
Date: Mar 18, 2021
********************************************************************************
Description:This program will eventually take a given set of cards and inform
the user what kind of poker hand they have.
*******************************************************************************/

// function prototypes://
void purpose(void);
void getCard(int[2][5]);
int isValid(int card, int suit);
int isDuplicated(int[2][5], int nELEM, int);
void swap(int[2][5]);
void sort(int[2][5]);

/*******************************************************************************
main
*******************************************************************************/
void main(void)
{
	int hand[2][5];

	purpose();
	getCard(hand);
	swap(hand);
	sort(hand);

	while (!_kbhit());
}
/*******************************************************************************
purpose - This function prints the purpose of the program to the console.
Inputs: none
Returned: none
*******************************************************************************/
void purpose(void)
{

}
/*******************************************************************************
getCard : This function asks the user 5 times for a card and suit
cards are 1-13 and suits ar 1-4 in alphabetical order
Inputs:	user inputting card values
Returned: none pointers are used to fill the array
*******************************************************************************/
void getCard(int hand[2][5])
{
	int i, validFlag, isDupe;
	for (i = 0; i < 5; i++)
	{
		printf("Please enter the numerical value (1-13) of card number %i: ", i + 1);
		scanf("%i", &hand[0][i]);
		printf("Please enter the suit of card number %i ", i + 1);
		printf("\nREMINDER 1 for Clubs 2 for Diamonds 3 for Hearts 4 for Spades: ");
		scanf("%i", &hand[1][i]);
		validFlag = isValid(hand[0][i], hand[1][i]);
		if (validFlag == 0)
		{
			i--;
		}
		isDupe = isDuplicated(hand, i + 1, 1);
		if (isDupe == 0)
		{
			i--;
		}
	}
}
/*******************************************************************************
Validate - this function will validates that the card entered is within the
range and has a appropriate suit
Inputs:	card values and suit values
Returned: status
*******************************************************************************/
int isValid(int card, int suit)
{
	int flag = 1;
	if (card > 13 || card < 1) flag = 0;
	if (suit > 4 || suit < 1) flag = 0;
	return flag;
}

/*******************************************************************************
Duplicate: this function checks if the card is duplicated in the array making
the new entry invalid
Inputs:	hand array,
		nElem - the number of the element for the recursive duplicate check
Returned: status
*******************************************************************************/
int isDuplicated(int hand[2][5], int nElem, int flag)
{
	for (int i = 0; i < nElem - 1 && flag == 1; i++)
		if ((hand[0][i] == hand[0][nElem - 1])
			&& (hand[1][i] == hand[1][nElem - 1]))
			flag = 0;

	if (flag != 0 && nElem != 0 && nElem != 1)
		flag = isDuplicated(hand, nElem - 1, flag);
	return flag;
}
/*******************************************************************************
swap: this function changes aces into 14's for the sorting array
Inputs:	hand array,
Returned: array with corrected values
*******************************************************************************/
void swap(int hand[2][5])
{
	for (int i = 0; i < 5; i++)
	{
		if (hand[0][i] == 1)
			hand[0][i] = 14;
	}
}

/*******************************************************************************
sort: this function sorts the array in order to make reading the cards and
determining what you have easier
Inputs:	hand array,
Returned: sorted hand
*******************************************************************************/
void sort(int hand[2][5])
{
	int i, j, tc, ts;

	for (i = 0; i < 4 - 1; i++) {
		for (j = 0; j < 4 - i - 1; j++) {
			if (hand[0][j] > hand[0][j + 1]) {
				/* Swapping */
				tc = hand[0][j];
				ts = hand[1][j];
				hand[0][j] = hand[0][j + 1];
				hand[1][j] = hand[1][j + 1];
				hand[0][j + 1] = tc;
				hand[1][j + 1] = ts;

			}
		}
	}
}