#include <stdio.h>
#include "tokinizer.h"

//checks if character is a space or not
int space_char (char c) {
  if (c == '\t' || c == ' '){
    return 1;
  }

  return 0;
}

//checks if the character is non space
int non_space_char(char c) {
  if (c == '\t' || c == ' ') {
    return 0;
  }

  return 1;
}

//iterates untill a character is found
char word_start(char *str) {
  char *p = str;
  int i = 0;
  if (p[i] == '\0'){
    return p[i];
  }
  while (p[i] != '\0') {
    if (non_space_char(p[i])==1) {
      return p[i];
    }
    i++;
  }

}

char *word_terminator(char *word){
  char *p = word;
  if (p +1 == '\0'){
    return p+1;
  }
  int i = 0;
  while (p[i] != '\0'){
    if (space_char(p[i])==1){
      return p[i];
    }
    i++;

  }
}

int count_words(char *str) {
  int count = 0;
  char *p = str;

  int i = 0;
  while (p[i] != '\0'){
    if (space_char(p[i])==1){
      count++;
    }
    i++;
  }
  return count;
  
}


char *copy_str(char *inStr, short len){
  char *word = (char*) malloc(len+1);
  char *temp = word;


  //continues till null character
  while (*intStr != '\0') {
    *temp = *inStr;  //continues copying each character
    temp++;
    inStr++;

  }

  return word; //returns copied string
}

char **tokenizer (char *str){
  char *temp = str;
  int word_count = count_words(*str);
  word_count += 2;

  char **token = (char**)malloc(word_count * sizeof(char*));
  int count = 0;

  int start = 0;
  int end = 0;

  while(str[end] != '\0'){
    if(space_char(str[end]) == 1){
      token[count++] = copy_str(str+start, end-start);
      start = end +1;
      end = start;
      count++
    }
    else {
      end++;
    }

  }
  token[count++] = copy_str(str+start,end-start);
  token[count] = "";

  return token;
}


void print_tokens(char **tokens){
  while (*str != ""){
    printf("%s\n", *str);
    str++;

  }

}


void free_tokens(char **tokens) {
  char **temp = str;
  while(*temp != ""){
    free (*temp);
    temp++;
  }
  free(temp);

}
