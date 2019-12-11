#include "M083040024.h"

void Random()
{
	int Memory_size;
	Generate_Sequence_Random( reference );	//Generate random string
	Generate_Sequence_write( modify );	//Generate modify string
	printf( "*****************Random*****************\n" );
	for( Memory_size = 10 ; Memory_size <= 100 ; Memory_size = Memory_size + 10 )//memory size = 10,20,30,...,100
	{
		printf( "===================\nMemory size = %3d\n" , Memory_size );
		
		Init_Array( r_bit , Memory_size );	//Initialize r_bit
		Init_Array( m_bit , Memory_size );	//Initialize m_bit
		Init_Array( DRAM , Memory_size );	//Initialize DRAM
		printf( "FIFO:       " );
		FIFO( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );	//Initialize r_bit
		Init_Array( m_bit , Memory_size );	//Initialize m_bit
		Init_Array( DRAM , Memory_size );	//Initialize DRAM
		printf( "Optimal:    " );
		Optimal( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );	//Initialize r_bit
		Init_Array( m_bit , Memory_size );	//Initialize m_bit
		Init_Array( DRAM , Memory_size );	//Initialize DRAM
		printf( "ESC:        " );
		Enhanced_second_chance( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );	//Initialize r_bit
		Init_Array( m_bit , Memory_size );	//Initialize m_bit
		Init_Array( DRAM , Memory_size );	//Initialize DRAM
		Init_Array( priority , Memory_size );	//Initialize priority
		printf( "MyAlgorithm:" );
		MyAlgorithm( Memory_size , REFERENCE_SIZE );
	}
}
void Locality()
{
	int Memory_size;
	Generate_Sequence_Locality( reference );//Generate locality string
	Generate_Sequence_write( modify );	//Generate modify string
	printf( "\n***************Locality***************\n" );
	for( Memory_size = 10 ; Memory_size <= 100 ; Memory_size = Memory_size + 10 )//Ibid.
	{
		printf( "===================\nMemory size = %3d\n" , Memory_size );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		printf( "FIFO:       " );
		FIFO( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		printf( "Optimal:    " );
		Optimal( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		printf( "ESC:        " );
		Enhanced_second_chance( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		Init_Array( priority , Memory_size );
		printf( "MyAlgorithm:" );
		MyAlgorithm( Memory_size , REFERENCE_SIZE );
	}
}

void special()
{
	int Memory_size;
	Generate_Sequence_special( reference );	//Generate my own string
	Generate_Sequence_write( modify );	//Generate modify string
	printf( "\n***************My own reference string***************\n" );
	for( Memory_size = 10 ; Memory_size <= 100 ; Memory_size = Memory_size + 10 )//Ibid.
	{
		printf( "===================\nMemory size = %3d\n" , Memory_size );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		printf( "FIFO:       " );
		FIFO( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		printf( "Optimal:    " );
		Optimal( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		printf( "ESC:        " );
		Enhanced_second_chance( Memory_size , REFERENCE_SIZE );
		
		Init_Array( r_bit , Memory_size );
		Init_Array( m_bit , Memory_size );
		Init_Array( DRAM , Memory_size );
		Init_Array( priority , Memory_size );
		printf( "MyAlgorithm:" );
		MyAlgorithm( Memory_size , REFERENCE_SIZE );
	}
}


int main( int argc , char* argv[] )
{
	//int c = -1;
	srand( time(0) );
	
	Random();
	Locality();
	special();
	
	printf("Run success!\n");
	return 0;
}
