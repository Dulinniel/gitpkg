#include <stdlib.h>
#include <stdio.h>

#include "./headers/pkg.h"

#define MAX_REPO_PER_PAGE 5

/*
 * @name: find_package
 * @description: This function fetch github API with the query to return a list of repo
 * @params:
 * -> query ( const char* ) The user query which is argv[2] 
 * */
void find_package(const char *query)
{
  char command[512];
  // Unsafe code, but I promise I will make it safer
  snprintf(command, sizeof(command), 
      "curl -s \"https://api.github.com/search/repositories?q=%s&per_page=%d\" | grep \"full_name\" | cut -d '\"' -f 4",
      query, MAX_REPO_PER_PAGE);
  // YOU SHOULD NEVER DO THIS 
  system(command);
}

/*
 * @name: display_readme
 * @description: This function display in cat the README of the repo, if it's present
 * @params:
 * -> repo ( const char* ) The repo to get the reeadme from wich is argv[2]
 * */
void display_readme(const char* repo)
{
  char command[512];
  snprintf(command, sizeof(command),
      "curl -s \"https://raw.githubusercontent.com/%s/master/README.md\" | cat", 
      repo);
  system(command);
  printf("\n");
}

/*
 * @name: goto_repo
 * @description: Reach the repo in a browser 
 * @params:
 * -> repo ( const char* repo ) The repo name in argv[2]
 *  @TODO: Allow the user to config the browser to use to reach the repo
 * */
void goto_repo(const char* repo)
{ 
  char command[512];
  snprintf(command, sizeof(command),
      "lynx https://github.com/%s", 
      repo);
  system(command);
}


/*
 * @name: download_repo
 * @description: Clone the repo on the system 
 * @params:
 * -> repo ( const char* repo ) The repo to download 
 *  @TODO: Allow the user to config where he want to get the repo from 
 * */
void download_repo(const char *repo)
{
  char command[512];
  snprintf(command, sizeof(command),
    "git clone https://github.com/%s.git",
    repo
  );
  system(command);
}

/*
 * @name: display_help 
 * @description: Display the help message 
 * */
void display_help()
{
  printf("gitpkg, by Dulinniel 2025\n");
  printf("Available commands are: \n");
  printf("gitpkg search <keyword>\n\tLook for repo on github\n");
  printf("gitpkg read <repo>\n\tDisplay the README of a repo\n");
  printf("gitpkg see <repo>\n\tOpen the repo in a browser (default: lynx)\n");
  printf("gitpkg get <repo>\n\tCopy the repo on the disk\n");
  printf("gitpkg help\n\tDisplay this help message\n");
  printf("Want to Contribute ? Check : https://github.com/Dulinniel/gitpkg\n\n");
}
