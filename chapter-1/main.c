#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

const void* Set;
const void* Object;

int main()
{
	void* s = new( Set );
	void* a = add( s, new( Object ) );
	void* b = add( s, new( Object ) );
	void* c = new( Object );

	if ( contains( s, a ) && contains( s, b ) )
		printf("OK: Set S contains Object a and b.\n");
	if ( contains( s, c ) )
		printf( "FAIL: Set S should not contain Object c!\n" );
	if ( differ( a, add( s, a ) ) )
		printf( "FAIL: Object a should differ from Object a contained in Set S!\n" );
	if ( contains( s, drop( s, a ) ) )
		printf( "FAIL: Set S should not contain Object a!\n");

	delete( drop( s, b ) );
	delete( drop( s, c ) );

	return 0;
}
