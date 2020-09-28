#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history ()
{
  List *list = (List*) malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }                       //Gets length to create a copy

  char *inStr = copy_str(str, i);    //gets string
  Item *item = malloc(sizeof(Item)); //creates item that will be added
  Item *current = list->root;

  item->str = inStr;  //item str set to instr
  item->next = NULL;  //next value gets equal to null, this will be the tail of the list once added
  int count = 0;

  if(list->root == NULL){ // case for an empty list
    item->id = count;
    list->root = item;
  }

  else{
    count = 1;
    while(current->next){ //iterates till finds end of list while tracking place in list with count
      current = current->next;
      count++;
    }
    current->next = item;
    item->id = count+1;

  }
}



char *get_history(List *list, int id)
{
  Item* current = list->root;
  if(current == NULL){ //case for an empty list
    return NULL;
  }

  while(current != NULL){//iterates through the whole list till id is found
    if(current->id == id){
      return current->str;
    }
  }
  return NULL; //if id is not found null is returned

}


void print_history(List *list)
{
  Item *current = list->root;
  printf("Beginning of history\n");

  while(current != NULL){
    printf("%d: %s\n", current->id, current->str);
    current = current->next;
  }
}


void free_history(List *list)
{
  Item *current;
  while(list->root != NULL){       //frees root every pass and sets new root to root->next
    current = list->root;              // continues untill there is no root to free
    list->root = list->root->next;
    free(current);
  }
  free(list);

}


