/*
 *
 This File contains C code for Two dimensional Array and perform basic operations
 	- Traversal
	- Maximum number
	- Reverse of that Array
	- Sum of total Element
	- Find Row, cols and length of the Array
 *
 *
*/


#include <stdio.h>
#include <stdint.h>

void traversal(uint32_t matrics[][4],uint64_t rows, uint64_t cols){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("[%d]",matrics[i][j]);
		}
		printf("\n");
	}
}

uint32_t max(uint32_t matrics[][4],uint64_t rows,uint64_t cols){
	uint32_t max=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(max<=matrics[i][j]){
				max=matrics[i][j];	
			}
		}
	}
	return max;
}

uint32_t sum(uint32_t matrics[][4],uint64_t rows, uint64_t cols){
	uint32_t sum=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			sum+=matrics[i][j];
		}
	}
	return sum;
}

void Reverse(uint32_t matrics[][4],uint64_t rows, uint64_t cols){
	printf("Reverse: ");
	for(int i=rows-1;i>=0;i--){
		for(int j=cols-1;j>=0;j--){
			printf("[%d]",matrics[i][j]);
		}
		printf("\n");
	}
}

int main(){
	uint32_t matrics[][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
	uint64_t length = sizeof(matrics)/sizeof(matrics[0][0]);
	uint64_t rows = sizeof(matrics)/sizeof(matrics[0]);
	uint64_t cols = length/rows;
	printf("length: %lu\n",length);
	printf("rows: %lu\n",rows);
	printf("cols: %lu\n",cols);
	
	printf("array \n");
	traversal(matrics,rows,cols);
	
	printf("max: %u\n",max(matrics,rows,cols));
	printf("sum: %u\n",sum(matrics,rows,cols));
	
	Reverse(matrics,rows,cols);
	printf("\n");
	traversal(matrics,rows,cols);
	return 0;
}
