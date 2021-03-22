/*
 * Author: Joseph Bidinger
 *
 * This program runs a loop where the user can enter an integer.
 * Each time the user enters an integer, the program will output 
 * "Mustang" to the screen if the integer is divisible by 3, "Bronco"
 * if the integer is divisible by 5, and "MustangBronco" if the integer
 * is divisible by both 3 and 5. If the integer is divisible by neither, 
 * the program will just display the number entered by the user. To exit 
 * the program, the user can enter the value -1, or hit enter without any
 * input value.
 */

#include<stdio.h>
#include<stdlib.h>

/* Constants */
#define EXIT_CODE -1
#define EXIT_MESSAGE "\nThank you for using the MustangBronco GUI!\n"
#define DEFAULT_PROMPT "Please enter an integer: "


/* Function Prototypes */
static int getUserInput(char prompt[]);
static void mustangBronco();

int main(){
	/* Run the Mustang Bronco GUI loop */
	mustangBronco();
	return 0;
}

/*
 * This function will return an integer entered by the user.
 */
static int getUserInput(char prompt[]){
	char input_buffer[256];
	int input = -1;
	/* Give the user instructions on what to enter */
	printf("\n%s", prompt);
	/* Read the input from the terminal */
	fgets(input_buffer, 256, stdin);
	/* Store the value entered by the user in the address of the variable 'input' */
	sscanf(input_buffer, "%d", &input);
	return input;
}

/*
 * This function is the Mustang Bronco GUI.
 */
static void mustangBronco(){
	int user_input = 0;
	printf("Hello! Welcome to the MustantBronco GUI.\nYou can enter an integer to play the game. To exit, please enter %d, or simply hit enter with no input.\n", EXIT_CODE);
	
	/* Run the Mustang Bronco Loop */
	while(user_input != EXIT_CODE){
		/* Read in the value from the user */
		user_input = getUserInput(DEFAULT_PROMPT);
		
		if((user_input % 3 != 0) && (user_input % 5 != 0)){
			if(user_input != EXIT_CODE){
				printf("%d", user_input);	
			}
		}
		else{
			if(user_input % 3 == 0){
				printf("Mustang");
			}
			if(user_input % 5 == 0){
				printf("Bronco");
			} 
		}
	}
	
	printf(EXIT_MESSAGE);	
}