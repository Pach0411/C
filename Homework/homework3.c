#include <stdio.h>

int main()
{
    int c, number, quotes, single_quotes, parenthesis;

    number = 0; quotes = 0; single_quotes = 0; parenthesis = 0;

    while ((c = getchar()) != EOF)
    { 
        switch (c){ 

        case '(': parenthesis = 1;
          putchar (c);
           break; 

        case ')': parenthesis = 0;
          putchar (c); 
           break;

        case '{': parenthesis = 1;
          putchar (c);
           break;

        case '}':  parenthesis = 0;
          putchar (c);
           break;

        case '<': parenthesis = 1; 
          putchar (c);
           break;

        case '>': parenthesis = 1; 
          putchar (c); 
           break;

        case '[': parenthesis = 1; 
          putchar (c); 
           break;

        case ']': parenthesis = 0;
          putchar (c); 
           break;

        case '\"': quotes = 1; 
         quotes ++; 
          putchar (c); 
           break;

        case '\'': single_quotes = 1;
         single_quotes ++; 
          putchar (c); 
           break;

        default:
        if (c!='_' && c!='\?' && c!=':' && c!='.' && c!=';' && c!=',' && c!='!' && c!= '\¿' && c!='-')
        { 
            if (parenthesis == 1 || quotes == 1 || single_quotes == 1)
            {
                putchar (c);
            }
            else { 
                if (quotes == 2)
                {
                    quotes = 0;
                    putchar(c);
                }
                if (single_quotes == 2)
                {
                    single_quotes = 0;
                    putchar(c);
                }
            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){ 
                number ++;
            }
            else
            {
                number = 0;
            }
            if (number == 1)
            {
                putchar ('X');
            }
            if (number == 0)
            {
                putchar (c);
            }
            }
        }
        }
    }

    return 0;
}
/*This program was made with help of rulgame03 and hectorMtz22, the teacher's repo too, and the c programming language whit the book by Bria W. Kernighan and Dennis M. Ritchie the Second edition*/