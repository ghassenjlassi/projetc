/**
 * \file UnitTests.c
 * \brief Tests unitaire des fonctions de la grille
 * \author O'Calm
 * \version 0.1
 * \date 19 avril 2017
 *
 * Tests Unitaires :)
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "grid.c"

void test_init_grid(void){
	int n =5;
Grid c = createGrid(n);
    CU_ASSERT(c.size == n);
    CU_ASSERT(sizeof c.block == sizeof (n*n*sizeof(char)));
}

void test_init_grid_random(){
	   int n =6;
Grid c = createGrid(n);
    CU_ASSERT(c.size == n);
    CU_ASSERT(sizeof c.block == sizeof (n*n*sizeof(char)));       
} 

void test_init_grid_file(){
	        
} 

void test_change_color(){
	Grid c = initGridFromFile("grilleTest.txt"); 
    changeCaseColor(&c,3,2,'B');
     CU_ASSERT(c.block [3][2] == 'B');      
}

void test_(){
	        
} 

void test_colorflood(){
	        
}

void test_fullgrid(){
    int n=5;
	    Grid c = createGrid(n);
        int i,j;
        for (int i = 0; i < n; i++)
            {
               for (int j = 0; j < n; j++)
               {
                   c.block[i][j]='B';
               }
            }    
CU_ASSERT(checkFullGrid(c) == true);
} 
int main() {
 	CU_pSuite pSuite = NULL;

 	if (CU_initialize_registry() != CUE_SUCCESS) {
 		return CU_get_error();
 	}

 	pSuite = CU_add_suite("Suite",NULL,NULL);

 	if (pSuite==NULL) {
 		CU_cleanup_registry();
 		return CU_get_error();
 	}

     if (CU_add_test (pSuite, "test_init_grid()",test_init_grid)==NULL) {
         CU_cleanup_registry();
         return CU_get_error();
     }
     if (CU_add_test (pSuite, "test_init_grid_random()",test_init_grid_random)==NULL) {
         CU_cleanup_registry();
         return CU_get_error();
     }
    /*  if (CU_add_test (pSuite, "test_change_color()",test_change_color)==NULL) {
         CU_cleanup_registry();
         return CU_get_error();
     }*/
     if (CU_add_test (pSuite, "test_fullgrid",test_fullgrid)==NULL) {
         CU_cleanup_registry();
         return CU_get_error();
     }


     CU_basic_set_mode(CU_BRM_VERBOSE);
     CU_basic_run_tests();
     CU_cleanup_registry();

 	return 0;
 }
