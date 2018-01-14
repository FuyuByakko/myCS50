#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define PASSWORDCOUNT 1 // sub for the position of the KEY in the comand line arguments (assume key is the last argument typed)
#define LETTERCOUNT 26 // using english alphabet letters to check shift values etc

//declare the functions used
//get the input for plain text and check it is not a null value
string get_text(void);
int checkKey(int argc, string argv);
//get the intereger value from 0 to 26 for each letter for both the key and the plain text
int getChar_value(char letter);
//based on coded char value and upper/lower check, return the actual encrypted character
char getCodeChar(int CharValue, bool upper);

int main(int argc, string argv[])
{
    // check if the provided Com. line arguments are valid as KEY, return 0 - ok, 1 - invalid key
    int keycheck = checkKey(argc, argv[PASSWORDCOUNT]);

    //check the return from the key check. In case of 0 - continue, in case return is 1 or any other error - stop execution
    switch (keycheck)
    {
        case (0):
            //Prompt user for plain text input. check the text is valid and return is proper.
            printf("plaintext: ");
            string plainText = get_text();

            //initialize a key position value, which shows which letter of the key is used. starting with 1st letter 0th position
            int keyPos = 0;
            //remember the KEY
            string key =  argv[PASSWORDCOUNT];

            //prepare for printing out the cyphertext
            printf("ciphertext: ");
            //iterate through each letter/symbol of the plain text
            for (int i = 0, n = strlen(plainText); i < n; i++)
            {
                //check if the i-th element is an alphabet letter
                if (isalpha(plainText[i]))
                {
                    //if it is, get its integer ALPHABETICAL values for each character: A/a=0, B/b=1... Z/z=26
                    int plainChartoInt = getChar_value(plainText[i]);
                    //set a boolcheck if letter is uppper or not for text(key case can be ignored) for
                    bool upper;
                    if (isupper(plainText[i]))
                    {
                        upper = true;
                    }
                    else
                    {
                        upper = false;
                    }

                    //get the alphabetical numerical value (SHIFT value) for key (uppercase/lowercase does not mater for key, so no bool check)
                    int keyChartoInt = getChar_value(key[keyPos]);
                    //eprintf("using %c as key, switch value of %i!\n", key[keyPos], keyChartoInt);

                    //get the encrypted character alphabetical value. Make sure to wrap around the alhabet (LETTERCOUNT total)
                    int encryptedCharValue = (plainChartoInt + keyChartoInt) % LETTERCOUNT;

                    //accounting for the Upper/Lower case check, get the CHARACTER for the encrypted alphabetical value.
                    char codedChar = getCodeChar(encryptedCharValue, upper);

                    //eprintf("used character %c, with key %c. Encrypted char is %c.\n", plainText[i], key[keyPos], codedChar);

                    //print out the encrypted character value
                    printf("%c", codedChar);

                    //since key was used, for next iteration, switch position of the current keymarker
                    keyPos++;
                    //loop key on itself so once it iterates through the whole length, it goes back to start of key word
                    keyPos %= strlen(argv[PASSWORDCOUNT]);
                }
                //if value is NOT alphabetic, print the i-th symbol as is without encoding. key untouched
                else
                {
                    printf("%c", plainText[i]);
                }
            }
            printf("\n");
            return 0;
        default:
            //if keycheck was unsuccessful, return error and terminate
            printf("Bad input. Try again\n");
            return 1;

    }
}


int checkKey(int argc, string argv)
{
    //check if total amount of comand line arguments is valid (name + key as last argument
    if (argc != PASSWORDCOUNT + 1)
    {
        printf("Please check you input! NUmber of arguments invalid!\n");
        return 1;
    }
    else
    {
        //check that each value of the KEY is alphabetic
        for (int i = 0, n = strlen(argv); i < n; i++)
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
        //return 0 if check ends succesffully
        return 0;
    }
}

//gets the text input and ensures that the return was a valid string
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
    while (plainText == NULL);
    return plainText;
}

//gets the alphabetical value of the character from the ASCII value (A/a = 0, B/b = 1, etc)
int getChar_value(char letter)
{
    if (isupper(letter))
    {
        return letter - 'A';
    }
    else
    {
        return letter - 'a';
    }
}

//gives the encrypted character from its ASCII value, based on its alphabetical value and uppercase/lowercase status
char getCodeChar(int charValue, bool upper)
{
    if (upper == true)
    {
        return charValue + 'A';
    }
    else
    {
        return charValue + 'a';
    }
}
