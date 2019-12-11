#include "M083040024.h"
void FIFO( ConstInt Memory_size , ConstInt ref_size )
{
	int change = 0;
	int i = 0;
	int hit=0;
	int miss=0;
	int write = 0;
	
	for( i = 0 ; i < ref_size ; i++ )
	{
		if( Check_Hit( reference[i] , Memory_size ))	//If hit, "hit" +1
		{
			hit++;
		}
		else						//else page fault
		{
			miss++;
			if( m_bit[change] == 1 ) write++;	//If modity=1, we have to write back to Disk
			DRAM[change] = reference[i];		//Replace DRAM
			m_bit[change] = modify[i];		//Replace modify bit
			change = (change+1) % Memory_size;	//compute the value of "change". If we replace index i now, index i+1 will be replaced next time.
		}
	}
	printf( "Page fault rate = %6d / %6d = %.4lf %% , write = %6d times\n" , miss, hit+miss , (double)miss*100/(hit+miss) , write );	//output the result of FIFO algorithm
}
