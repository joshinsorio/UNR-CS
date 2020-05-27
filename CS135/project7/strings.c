//Name: Joshua Insorio
//Date: 4.16.18
//Project 7: strings.c
//Purpose: Write a program that implements four of the string library functions using pointers: strcopy (string copy), strconcat (string concatenate), strcomp (string compare), and strlength (string length). 



#include <stdio.h>
#include <ctype.h>
int strlength(char *s);
int strcomp(char *s1, char *s2);
char strconcat(char *s1, char *s2);
char strcopy(char *s1, char *s2);

int main(void)
{
    char str1[51], str2[51];


    printf("Please enter the first string: ");
    gets(str1);
    printf("Please enter the second string: ");
    gets(str2);

    printf("The length of string 1 is: %d\n", strlength(str1));
    printf("The length of string 2 is: %d\n", strlength(str2));

    switch(strcomp(str1, str2))
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

    strconcat(str1, str2);
    printf("String 1 after concatenation: %s\n", str1);
    printf("String 2 after concatenation: %s\n", str2);

    strcopy(str1, str2);
    printf("String 1 after copying: %s\n", str1);
    printf("String 2 after copying: %s\n", str2);


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