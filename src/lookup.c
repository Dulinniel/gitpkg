#include <stdlib.h>
#include <string.h>

#include "./headers/lookup.h"

/*
 * @name: linear_search
 * @description: Basic search algorithm
 * @params:
 *  -> options ( options* ) the option table to search in
 *  -> size ( short ) The size of the option
 *  -> key ( const char* ) The term we are looking for
 * @return:
 *  1. Pointer to the found element in the table ( &options[i] }
 *  2. NULL pointer { NULL )
 * @TODO: Make it a while loop to avoid early return technique
 * */
option* linear_search(option* options, short size, const char* key)
{
  for ( short i = 0; i < size; i++ )
  {
    if ( strcmp(options[i].key, key) == 0 ) 
      return &options[i]; 
  }
  return NULL;
}
