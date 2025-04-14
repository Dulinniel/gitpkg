#include <stdlib.h>
#include <stdio.h>

#include "./headers/pkg.h"
#include "./headers/lookup.h"

int main(int argc, const char *argv[])
{

  // Check if there is enough argument
  if ( argc < 2 ) 
  {
    printf("Missing arguments\n");
    display_help();
    return -1;
  }

  // Lookup table
  option options[] = {
    { "search", CMD_SEARCH }, { "read", CMD_READ }, 
    { "see", CMD_SEE }, { "get", CMD_GET },
    { "help", CMD_HELP }
  };

  // Magic sizeof calculation
  short option_size = sizeof(options) / sizeof(option);

  option* selected_option = linear_search(options, option_size, argv[1]);

  // If you entered an invalid command
  if ( !selected_option )
  {
    printf("Unknown argument\n");
    display_help();
    return -1;
  }

  switch ( selected_option->instruction )
  {
    case CMD_SEARCH:
      find_package(argv[2]);
      break;
    case CMD_READ:
      display_readme(argv[2]);
      break;
    case CMD_SEE:
      goto_repo(argv[2]);
      break;
    case CMD_GET:
      download_repo(argv[2]);
      break;
    // Fallback to default case if help is invoked
    case CMD_HELP:
    default:
      display_help();
      break;
  }
  return 0;
}
