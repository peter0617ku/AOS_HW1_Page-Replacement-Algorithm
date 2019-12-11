#include "M083040024.h"

void Init_Array(int a[] , ConstInt size)	//Initialize an array
{
	int i;
	for( i = 0 ; i < size ; i++ )
		a[i] = -1;
}

void Generate_Sequence_write( int a[] )	//Generate a sequence of random write number
{
	int i;
	for(i = 0 ; i < REFERENCE_SIZE ; i++)
	{
		if( rand() % 3 == 0)
			a[i] = 1;
		else
			a[i] = 0;
	}	
}

void Generate_Sequence_Random( int a[] ) //Generate a sequence of random reference number
{
	int i;
	for(i = 0 ; i < REFERENCE_SIZE ; i++)
		a[i] = RandomNum();
}

void Generate_Sequence_Locality( int a[] ) //Generate a sequence of locality reference number, consists of many consecutive sequence
{
	int length , start , i;
	int index = 0;
	while( index < 100000 )
	{
		length = rand() % 26 + 25;
		start = rand() % (500-length+1) + 1;
		for( i = start ; i < start + length; i++ )
		{
			a[ index ] = i ;
			index++;
			if( index >= 100000 ) break;
		}
	}
}

void Generate_Sequence_special( int a[] ) // My own sequence, most of them are small numbers(1~100), the rest are big number(101~500)
{
	int i;
	for(i = 0 ; i < REFERENCE_SIZE ; i++)
	{
		if(rand() % 4 == 0)
			a[i] = RandomNum();
		else
			a[i] = rand() % 100 + 1;
	}	
}

void Print_Array( ConstInt a[] , ConstInt Size ) //Print values of the array a[]
{
	int i;
	for( i = 0 ; i < Size ; i++ )
		printf( "[%d]:	%3d\n" , i+1 , a[i] );
}

int Check_Hit( ConstInt reference_bit , ConstInt Memory_size )	//Check whether hit or not (page fault)
{
	int i;
	for( i = 0 ; i < Memory_size ; i++ )
	{
		if( DRAM[i] == reference_bit )
		{
			ESC_hit = i;
			return 1;
		}
	}
	ESC_hit = -1;
	return 0;
}

