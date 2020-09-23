#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main ()
{
  printf("Welcome to the Tokenizer!\n");
  Char str[200];
  Char *p = str;
  printf("Here are your options\n");
  printf("1. Enter a string to tokenize\n");
  printf("2. Enter q to exit program\n");
  printf("3. Enter h to see your history\n");
  printf("4. Enter ! followed by a number to acces exact history");
  int i = 0;
  int k = 0;

  while(k == 0){


    while( (c = getchar()) != '\n') {
      str[i] = c;
      i++;

    }
    str[i] = '\0';
    if (str[0] == 'q'){
      gotto done;
    }
    else if(str[0] == 'h'){

    }

    else if(str[0] == '!'){

    }

    else{
      tokens = tokenizer(str);
      print_tokens(tokens);
      //add history function
    }
    





  }

  done:
   printf("Goodbye!");
   return 0;

}
