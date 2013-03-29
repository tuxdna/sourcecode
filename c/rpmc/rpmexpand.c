/* Show some macro settings. */
#include <stdio.h>
#include <stdlib.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmmacro.h>
int main(int argc, char * argv[]) {
  int status = rpmReadConfigFiles( (const char*) NULL,
				   (const char*) NULL);
  if (status != 0) {
    printf("Error reading RC files.\n");
    exit(-1);
  }

  char* value = rpmExpand(argv[1], (const char*) NULL);
  printf("Value of macro is [%s]\n", value);
  exit(0);

}
