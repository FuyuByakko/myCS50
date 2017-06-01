#include <stdio.h>
#include <cs50.h>
/**
 * shower spits out 1.5 gallons of water per minute. 
 * A gallon is 128 ounces, so 1.5 × 128 = 192 ounces of water per minute. 
 * A typical bottle is 16 ounces. 
 * So taking a 1-minute shower is akin to using 192 ÷ 16 = 12 bottles of water
 */
int  main(void)
{
    //ask for user input of shower duration
    int minutes;
    do
    {
        printf("Minutes: ");
        minutes = get_int();
    }
    while (minutes < 0); //repromt user input if length is input as negative int
    
    //returns the number of bottles calculating 12 bottles of water per minute of showering based on task definitions.
    printf("Bottles: %i\n", minutes*12);
}
