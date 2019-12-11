#include "M083040024.h"
void Optimal( ConstInt Memory_size , ConstInt ref_size )
{
	int i;
	int j;
	int k;
	int hit=0;
	int miss=0;
	int replacement = 0;
	int change[2];	//index, length
	int count;
	int equal;
	int empty = 0;
	int write = 0;
	
	for( i = 0 ; i < ref_size ; i++ )
	{
		if( Check_Hit( reference[i] , Memory_size ))
		{
			hit++;
			
		}
		else
		{
			miss++;
			if( !replacement )
			{
				DRAM[ empty ] = reference[ i ];
				m_bit[ empty ] = modify[i];
				empty++;
				if( empty >= Memory_size-1 ) replacement = 1;
			}
			else
			{
				change[0] = -1;
				change[1] = -1;
				count = 0;
				for( j = 0 ; j < Memory_size ; j++ )
				{
					equal = 0;
					for( k = i+1 ; k < ref_size ; k++ )
					{
						if( (DRAM[j] == reference[k]) )
						{
							equal = 1;
							if( k-i > change[1] ){
								count++;
								change[0] = j;
								change[1] = k-i;
							}
							break;
						}		
					}
					if(equal == 0)
					{
						change[0] = j;
						break;
					}
				}
				if( m_bit[ change[0] ] == 1 ) write++;
				DRAM[ change[0] ] = reference[ i ];
				m_bit[ change[0] ] = modify[i];
			}
		}
		
	}
	printf( "Page fault rate = %6d / %6d = %.4lf %% , write = %6d times\n" , miss, hit+miss , (double)miss*100/(hit+miss) , write );
}

