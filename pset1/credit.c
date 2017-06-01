#include <stdio.h>
#include <cs50.h>
/** The implemention of this task is based on the current level of information provided.
 * Meaning that there is no typecasting to string, or string indexing/slicing, as these topics are not yet covered in Week 1.
 */


//initialize a function for counting the sum of digits that are doubled
long long doublesSum(long long n);
 
int  main(void)
{
    //ask for user input of the card number
    long long cardNr;
    do
    {
        printf("Number: ");
        cardNr = get_long_long();
    }
    while (cardNr < 0); //repromt user input if height is input as negative int or heigher than 23
    
    /** WE assume that the first number will be a NON zero
     * we will start the calucation of the sum of each second integer starting from last (unchanged)
     * and another sum for the ints that are doubled
     * as well as a counter for the total nubmer of digits
     * 
     */
     
     long long sumReg=0; //sum for the regular integers (last, 3rd from left, 5th, etc)
     long long sumDouble=0; //sum of the elements that need to be doubled and added numbers 
     int intNum=0; //position of the integer in the number, total number of integers.
     //if intNum is 0 - last, elemnt, 1 - second from letf, 2 - 3rd from left, etc. Even elements - regular sum, ODD - doubled.
     int firstNr=0;
     int secondNr=0;
     
     for (long long i=cardNr; i>0; i/=10)
     {
         //checl if intNum is odd or even and decide to wich sum to add the element
         if (intNum%2 == 0)
         {
             //printf("add to reg %lli\n", i%10); //for checking the added number
             sumReg+=i%10; //add the last element of the number to the sum of regulars
         }
         else
         {
             sumDouble+=doublesSum(i%10); //functions returns the doubled value, or in case its a 2 digit value- the sum of its elements 
             //printf("add to double %lli\n",doublesSum(i%10)); // check the added number
         }
         //Keep track of the first2 elements of the currently checked number The number being added will always be the new First. Whereas the old first will shift to second
         secondNr = firstNr;
         firstNr = i%10;
     
         //increment the counter for postion in number(counter for total numbers once finished)
         intNum++;
     }
     //printf("number# %i, First:%i, Second:%i, sumdouble:%lli, sumReg:%lli", intNum, firstNr, secondNr, sumDouble, sumReg);
     //check the variables
     
     if ((sumReg+sumDouble)%10!=0)
     {
        printf("INVALID\n");
     }
     else
     {
         if (intNum==15 && firstNr==3 && (secondNr==4 ||secondNr==7))
         {
             printf("AMEX\n");
         }
         else if (intNum==13 && firstNr==4)
         {
             printf("VISA\n");
         }
         else if (intNum==16)
         {
             if (firstNr==4)
             {
                 printf("VISA\n");
             }
             else if (firstNr==5 && secondNr>0 && secondNr<6)
             {
                 printf("MASTERCARD\n");
             }
             else
            {
                printf("INVALID\n");
            }
         }
        else
        {
        printf("INVALID\n");
        }
     }
    
}

long long doublesSum(long long n)
{
    //double the integer. If the result is a 2digit number, sum the individual elements (mod gives singles, /10 gives tens)
    if (n*2>9)
    {
        return n*2%10 + n*2/10;
    }
    else
    {
        return n*2;
    }
}
