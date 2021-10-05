#include<stdio.h>
#include<stdlib.h>
#include "csci4500utils.h"

int main( void ) {

  /* Write a string to standard output */
  char husker[90];
  readline(1, husker, 90);

  writeline( 1, husker );

  return 0;

}
