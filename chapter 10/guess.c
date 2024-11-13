/* Asks user to guess a hidden number */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10

/* external variable */
int secret_number;

/* prototypes */
void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(void){
    char command;
    printf("Guess the secret number between 1 and %d\n\n", MAX_NUMBER);
    initialize_number_generator();

    do {
        choose_new_secret_number();
        printf("A new secret number has been chosen\n");
        read_guesses();
        printf("Play again? (Y/N)");
        scanf("%c", &command);
    }   while (command == 'Y');
}

/* initialize_number_generator: Initialize the random number generator using the time of the day*/
initialize_number_generator(void){
    srand((unsigned) time(NULL));
}

/* choose_new_secret_number: randomly selects a number between 1 and MAX_NUMBER and stores it in secret number*/
choose_new_secret_number(void){
    secret_number = rand() % MAX_NUMBER + 1;
}

/* read_guesses: Repeatedly reads user guesses and tells the user whether each guess is to high or too low*/
read_guesses(void){
    int guess, num_guesses = 0;

    for(;;){
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secret_number){
            printf("You won in %d guesses\n", num_guesses);
            return;
        } else if (guess > secret_number){
            printf("Too high, try again\n");
        }
        else
            printf("Too low, try again\n");
    }
}
