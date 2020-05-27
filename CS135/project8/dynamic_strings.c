//Name: Joshua Insorio 
//Date: 5/3/17
//project 8: dynamic_strings.c
//Function: This program will build off the last project. You will write an interactive program for strings. The number of strings
//will be provided as a command line argument. The user will enter the length of the string they are about to enter and
//then the string itself. After the program has read in the specified number of strings it will print the strings out and
//then print a menu that will allow the user to either: find the length of any string they want, compare any two strings,
//copy any string into another, or copy any string into another.


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int strlength(char *s);
int strcomp(char *s1, char *s2);
char strconcat(char *s1, char *s2);
char strcopy(char *s1, char *s2);

int main(int argc, char *argv[])
{
    char inputc = *argv[1];
    int choice, length, option1, option2, input = atoi(&inputc);
    char *array[input];

    for(int i = 0;i < input; i++)
    {
        printf("Enter the length of string %d: ", i + 1);
        scanf("%d", &length);
        array[i] = malloc(length + 1 * sizeof(char));
    	if(!array[i])
	    {
            printf("Unexpected error encountered, please contact your administrator.\n");
            return 1;
        }
        printf("Please enter string %d: ", i + 1);
        scanf("%s", array[i]);
    }
    printf("Your strings are: \n");
    for(int i = 0;i < input; i++)
    {
        printf("String number %d - \"%s\"\n", i + 1, array[i]);
    }


    printf("Options: \n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n4 - Concatenate strings\n5 - Quit\n");
    printf("Please enter your option: ");
    scanf("%d", &choice);
    
    while(choice == 0 || choice > 5)
    {
        printf("Invalid Option.\n");
        
        printf("Your strings are: \n");
        for(int i = 0;i < input; i++)
        {
            printf("String number %d - \"%s\"\n", i + 1, array[i]);
        }

        printf("Options: \n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n4 - Concatenate strings\n5 - Quit\n");
        printf("Please enter your option: ");
        scanf("%d", &choice);

    }

    while(choice > 0 && choice < 6)
    {
        switch(choice)
        {
            case 1:
                printf("Enter a string number: ");
                scanf("%d", &option1);
                printf("The length of string %d is: %d\n", option1, strlength(array[option1 - 1]));
                break;
            case 2:
                printf("Enter the number of the first string: ");
                scanf("%d", &option1);
                printf("Enter the number of the second string: ");
                scanf("%d", &option2);
                switch(strcomp(array[option1 - 1], array[option2 - 1]))
                {
                    case 0:
                        printf("The two strings are the same.\n");
                        break;
                    case 1:
                        printf("String 1 comes before string 2 alphabetically.\n");
                        break;
                    case -1:
                        printf("String 2 comes before string 1 alphabetically.\n");
                        break;
                }
                break;
            case 3:
                printf("Enter the number of the source string: ");
                scanf("%d", &option1);
                printf("Enter the number of the destination string: ");
                scanf("%d", &option2);
                strcopy(array[option1 - 1], array[option2 - 1]);
                break;
            case 4:
                printf("Enter the number of the source string: ");
                scanf("%d", &option1);
                printf("Enter the number of the destination string: ");
                scanf("%d", &option2);
                strconcat(array[option1 - 1], array[option2 - 1]);
            case 5:
                return 0;

        }

        printf("Your strings are: \n");
        for(int i = 0;i < input; i++)
        {
            printf("String number %d - \"%s\"\n", i + 1, array[i]);
        }

        printf("Options: \n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n4 - Concatenate strings\n5 - Quit\n");
        printf("Please enter your option: ");
        scanf("%d", &choice);
    }

    free(array);

    return 0;
}

char strcopy(char *s1, char *s2)
{
    while(*s1 != '\0')
    {
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = '\0';
    return *s2;
}

int strlength(char *s)
{
    int n = 0;
    for(; *s != '\0'; s++)
    {
        n++;
    }

    return n;
}

int strcomp(char *s1, char *s2)
{
    int result;

    while(*s1 != '\0' && *s2 != '\0')
    {
        if(tolower(*s1) > tolower(*s2))
        {
            return -1;
        }

        else if(tolower(*s2) > tolower(*s1))
        {
            return 1;
        }
        s1++;
        s2++;
    }

    if(strlength(s1) > strlength(s2))
    {
        return -1;
    }
    else if(strlength(s2) > strlength(s1))
    {
        return 1;
    }
    return 0;

}

char strconcat(char *s1, char *s2)
{
    while(*s2 !='\0')
    {
        s2++;
    }
    while(*s1 != '\0')
    {
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = '\0';
    return *s2;
}
