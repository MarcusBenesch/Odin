/*
 * Auth: Marcus Benesch
 * Date: 09-19-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-01, A Simple "Hello, World" C program.
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main( void )  {

	/* Personalized hello. */
	printf( "Hello, World, from Marcus Benesch!\n" );

	/* Proper way to finish a program in a POSIX-system. */
	exit( EXIT_SUCCESS );

} /* end main() */