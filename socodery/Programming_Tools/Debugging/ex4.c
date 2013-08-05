
#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

  char fileName[BUFSIZE];
  char password[BUFSIZE];
  char buf[BUFSIZE];
  FILE *f;
  
  if (argc != 3) {
    fprintf(stderr, "\nCIPHER syntax: cipher file password\n\n");
    /* we should be exiting here */
  }

  /* what happens if argv[1] or argv[2] is greater than BUFSIZE? */
  strcpy(fileName, argv[1]);
  strcpy(password, argv[2]);

  if ((f = fopen(fileName, "r")) == NULL) {
    fprintf(stderr, "Error: could not open %s for reading!\n\n", fileName);
    exit(1);
  }

  while (!feof(f)) {
    /* does this correctly handle EOF cases? */
    if (fgets(buf, BUFSIZE, f) == EOF) {
      break;
    }

    /* we would insert the encryption process here */
    
    printf(buf);
  }
  
  fclose(f);
  
  exit(0);
}

