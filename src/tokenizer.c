#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

//checks if character is a space or not
int space_char (char c)
{
  if (c == '\t' || c == ' '){
    return 1;
  }

  return 0;
}

//checks if the character is non space
int non_space_char(char c)
{
  if (c == '\t' || c == ' ') {
    return 0;
  }

  return 1;
}

//iterates untill a character is found
char word_start(char *str)
{
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

char *word_terminator(char *word)
{
  char *p = word;
  int i = 0;
  if (p[i] == '\0'){
    return p+i;
  }
  while (p[i] != '\0'){
    if (space_char(p[i])==1){
      return word[i];
    }
    i++;

  }
}

int count_words(char* str)
{
  int count = 0;
  char *p = str;

  int i = 0;
  while (p[i] != '\0'){       //iterates till null terminator
    if (space_char(p[i])==1){ //if space found then one word has passed
      count++;                //increase count each time space is found
    }
    i++;
  }
  return count;
  
}


char *copy_str(char *inStr, short len)
{
  char *word = (char*) malloc(len+1);
  char *temp = word;
  

                             //continues till null character
  while (*inStr != '\0') {
    *temp = *inStr;          //continues copying each character
    temp++;
    inStr++;

  }

  return word;               //returns copied string
}

char **tokenizer (char *str)
{
  int word_count = count_words(str); //gets size needed for token
  char *p = str;
  int i = 0;
  int j = 0;
  word_count++;
  char *temp[50];
  temp[0] = '\0';   //empty string to omit to then place into token[i]

  char *token =(char*) malloc(word_count * sizeof(char*));

  while(p[i] != "\0"){
    if(space_char(p[i]) == 1){
      
      token[j] = temp;
      j++;
      i++;
      temp[0] = '\0';      // once temp is added in token[j] reset to "" to begin copying next word
    }
    strncat(temp, &p[i], 1); //appends current character to temp
    i++;
  }

  return token;
}


void print_tokens(char **tokens)
{
  int i = 0;
  while (tokens[i] != ""){      //prints untill the null terminator
    printf("%s\n", tokens[i]);
    i++;

  }

}


void free_tokens(char **tokens)
{
  char **temp = tokens;       //iterates through and frees every step of iteration
  while(*temp != ""){
    free (*temp);
    temp++;
  }
  free(temp);

}
