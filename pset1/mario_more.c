#include <stdio.h>
#include <cs50.h>
/**
 * print the mario piramids of set height (non negative, <23)
 */
int  main(void)
{
    //ask for user input of desired height
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height >23); //repromt user input if height is input as negative int or heigher than 23
    
    //returns the 2 pyramids
    for (int h = 0; h<height; h++) //generates the determined number of rows
    {
        /**generate left pyramid
         * 
         * generates the spaces each row. There are (height) elements in the row.
         * starts with ONE (#) sign in line one (h=0) and remaining points in line are spaces. 
         * spaces start with (height-1) amount for h=0, and reduce by one as h increases. Done total (height) times*/
        for (int sp1 = 0; sp1<height-1-h; sp1++) 
        {
            printf(" ");
        }
        /** generates the # for each row
         * starting with one sharp symbol (sh) for h=0.
         * Increases by one each line h, so (h+1). Done a total of h times.*/ 
        for (int sh = 0; sh<h+1; sh++)     
        {
            printf("#");
        }
        
        //generates the 2 spaces between the 2
        printf("  ");
        
        //generate right pyramid. starts with 1 sharp in first row h=0. increases by for each row (h+1).
        for (int shr = 0; shr<h+1; shr++)     
        {
            printf("#");
        }
        printf("\n");
    }
}
