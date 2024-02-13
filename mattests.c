/*
 * Tests functions for square matrices.
 * CSC 225, Assignment 7
 * Given tests, Fall '20
 */

#include <assert.h>
#include "matrix.h"

/* test01matscl: Tests multidimensional matrix scaling. */
void test01matscl() {
    int mat[2][2] = {{1, 2}, {3, 4}};

    matscl(&mat[0][0], 2, 2);

    assert(mat[0][0] == 2);
    assert(mat[0][1] == 4);
    assert(mat[1][0] == 6);
    assert(mat[1][1] == 8);
}

/* test02matpscl: Tests array-of-pointers matrix scaling. */
void test02matpscl() {
    int row1[2] = {1, 2}, row2[2] = {3, 4}, *mat[2];

    mat[0] = row1;
    mat[1] = row2;
    matpscl(mat, 2, 2);

    assert(mat[0][0] == 2);
    assert(mat[0][1] == 4);
    assert(mat[1][0] == 6);
    assert(mat[1][1] == 8);
}

/* test03mattrn: Tests multidimensional matrix transposition. */
void test03mattrn() {
    int mat[2][2] = {{1, 2}, {3, 4}};

    mattrn(&mat[0][0], 2);

    assert(mat[0][0] == 1);
    assert(mat[0][1] == 3);
    assert(mat[1][0] == 2);
    assert(mat[1][1] == 4);
}

/* test04matptrn: Tests array-of-pointers matrix transposition. */
void test04matptrn() {
    int row1[2] = {1, 2}, row2[2] = {3, 4}, *mat[2];

    mat[0] = row1;
    mat[1] = row2;
    matptrn(mat, 2);

    assert(mat[0][0] == 1);
    assert(mat[0][1] == 3);
    assert(mat[1][0] == 2);
    assert(mat[1][1] == 4);
}

/* test05matadd: Tests multidimensional matrix addition. */
void test05matadd() {
    int mata[2][2] = {{1, 2}, {3, 4}},
        matb[2][2] = {{4, 3}, {2, 1}},
        matc[2][2];

    matadd(&mata[0][0], &matb[0][0], &matc[0][0], 2);

    assert(matc[0][0] == 5);
    assert(matc[0][1] == 5);
    assert(matc[1][0] == 5);
    assert(matc[1][1] == 5);
}

/* test06matpadd: Tests array-of-pointers matrix addition. */
void test06matpadd() {
    int row1[2] = {1, 2}, row2[2] = {3, 4}, *mata[2],
        row3[2] = {4, 3}, row4[2] = {2, 1}, *matb[2],
        row5[2], row6[2], *matc[2];

    mata[0] = row1;
    mata[1] = row2;
    matb[0] = row3;
    matb[1] = row4;
    matc[0] = row5;
    matc[1] = row6;
    matpadd(mata, matb, matc, 2);

    assert(matc[0][0] == 5);
    assert(matc[0][1] == 5);
    assert(matc[1][0] == 5);
    assert(matc[1][1] == 5);
}

/* test07matmul: Tests multidimensional matrix multiplication. */
void test07matmul() {
    int mata[2][2] = {{1, 2}, {3, 4}},
        matb[2][2] = {{4, 3}, {2, 1}},
        matc[2][2];

    matmul(&mata[0][0], &matb[0][0], &matc[0][0], 2);

    assert(matc[0][0] == 8);
    assert(matc[0][1] == 5);
    assert(matc[1][0] == 20);
    assert(matc[1][1] == 13);
}

/* test08matpmul: Tests array-of-pointers matrix multiplication. */
void test08matpmul() {
    int row1[2] = {1, 2}, row2[2] = {3, 4}, *mata[2],
        row3[2] = {4, 3}, row4[2] = {2, 1}, *matb[2],
        row5[2], row6[2], *matc[2];

    mata[0] = row1;
    mata[1] = row2;
    matb[0] = row3;
    matb[1] = row4;
    matc[0] = row5;
    matc[1] = row6;
    matpmul(mata, matb, matc, 2); 

    assert(matc[0][0] == 8);
    assert(matc[0][1] == 5);
    assert(matc[1][0] == 20);
    assert(matc[1][1] == 13);     
}                                                                                                                                                                                                                                               
void test09matscl() {	
	int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	matscl(&mat[0][0], 3, 2);

	assert(mat[0][0] == 2);
	assert(mat[0][1] == 4); 
	assert(mat[0][2] == 6); 
	assert(mat[1][0] == 8);
	assert(mat[1][1] == 10);
	assert(mat[1][2] == 12); 
	assert(mat[2][0] == 14);
	assert(mat[2][1] == 16);
	assert(mat[2][2] == 18); 
}

void test10matpscl() {
	int row1[3] = {1, 2, 3}, row2[3] = {4, 5, 6}, row3[3] = {7, 8, 9}, *mat[3]; 
	
	mat[0] = row1; 
	mat[1] = row2; 
	mat[2] = row3; 
	matpscl(mat, 3, 2); 
	
	assert(mat[0][0] == 2);                                                                                                                                                     assert(mat[0][1] == 4);                                                                                                                                                     assert(mat[0][2] == 6);                                                                                                                                                     assert(mat[1][0] == 8);                                                                                                                                                     assert(mat[1][1] == 10);                                                                                                                                                    assert(mat[1][2] == 12);                                                                                                                                                    assert(mat[2][0] == 14);                                                                                                                                                    assert(mat[2][1] == 16);                                                                                                                                                    assert(mat[2][2] == 18); 
 
}

