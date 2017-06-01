#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declare the 2 functions used 
//get the input for name and check it is not a null value
string get_name(void);
//print out the upper case intiails. function with no return
void get_initials(string inits);

int main(void)
{
    //initialize a variable to store the name
    string name = get_name();
    // pass it into a function that princts out the initials
    get_initials(name);
    //start a new line after
    printf("\n");
}

string get_name(void)
{
    //initialize a variable, and get the input from the user
    string fullname;
    do
    {
        fullname = get_string();
    }
    //keep asking for the input until a nonNull value is returned from the get_string.
    //done under assumption that its a simple text input with no numbers or special symbols as per task
    while (fullname==NULL);
    return fullname;
}

void get_initials(string inits)
{
    //check the fisrt character in the string, if its a not a SPACE, print out the uppercase version of the character
    if (inits[0]!=' ')
    {
        printf("%c",toupper(inits[0]));
    }
    //starting from the second index check whether it's a character or a space 
    for (int i=1, n=strlen(inits); i<n;i++)
    {
        //if the character at the i'th index is NOT a space, check the previous index. 
        //if the i-1 is a space, then i is the start of a new "word"
        if (inits[i]!= ' ' && inits[i-1]==' ')
        {
            //print out the uppercase character of a letter that follows spaces
            printf("%c",toupper(inits[i]));
        }
    }
}
