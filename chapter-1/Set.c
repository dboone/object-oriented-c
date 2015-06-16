#include <stdio.h>
#include <assert.h>

#include "Set.h"

#if !defined SIZE || SIZE < 1
#define SIZE 10
#endif

static int heap[SIZE];

void printUsage()
{
  int* p;
  int free = 0;
  
  for ( p = heap + 1; p < heap + SIZE; ++p )
    {
      if ( *p )
	{
	  ++free;
	}
    }
  printf( "Using %d of %d blocks\n", free, SIZE );
}

void* new( const void* type, ... )
{
  int* p;
  for ( p = heap + 1; p < heap + SIZE; ++p )
    {
      if ( !*p )
	{
	  break;
	}
    }
  assert( p < heap + SIZE );
  printf( "Allocated memory...\n" );
  *p = SIZE;
  return p;
}

void delete( void* _item )
{
  int* item = _item;
  
  if ( item )
    {
      assert( item > heap && item < heap + SIZE );
      *item = 0;
      printf( "Deallocated memory...\n" );
    }
}

void* add( void* _set, const void* _element )
{
  int* set = _set;
  const int* element = _element;
  
  assert( set > heap && set < heap + SIZE );
  assert( *set == SIZE );
  assert( element > heap && element < heap + SIZE );
  
  if ( *element == SIZE )
    {
      *(int*) element = set - heap;
    }
  else
    {
      assert( *element == set - heap );
    }
  
  return (void*) element;
}

void* find( const void* _set, const void* _element )
{
  const int* set = _set;
  const int* element = _element;
  
  assert( set > heap && set < heap + SIZE );
  assert( *set == SIZE );
  assert( element > heap && element < heap + SIZE );
  assert( *element );
  
  return *element == set - heap ? (void*) element : 0;
}

int contains( const void* _set, const void* _element )
{
  return find( _set, _element) != 0;
}

void* drop( void* _set, const void* _element )
{
  int* element = find( _set, _element );
  
  if ( element )
    {
      *element = SIZE;
    }
  return element;
}

int differ( const void* left, const void* right )
{
  return left != right;
}