void test11mattrn() {
	int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 

	mattrn(&mat[0][0], 3);

	assert(mat[0][0] == 1);
	assert(mat[0][1] == 4); 
	assert(mat[0][2] == 7); 
	assert(mat[1][0] == 2); 
	assert(mat[1][1] == 5); 
	assert(mat[1][2] == 8); 
	assert(mat[2][0] == 3); 
	assert(mat[2][1] == 6); 
	assert(mat[2][2] == 9); 
}

void test12matptrn(){
	int row1[3] = {1, 2, 3}, row2[3] = {4, 5, 6}, row3[3] =  {7, 8, 9}, *mat[3];
	
	mat[0] = row1;  
	mat[1] = row2;
	mat[2] = row3;   
	matptrn(mat, 3); 

	assert(mat[0][0] == 1);
	assert(mat[0][1] == 4); 
	assert(mat[0][2] == 7); 
	assert(mat[1][0] == 2); 
	assert(mat[1][1] == 5); 
	assert(mat[1][2] == 8); 
	assert(mat[2][0] == 3); 
	assert(mat[2][1] == 6); 
	assert(mat[2][2] == 9); 
} 

void test13matadd() {
	int mata[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},  
	    matb[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}},
	    matc[3][3]; 
  
	matadd(&mata[0][0], &matb[0][0], &matc[0][0], 3);

	assert(matc[0][0] = 10);
	assert(matc[0][1] = 10);
	assert(matc[0][2] = 10);  
	assert(matc[1][0] = 10);
	assert(matc[1][1] = 10);
	assert(matc[1][2] = 10);
	assert(matc[2][0] = 10);
	assert(matc[2][1] = 10);
	assert(matc[2][2] = 10);
}

void test14matpadd() {
	int row1[3] = {1, 2, 3}, row2[3] = {4, 5, 6}, row3[3] =  {7, 8, 9}, *mata[3],
	    row4[3] = {9, 8, 7}, row5[3] = {6, 5, 4}, row6[3] = {3, 2, 1}, *matb[3], 
	    row7[3], row8[3], row9[3], *matc[3]; 

	mata[0] = row1;  
	mata[1] = row2;
	mata[2] = row3;
	matb[0] = row4;  
	matb[1] = row5;
	matb[2] = row6;  
	matc[0] = row7;
	matc[1] = row8;
	matc[2] = row9; 
	matpadd(mata, matb, matc, 3); 

	assert(matc[0][0] = 10);                                                                                                                                                    assert(matc[0][1] = 10);                                                                                                                                                    assert(matc[0][2] = 10);                                                                                                                                                    assert(matc[1][0] = 10);                                                                                                                                                    assert(matc[1][1] = 10);                                                                                                                                                    assert(matc[1][2] = 10);                                                                                                                                                    assert(matc[2][0] = 10);                                                                                                                                                    assert(matc[2][1] = 10);                                                                                                                                                    assert(matc[2][2] = 10); 
}  

void test15matmul() {
	int mata[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},                                                                                                                             matb[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}},                                                                                                                             matc[3][3];  

	 matmul(&mata[0][0], &matb[0][0], &matc[0][0], 3);                                                                                                                                                                                                                                                                                                       
	assert(matc[0][0] =  30);                                                                                                                                                   assert(matc[0][1] = 24);                                                                                                                                                    assert(matc[0][2] = 18);                                                                                                                                                    assert(matc[1][0] = 84);                                                                                                                                                    assert(matc[1][1] = 69);                                                                                                                                                    assert(matc[1][2] = 54);                                                                                                                                                    assert(matc[2][0] = 138);                                                                                                                                                   assert(matc[2][1] = 114);                                                                                                                                                   assert(matc[2][2] = 90); 

}

void test16matpmul() {
        int row1[3] = {1, 2, 3}, row2[3] = {4, 5, 6}, row3[3] =  {7, 8, 9}, *mata[3],
            row4[3] = {9, 8, 7}, row5[3] = {6, 5, 4}, row6[3] = {3, 2, 1}, *matb[3],
            row7[3], row8[3], row9[3], *matc[3];

        mata[0] = row1;
        mata[1] = row2;
        mata[2] = row3;
        matb[0] = row4;
        matb[1] = row5;
        matb[2] = row6;
        matc[0] = row7;
        matc[1] = row8;
        matc[2] = row9;

        matpmul(mata, matb, matc, 3);                                                                                                                                                                                                                                                                                              
        assert(matc[0][0] =  30);                                                                                                                                                   assert(matc[0][1] = 24);                                                                                                                                                    assert(matc[0][2] = 18);                                                                                                                                                    assert(matc[1][0] = 84);                                                                                                                                                    assert(matc[1][1] = 69);                                                                                                                                                    assert(matc[1][2] = 54);                                                                                                                                                    assert(matc[2][0] = 138);                                                                                                                                                   assert(matc[2][1] = 114);                                                                                                                                                   assert(matc[2][2] = 90);

}	 

	
int main(void) {
    test01matscl();
    test02matpscl();
    test03mattrn(); 
    test04matptrn();
    test05matadd();
    test06matpadd();
    test07matmul();
    test08matpmul();
    test09matscl();
    test10matpscl();
    test11mattrn();
    test12matptrn();
    test13matadd();
    test14matpadd();   
    test15matmul();
    test16matpmul();  

    return 0;
}
