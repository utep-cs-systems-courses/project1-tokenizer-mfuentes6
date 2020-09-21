#include <stdio.h>
#include "tokinizer.h"


int space_char (char c) {
  if (c == "\t" || c == " "){
    return 1;
  }

  return 0;
}

int non_space_char(char c) {
  if (c == "\t" || c == " ") {
    return 0;
  }

  return 1;
}

char word_start(char *str) {
  char *p = str;

  for (int i = 0; i < strlen(str) +1; i++) {
    if (p[i] == "\0") {
      return[i];
    }
    if (p[i] != " " || p[i] != "\t") {
      return p[i];
    }

  }

}

char *word_terminator(char *word){
  char *p = word;
  if (p +1 == "\0"){
    return p+1;
  }
  for (int i =0; i < strlen(word)+1; i++){
    if (p[i] == " " || p[i] == "\t"){
      return p[i];
    }
  }
}

int count_words(char *str) {
  int count = 0;
  char *p = str;

  for (int i = 0; i < strlen(str)+1; i++){
    if (p[i]== " " || p[i] == "\t") {
      count ++;
    }
  }
}


char **tokenizer (char *str){


}


void print_tokens(char **tokens){


}


void free_tokens(char **tokens) {



}
