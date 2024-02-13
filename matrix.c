/*
 * Defines functions for manipulating square integer matrices.
 * CSC 225, Assignment 7
 */

#include "matrix.h"

/* matscl: Multiplies each element of a matrix by a scalar. */
void matscl(int *mat, unsigned int n, int c) {
    /* TODO: Complete this function, given:
     *  mat - A pointer to the first element in a multidimensional array
     *  n   - The height and width of the matrix
     *  c   - The constant scalar
     *  ... multiply each element in "mat" by "c" */
	int i, j; 

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			mat[i * n + j] = mat[i * n + j] * c;
		}
	}
}

/* matpscl: Multiplies each element of a matrix by a scalar. */
void matpscl(int **mat, unsigned int n, int c) {
    /* TODO: Complete this function, given:
     *  mat - An array of pointers to arrays of integers
     *  n   - The height and width of the matrix
     *  c   - The constant scalar
     * ...multiply each element in "mat" by "c". */
	int i, j; 
	
	for (i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
          		mat[i][j] = mat[i][j] * c;
		}
	} 
}

/* mattrn: Transposes a matrix about its diagonal, in-place. */
void mattrn(int *mat, unsigned int n) {
    /* TODO: Complete this function, given:
     *  mat - A pointer to the first element in a multidimensional array
     *  n   - The height and width of the matrix
     * ...transpose "mat" about its diagonal. */

	int i, j, temp;	
	for (i = 0; i < n; i++) { 	
		for (j = i; j < n; j++) {
			temp =  mat[j * n + i];
			mat[j * n + i] = mat[i * n + j];
			mat[i * n + j] = temp; 
		}
	}
}

/* matptrn: Transposes a matrix about its diagonal, in-place. */
void matptrn(int **mat, unsigned int n) {
    /* TODO: Complete this function, given:
     *  mat - An array of pointers to arrays of integers
     *  n   - The height and width of the matrix
     * ...transpose "mat" about its diagonal. */
	
	int i, j, temp; 

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			temp = mat[j][i];
			mat[j][i] = mat[i][j];
			mat[i][j] = temp;  
		}
	}
}

/* matadd: Adds two matrices, placing their sum into a third. */
void matadd(int *mata, int *matb, int *matc, unsigned int n) {
    /* TODO: Complete this function, given:
     *  mata - A pointer to the first element in a multidimensional array
     *  matb - A pointer to the first element in a multidimensional array
     *  matc - A pointer to the first element in a multidimensional array
     *  n    - The height and width of the matrices
     * ...compute "matc = mata + matb". */
	int i, j;
 
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
		matc[i * n + j] = mata[i * n + j] + matb[i * n + j];  
		}
	}
}

/* matpadd: Adds two matrices, placing their sum into a third. */
void matpadd(int **mata, int **matb, int **matc, unsigned int n) {
    /* TODO: Complete this function, given:
     *  mata - An array of pointers to arrays of integers
     *  matb - An array of pointers to arrays of integers
     *  matc - An array of pointers to arrays of integers
     *  n    - The height and width of the matrices
     * ...compute "matc = mata + matb". */
	int i, j; 

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			matc[i][j] = mata[i][j] + matb[i][j]; 
		}
	}
}

/* matmul: Multiplies two matrices, placing their product into a third. */
void matmul(int *mata, int *matb, int *matc, unsigned int n) {
    /* TODO: Complete this function, given:
     *  mata - A pointer to the first element in a multidimensional array
     *  matb - A pointer to the first element in a multidimensional array
     *  matc - A pointer to the first element in a multidimensional array
     *  n    - The height and width of the matrices
     * ...compute "matc = mata * matb". */
	int i, j, g, temp1, temp2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			temp2 = 0;
			for (g = 0; g < n; g++) { 
				temp1 = mata[i * n + g] * matb[g * n + j];
				temp2 = temp2 + temp1; 
			}
			matc[i * n + j] = temp2;  
		}
	}	
}

/* matpmul: Multiplies two matrices, placing their product into a third. */
void matpmul(int **mata, int **matb, int **matc, unsigned int n) {
    /* TODO: Complete this function, given:
     *  mata - An array of pointers to arrays of integers
     *  matb - An array of pointers to arrays of integers
     *  matc - An array of pointers to arrays of integers
     *  n    - The height and width of the matrices
     * ...compute "matc = mata * matb". */
	int i, j, g, temp1, temp2;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        temp2 = 0;
                        for (g = 0; g < n; g++) {
                                /* temp1 = mata[i * n + g] * matb[g * n + j];*/
				temp1 = mata[i][g] * matb[g][j]; 
                                temp2 = temp2 + temp1;
                        }
                        matc[i][j] = temp2;
                }
        }
}
