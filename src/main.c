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
    { "search", 1 }, { "read", 2 }, { "see", 3 }, { "get", 4 },
    { "help", 5 }
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

  switch ( selected_option->value )
  {
    case 1:
      find_package(argv[2]);
      break;
    case 2:
      display_readme(argv[2]);
      break;
    case 3:
      goto_repo(argv[2]);
      break;
    case 4:
      download_repo(argv[2]);
      break;
    // Fallback to default case if help is invoked
    case 5:
    default:
      display_help();
      break;
  }
  return 0;
}
