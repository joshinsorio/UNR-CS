//Name: Joshua Insorio 
//Date: 5/3/17
//project 8: combine_strings.c
//Function: Write a program that asks the user to enter two strings (with a maximum length of 30) and then performs one of two
//possible operations provided as command line arguments to the program

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int strlength(char *s);
int strcomp(char *s1, char *s2);
char intersperse(char *s1, char *s2, char *string);
char intersperse_2(char *s1, char *star, char *string);
char strcopy(char *s1, char *s2);
char widen_stars(char *s1, char *s2, char *string);

int main(int argc, char *argv[])
{

    char str1[31];
    char str2[31];
    char *choice[] = {"-i","-w"};
    char *string;
    int length1 = strlength(str1), length2 = strlength(str2);

    string = malloc(length1 + length2 + 1);
	if(!string)
	{
		printf("Unexpected error encountered, please contact your administrator.\n");
		return 1;
    }

    if(strcomp(argv[1],choice[0]) == 0)
    {
    printf("Please enter a string of maximum 30 characters: ");
    gets(str1);
    printf("Please enter a string of maxumum 30 characters: ");
    gets(str2);
    intersperse(str1, str2, string);
    printf("The combined string is: %s\n", string);
    }
    
    else if(strcomp(argv[1],choice[1]) == 0)
    {
    printf("Please enter a string of maximum 30 characters: ");
    gets(str1);
    printf("Please enter a string of maxumum 30 characters: ");
    gets(str2);
    widen_stars(str1, str2, string);
    printf("The combined string is: %s\n", string);
    }

    free(string);

    return 0;
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
    while(*s1 !='\0')
    {
        s1++;
    }
    while(*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return *s1;
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

char intersperse(char *s1, char *s2, char *string)
{

    int n = 0, i = 1;

    while (*s1 != '\0' && *s2 != '\0')
    {
        *string = *s1;
        string++;
        s1++;
        *string = *s2;
        string++;
        s2++;
    }
    while (*s1 != '\0')
    {
        *string = *s1;
        string++;
        s1++;
    }
    while (*s2 != '\0')
    {
        *string = *s2;
        string++;
        s2++;
    }
    *string = '\0';

    return *string;
}

char intersperse_2(char *s1, char *s2, char *string)
{

    int n = 0, i = 1;

    while (*s1 != '\0' && *s2 != '\0')
    {
        *string++ = *s1++;
        *string++ = *s2++;
    }
    string--;
    *string = '\0';

    return *string;
}

char widen_stars(char *s1, char *s2, char *string)
{
    int i = 0;
    int length  = strlength(s1) + strlength(s2) + 1;
    char star[length];

    for(i = 0; i < length; i++)
    {
        star[i] = '*';
    }
    strconcat(s1, s2);
    intersperse_2(s1, star, string);


    return *string;
}

