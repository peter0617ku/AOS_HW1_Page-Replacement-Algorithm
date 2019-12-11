#include "M083040024.h"

void MyAlgorithm( ConstInt Memory_size , ConstInt ref_size )
{
	int i , j , x , find;
	int replace = 0;
	int ini_index = 0;
	int hit = 0;
	int miss = 0;
	int prob = 0;
	int write = 0;
	for( i = 0 ; i < ref_size ; i++ )
	{
		if( Check_Hit( reference[i] , Memory_size ) )	//If hit, hit+1 and priority+1
		{
			hit++;
			priority[ ESC_hit ]++;
		}
		else//If miss
		{
			miss++;
			if(!replace)	//If DRAM is not full, we will not replace the contents of the memory.
			{
				DRAM[ ini_index ] = reference[i];
				m_bit[ ini_index ] = modify[i];
				if( DRAM[ ini_index ] <= 100 ) priority[ ini_index ] = 3;	//If this block is a commonly used block, priority=3
				else priority[ ini_index ] = 1;					//else priority=1
				ini_index++;
				if( ini_index >= Memory_size-1 ) replace = 1;
			}
			else		//If DRAM is full, we will replace the contents of the memory.
			{
				find = 0;
				for( j = 0 ; j < (3 * Memory_size) && (find == 0) ; j++ )//Scan DRAM up to 3 times
				{
					x = (j + prob) % Memory_size;	//Start working from prob
					if( priority[x] == 0 )		//If priority has been reduced to 0, replace it!!
					{
						
						find = 1;
						if( m_bit[ x ] == 1) write++;	//If modity=1, we have to write back to Disk
						DRAM[ x ] = reference[i];
						m_bit[ x ] = modify[i];
						if( DRAM[ ini_index ] <= 100 ) priority[ x ] = 3;	//If this block is a commonly used block, priority=3
						else priority[ x ] = 1;					//else priority=1
						prob = (x + 1) % Memory_size;	//Next time we will start from (x+1)
					}
					else
					{
						priority[x]--;	//If the priority of this block is not 0, priority[x]--
					}
				}
			}
		}
	}
	printf( "Page fault rate = %6d / %6d = %.4lf %% , write = %6d times\n" , miss, hit+miss , (double)miss*100/(hit+miss) , write );	//output the result of the algorithm
}
