#include <stdio.h>

#include "new.h"
#include "Element.h"
#include "Set.h"

const void* Set;
const void* Element;

int main()
{
  void* s = new( Set );
  void* a = add( s, new( Element ) );
  void* b = add( s, new( Element ) );
  void* c = new( Element );
  
  printUsage();
  
  if ( contains( s, a ) && contains( s, b ) )
    printf("OK: Set S contains Element a and b.\n");
  if ( contains( s, c ) )
    printf( "FAIL: Set S should not contain Element c!\n" );
  if ( differ( a, add( s, a ) ) )
    printf( "FAIL: Element a should differ from Element a contained in Set S!\n" );
  if ( contains( s, drop( s, a ) ) )
    printf( "FAIL: Set S should not contain Element a!\n");
  
  delete( c );
  delete( b );
  delete( a );
  delete( s );
  
  printUsage();
  
  return 0;
}
