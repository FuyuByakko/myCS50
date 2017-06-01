#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define PASSWORDCOUNT 1
#define LETTERCOUNT 26

//declare the functions used 
//get the input for plain text and check it is not a null value
string get_text(void);
//print out the upper case intiails. function with no return
int checkKey(int argc, string argv);
//get the intereger value from 0 to 26 for each letter for both the key and the plain text
char getChar_value(char letter);
char getCodeChar(int shiftChar, bool upper);

int main(int argc, string argv[])
{
    int keycheck = checkKey(argc, argv[PASSWORDCOUNT]);
    switch(keycheck)
    {
        case (0): 
        {
            printf("Please input message:");
            plainText=get_text();
            
            //initialize a key position value, which shows which letter of the key is used
            int keyPos =0;
            //iterate through each letter/symbol of the text
            for (int i=0,n=strlen(plaintext);i<n;i++)
            {
                //check if the i-th element is an alphabet letter
                //if it is, get its get the integer values for each character: A=0, B=1... Z=26. do same for key
                if isalpha(plainText[i])
                {
                    //set a boolcheck if letter is uppper or not for text(key case can be ignored) for 
                    if isupper
                    {
                        bool upper=true;
                    }
                    else
                    {
                        bool upper=false;
                    }
                    //loop key on itself so once it iterates through the whole length, it goes back to start of key word
                    keyPos=keyPos%strlen(argv[PASSWORDCOUNT]);
                    
                    int shiftChar = (getchar_value(plainttext[i])+getchar_value(argv[PASSWORDCOUNT][keyPos]))%LETTERCOUNT
                    
                    //retrieve the actual coded char based on the in value+key shift
                    char codedChar = getCodeChar(shiftChar, upper);
                    printf(codedChar);
                    //since jth key was used, for next iteration, j+1should be ised
                    keyPos++;
                }
                else //just print the i-th symbol as is without encoding. key untouched
                {
                    printf(plainText[i]);
                }
            }
            
            return 0;
        }
        case (1): 
        {
            printf("Bad input. Try again\n");
            return 1;
        }
    }
}


char getCodeChar(int shiftChar, bool upper);

int getChar_value(char letter)
{
    if isupper(letter)
    {
        return letter-65;
    }
    else
    {
        return letter-97;
    }
}

string get_text(void)
{
    //initialize a variable, and get the input from the user
    string plainText;
    do
    {
        plainText = get_string();
    }
    //keep asking for the input until a nonNull value is returned from the get_string.
    //done under assumption that its a simple text input with no numbers or special symbols as per task
    while (plainText==NULL);
    return plainText;
}

int checkKey(int argc, string argv)
{
    if (argc!=PASSWORDCOUNT+1) 
    {
        printf("Please check you input!\n argc=%i\n",argc);
        return 1;
    }
    else
    {
        printf("%s\n",argv);
        for (int i=0, n=strlen(argv); i<n; i++)
        {
            if (isalpha(argv[i]))
                {
                    continue;
                }
            else
                {
                    printf("key contains non-Aphabet characters!\n");
                    return 1;
                }
        }
        return 0;
    }
}
