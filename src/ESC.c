#include "M083040024.h"
void Enhanced_second_chance( ConstInt Memory_size , ConstInt ref_size )
{
	int hit = 0;
	int miss = 0;
	int prob = 0;
	int i;
	int j;
	int find;
	int x;
	int replacement = 0;
	int empty = 0;
	int write = 0;
	
	for( i = 0 ; i < ref_size; i++ )
	{
		if( Check_Hit( reference[i] , Memory_size ) )//If hit, "hit" +1
		{
			hit++;
			r_bit[ ESC_hit ] = 1;		//reference bit change to 1
		}
		else
		{
			miss++;
			find = 0;
			if(!replacement)	//If DRAM is not full, we will not replace the contents of the memory.
			{
				DRAM[ empty ] = reference[i];	//update DRAM
				r_bit[ empty ] = 1;		//update reference bit
				m_bit[ empty ] = modify[i];	//update modify bit
				empty++;			//"empty" is an index, "empty" will continue to be used until DRAM is full
				if( empty >= Memory_size - 1) replacement = 1;	//If DRAM is full, we will use replacement algorithm.
			}
			else			//If DRAM is full, we will replace the contents of the memory.
			{
				for( j = 0 ; (j < Memory_size) && (!find) ; j++ )
				{
					x = (prob+j) % Memory_size;	//Start working from prob
					if( r_bit[ x ] == 0 && m_bit[ x ] == 0 )//First, we will find (0,0) without changing refeerence bit to 0. If success, replace it directly.
					{
						find = 1;
						DRAM[ x ] = reference[i];
						r_bit[ x ] = 1;
						m_bit[ x ] = modify[i];
						prob = (x + 1) % Memory_size;	//Next time we will start from (x+1)
					}
				}
				for( j = 0 ; (j < Memory_size) && (!find) ; j++ )//If there is no (0,0) in DRAM, we will start looking for (0,1)
				{
					x = (prob+j) % Memory_size;		//Start working from prob
					if( r_bit[ x ] == 0 && m_bit[ x ] == 1 )//If we find (0,1), update it
					{
						find = 1;
						DRAM[ x ] = reference[i];
						r_bit[ x ] = 1;
						m_bit[ x ] = modify[i];
						prob = (x + 1) % Memory_size;	//Next time we will start from (x+1)
						write++;	//If modity=1, we have to write back to Disk
					}
					if( r_bit[ x ] == 1 )	//If reference bit is 1, we will change it to 0
					{
						r_bit[ x ] = 0;
					}
				}
				for( j = 0 ; (j < Memory_size) && (!find) ; j++ )//If there is no (0,0) & (0,1) in DRAM, retry!!(Because we have updated all reference bit)
				{
					x = (prob+j) % Memory_size;
					if( r_bit[ x ] == 0 && m_bit[ x ] == 0 )
					{
						find = 1;
						DRAM[ x ] = reference[i];
						r_bit[ x ] = 1;
						m_bit[ x ] = modify[i];
						prob = (x + 1) % Memory_size;
					}
				}
				for( j = 0 ; (j < Memory_size) && (!find) ; j++ )
				{
					x = (prob+j) % Memory_size;
					if( r_bit[ x ] == 0 && m_bit[ x ] == 1 )
					{
						find = 1;
						DRAM[ x ] = reference[i];
						r_bit[ x ] = 1;
						m_bit[ x ] = modify[i];
						prob = (x + 1) % Memory_size;
						write++;
					}
				}
			}
		}
	}
	printf( "Page fault rate = %6d / %6d = %.4lf %% , write = %6d times\n" , miss, hit+miss , (double)miss*100/(hit+miss) , write );	//output the result of ESC algorithm
}

