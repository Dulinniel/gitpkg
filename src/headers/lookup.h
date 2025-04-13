typedef struct 
{
  char* key;
  int value;
} option;

option* linear_search(option* options, short size, const char* key);
