/*
 *
 *
 *This file contains a c program of 3D matrics and perform Basic operations on that
 *
 *
 *
 */


#include <stdio.h>
#include <stdint.h>

void traversal(uint32_t matrics[][4][3],uint8_t rows, uint8_t cols, uint8_t depth){
	for(int d=0;d<depth;d++){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				printf("[%d] ",matrics[d][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}

void reverse(uint32_t matrics[][4][3],uint8_t rows, uint8_t cols, uint8_t depth){
	printf("Revse Array:\n");
	for(int d=depth-1;d>=0;d--){
		for(int i=rows-1;i>=0;i--){
			for(int j=cols-1;j>=0;j--){
				printf("[%d] ",matrics[d][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}

uint32_t sum(uint32_t matrics[][4][3],uint8_t rows,uint8_t cols, uint8_t depth){
	uint32_t sum=0;
	for(int d=0;d<depth;d++){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				sum+=matrics[d][i][j];		
			}
		}
	}
	return sum;
}

uint32_t max(uint32_t matrics[][4][3], uint8_t rows, uint8_t cols, uint8_t depth){
	uint8_t max=0;
	for(int d=0;d<depth;d++){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(max<matrics[d][i][j]){
					max=matrics[d][i][j];
				}
			}
		}
	}
	return max;
}

int main(){
	uint32_t matrics[][4][3] = {{{1,2,3},{4,5,6},{7,8,9},{11,12,122}},
				   {{10,11,12},{13,14,15},{16,17,18},{23,2,4}}};
	uint8_t length = sizeof(matrics)/sizeof(matrics[0][0][0]);
	printf("length: %d\n",length);
	uint8_t rows = sizeof(matrics[0])/sizeof(matrics[0][0]);
	printf("rows: %d\n",rows);
	uint8_t cols = sizeof(matrics[0][0])/sizeof(matrics[0][0][0]);
	printf("cols: %d\n",cols);
	uint8_t depth = sizeof(matrics)/sizeof(matrics[0]);
	printf("depth: %d\n",depth);

	traversal(matrics,rows,cols,depth);
	reverse(matrics,rows,cols,depth);

	printf("sum: %d\n",sum(matrics,rows,cols,depth));
	printf("max: %d\n",max(matrics,rows,cols,depth));
	return 0;
}
