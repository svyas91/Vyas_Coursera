/******************************************************************************
 * Copyright (C) 2020 by Ioannis Fokianos
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief This programm prints an array and its statistics
 *
 * The function print statistics contains the implementation of
 * the min, max, mean and median values
 *
 * @author Ioannis Fokianos
 * @date 08/03/2020
 *
 */



#include <stdio.h>
#include "stats.h" 
#define SIZE 40

// Compile time switch for printing the original array
#if defined (PRINT)
#define flag (1)
void print_array(unsigned char *array,int N){
	PRINTF("Original array: ");
  for(int i=0;i<N;i++){
		PRINTF("%u ",*(array++));
	}
}
#else
#define flag (0)
#endif

int main(){
	
	unsigned int N = SIZE;
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,

							114, 88,   45,  76, 123,  87,  25,  23,
							200, 122, 150, 90,   92,  87, 177, 244,
							201,   6,  12,  60,   8,   2,   5,  67,
							7,  87, 250, 230,  99,   3, 100,  90};
	
	if(flag==1)
	{
		print_array(test,N);                    // print the array
	}
	
	print_statistics(test,N);                   // print statistics,also performs the 
                                                // find_mean.minimum,maximum,median functions
	return 0;

}

unsigned char find_mean(unsigned char *array,int N){

	int sum = 0;
	unsigned char mean;
	for(int i=0;i<N;i++){
		sum = sum + *(array++);
	}
	mean = sum/N;
	return mean;
}

unsigned char find_maximum(unsigned char *array, int N){
	unsigned char max = 0;
	for(int i=0;i<N;i++){
		if(*(array)>max){
			max = *(array);
		}
		array++;
	}
	return max;	
}

unsigned char find_minimum(unsigned char *array, int N){
	
	int min = 1000;
	for(int i=0;i<N;i++){
		if(*array<min){
			min = *array;
		}
		array++;
	}
	return min;
}

void sort_array(unsigned char *array, int N){
	
	unsigned char * fstptr = array;
	unsigned char * ptr = array;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if (j==0){ptr = fstptr;}
			if(*ptr<*array){
				int tmp = *array;
				*array = *ptr;
				*ptr = tmp;
			}
			++ptr;			
		}		
		++array;			
	}
  printf("\nSorted array: ");
	for(int i=0;i<N;i++){
		printf("%u ",*(fstptr++));
}
}

unsigned char find_median(unsigned char *array, int N){
	
	unsigned char * tempPtr = array;
	unsigned char median;

	if(N % 2 == 0){
		median = (*(array + N/2) + *(tempPtr + N/2 - 1))/2;
	}
	else{
		median = *(array + (N-1)/2);
	}
	return median;
}

void print_statistics(unsigned char *array,int N){

	unsigned char mean = find_mean(array,N);
	unsigned char min = find_minimum(array,N);
	unsigned char max = find_maximum(array,N);

	sort_array(array,N);
	unsigned char median = find_median(array,N);

	printf("\nMinimum value: %u\nMaximum value: %u\nMedian value: %u\nMean value: %u\n",min,max,median,mean);
}