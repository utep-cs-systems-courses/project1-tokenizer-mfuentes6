#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main ()
{
  printf("Welcome to the Tokenizer!\n");
  Char str[200];
  Char *p = str;
  List *HISTORY = init_history();
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
      print_history(HISTORY);
    
    }

    else if(str[0] == '!'){
      indexID = str[1];     //gets index id to look for
      printf("String at index %d", indexID);
      printf("%s", get_history(HISTORY,indexID);
    }

    else{
      tokens = tokenizer(str);
      print_tokens(tokens);
      add_history(HISTORY,str);
    }
    





  }

  done:
   printf("Goodbye!");
   return 0;

}
