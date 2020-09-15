#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
static int space_char(char c){
  if (c == "\t" || c == " "){
    return 1;
  }
  return 0;

}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
static int non_space_char(char c){
  if (c == "\t" || c == " "){
    return 0;
  }
  return 1;

}
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
static char word_start(char *str){
  char *p = str;

  for (int i = 0; i < strlen(str)+1; i++)
    {
      if (p[i] == "\0")
	{
	  return p[i];
	}
      if (p[i] != " " || p[i] != "\t")
	{
	  return p[i];
	}

    }

}

/* Returns a pointer terminator char following *word */
static char *word_terminator(char *word){
  char *p = word;
  if (p + 1 == "\0"){
    return p+1;
  }
  for (int i = 0; i < strlen(word)+1; i++){
    if (p[i] == " " || p[i] == "\t"){
      return p[i];
    }
  }
}

/* Counts the number of words in the string argument. */
static int count_words(char *str){
  int count = 0;
  char *p = str;

  for (int i = 0; i < strlen(str) + 1; i++){
    if (p[i] == " " || p[i] == "\t"){
      count++;
    }
  }

}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
static char *copy_str(char *inStr, short len){


}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
