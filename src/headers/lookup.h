typedef enum
{
  CMD_SEARCH = 1,
  CMD_READ = 2,
  CMD_SEE = 3,
  CMD_GET = 4,
  CMD_HELP = 5
} Command;

typedef struct 
{
  char* key;
  Command instruction;
} option;

option* linear_search(option* options, short size, const char* key);
