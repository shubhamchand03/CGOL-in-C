/*
 ============================================================================
 Name        : 180022_CGOL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Header files
#include <stdio.h>
#include <stdlib.h>

// Globally defined function and arrays
void next(int a[6][6]);
int a[6][6];
int a1[6][6];

// Main method
int main(void) {
	setbuf(stdout, NULL);
	int i, j;
	char ch;
	printf("Enter initial condition for CGOL 6x6");
	printf("\n0 is for dead cell and 1 is for live cell \nFirst generation: ");

	// To take input in array by user
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// Loop is used to ask user for display of next generation
	do {
		next(a);
		printf("\nEnter y for next generation or n for quit: ");
		scanf(" %c", &ch);
	} while (ch == 'y');

	printf("\n Thank you, Exit!");

	return EXIT_SUCCESS;
}
// 'next' function is created for generating new generation
void next(int a[6][6]) {
	int i, j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			a1[i][j] = 0;
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			int alive = 0, l, w;
			for (l = -1; l <= 1; l++) {
				for (w = -1; w <= 1; w++) {
					alive = alive + a[i + l][j + w];
				}
			}
			alive = alive - a[i][j];

			// Rules of CGOl is implemented below
			if (a[i][j] == 1 && alive < 2)
				a1[i][j] = 0;
			else if (a[i][j] == 1 && alive > 3)
				a1[i][j] = 0;
			else if (a[i][j] == 0 && alive == 3)
				a1[i][j] = 1;
			else
				a1[i][j] = a[i][j];
		}
	}
	// Print the next generation
	printf("\nNext Generation: \n");
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			printf("%d ", a1[i][j]);
		}
		printf("\n");
	}
	//Assigning all the elements of next generation array to the previous original array
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			a[i][j] = a1[i][j];
		}
	}
}

