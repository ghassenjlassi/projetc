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

void test_init_grid(){
	int n =5;
grid c = createGrid(n);
    CU_ASSERT(set_size(s) == 0);
    set_free(&s);

}

void test_init_grid_random(){
	        
} 

void test_init_grid_file(){
	        
} 

void test_change_color(){
	        
}

void test_(){
	        
} 

void test_colorflood(){
	        
}

void test_fullgrid(){
	        
} 
