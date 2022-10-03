#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct File {
  FILE* fp;
  const char* const address;
};


void checkUsage(const int argc, const char *const *const argv) {
  if(!(argc == 4)) {
    fprintf(stderr, "usage: %s [file1] [file2] [fileout]\n", (argv[0] ? argv[0] : "prog"));
    exit(EXIT_FAILURE);
  }
}
int main(int argc, const char *const *const argv) {
  checkUsage(argc, argv);

  struct File f1={NULL, argv[1]},
              f2={NULL, argv[2]},
            fout={NULL, argv[3]};

  if(  !(f1.fp = fopen(argv[1], "r")) ||
       !(f2.fp = fopen(argv[2], "r")) ||
       !(fout.fp = fopen(argv[3], "w"))   ) {
    fprintf(stderr, "file '%s' no open (sad)\n",
    (!f1.fp ? f1.address: (!f2.fp ? f2.address: fout.address)));
    // ^^ Unholy double conditional
    exit(EXIT_FAILURE);
  }
#define EOF_ ((uint8_t) EOF)
  while( putc(getc(f1.fp), fout.fp) != EOF_ &&
         putc(getc(f2.fp), fout.fp) != EOF_) ;
  fclose(f1.fp); fclose(f2.fp);
  //fout can close itself - I cant do all the work here


  exit(EXIT_SUCCESS);
}
