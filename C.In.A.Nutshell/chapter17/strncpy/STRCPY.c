/* STRNCPY.C */

#include <string.h>
#include <stdio.h>

void main( void )
{
   char string[100] = "Cats are nice usually";
   printf ( "Before: %s\n", string );
   strncpy( string, "Dogs", 4 );
   strncpy( string + 9, "mean", 4 );
   printf ( "After:  %s\n", string );
}
