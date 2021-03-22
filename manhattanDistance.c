/*
 * Author: Joseph Bidinger
 *
 * This program returns the Manhattan distance between two points
 * entered by the user. The user entries must be of the form (x, y)
 * including parenthesis, where x and y are integers.
 */

#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
static int* getUserInput(char prompt[]);
static int absoluteValue(int x);
static int manhattanDistance(int* A, int *B);

int main(){
	printf("To use this program, enter points of the form (x, y), including parenthesis, where x and y are integers\n");
	
	/* Get the points (a, b) and (c, d) from the user */
	int* pointA = getUserInput("Please enter point A: ");
	int* pointB = getUserInput("Please enter point B: ");
	
	/* compute the Manhattan distance between (a, b) and (c, d) */
	int distance = manhattanDistance(pointA, pointB);
	printf("The Manhattan distance between (%d, %d) and (%d, %d) is %d\n", pointA[0], pointA[1], pointB[0], pointB[1], distance);
	
	/* Free the memory allocated for the points */
	if(pointA != NULL){
		free(pointA);
	}
	if(pointB != NULL){
		free(pointB);
	}
	return 0;
}

/*
 * This function returns a pointer to an int array which will contain
 * two integers entered by the user. If the user enters (x, y), then
 * the function will return a pointer to the array [x, y].
 */
static int* getUserInput(char prompt[]){
	char input_buffer[256];
	int* input = malloc(2*sizeof(int));
	/* Check to make sure the memory allocation was successful */
	if(input == NULL){
		printf("System error: unable to allocate memory\n");
		exit(1); /* Malloc failed, so terminate the program */
	}
	/* Give the user instructions on what to enter */
	printf("\n%s", prompt);
	/* Read the input from the terminal */
	fgets(input_buffer, 256, stdin);
	/* Store the value entered by the user in the array */
	sscanf(input_buffer, "(%d,%d)", &input[0], &input[1]);
	return input;
}
 
/* 
 * This function returns the absolute value of an integer.
 */
static int absoluteValue(int x){
	if(x < 0){
		x *= -1;
	}
	return x;
}

/* 
 * This function computes the Manhattan distance between 
 * two points A, B, where A = (a1, a2) and B = (b1, b2).
 * The Manhattan distance between these points is simply the
 * distance between the x coordinates for A and B, plus the
 * distance between the y coordinates for A and B.
 */
static int manhattanDistance(int* A, int *B){
	int x = absoluteValue(A[0] - B[0]);
	int y = absoluteValue(A[1] - B[1]);
	return x + y;
}