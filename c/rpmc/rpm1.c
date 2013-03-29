/* Show the rpmrc settings. */
#include <stdio.h>
#include <stdlib.h>
#include <rpm/rpmlib.h>
int main(int argc, char * argv[]) {
  int status = rpmReadConfigFiles( (const char*) NULL,
				   (const char*) NULL);
  if (status != 0) {
    printf("Error reading RC files.\n");
    exit(-1);
  } else {
    printf("Read RC OK\n");
  }
  rpmSetVerbosity(RPMMESS_NORMAL);
  rpmShowRC( stdout );
  exit(0);
}
