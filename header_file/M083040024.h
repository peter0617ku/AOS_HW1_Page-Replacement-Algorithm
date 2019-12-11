#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ACCESS_MAX 500
#define REFERENCE_SIZE 100000
#define RandomNum() rand() % ACCESS_MAX + 1	//Generatte random number

typedef const int ConstInt;			//constant integer

int ESC_hit;				//ESC hit and store its index
int DRAM[100];				//memory space
int r_bit[100];				//reference bit
int m_bit[100];				//modify bit
int priority[100];			//priority bit
int reference[ REFERENCE_SIZE ];	//Reference string
int modify[ REFERENCE_SIZE ];		//modify string

void Init_Array(int a[] , ConstInt size);
void Generate_Sequence_write( int a[] );
void Generate_Sequence_Random( int a[] );
void Generate_Sequence_Locality( int a[] );
void Generate_Sequence_special( int a[] );
void Print_Array( ConstInt a[] , ConstInt Size );	
int Check_Hit( ConstInt reference_bit , ConstInt Memory_size );
void FIFO( ConstInt Memory_size , ConstInt ref_size );
void Optimal( ConstInt Memory_size , ConstInt ref_size );
void Enhanced_second_chance( ConstInt Memory_size , ConstInt ref_size );
void MyAlgorithm( ConstInt Memory_size , ConstInt ref_size );

