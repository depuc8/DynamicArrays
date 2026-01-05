#include<stdlib.h>
#include<stdio.h>
#include "DynA.h"

#define INITIAL_CAPACITY 4

/*
typedef struct DynamicArray{
	int *data;
	size_t size;
	size_t capacity;
}DynA;

void da_init(DynA *arr); DONE
void da_set(DynA *arr, size_t index, int value); DONE
int da_get(DynA *arr, size_t index); DONE
void da_pushback(DynA *arr, int value); 
void da_free(DynA *arr);
*/

void da_init(DynA *arr){
	
	arr->size = 0;
	arr->capacity = INITIAL_CAPACITY;
	arr->data = malloc(arr->capacity*sizeof(int));

	if(!arr->data){ 
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
}

void da_resize(DynA *arr, size_t new_capacity){

	int* new_data = realloc(arr->data,new_capacity*sizeof(int));
	if(!new_data){
		perror("realloc failed");
		exit(EXIT_FAILURE);
	}

	arr->data = new_data;
	arr->capacity = new_capacity;

}

void da_pushback(DynA *arr,int value){
	if(arr->size == arr->capacity){
		da_resize(arr, 2*arr->capacity);
	}

	arr->data[arr->size++] = value;

}

void da_set(DynA *arr, size_t index, int value){
	if(index >= arr->size){
		fprintf(stderr,"index out of bounds\n");
		exit(EXIT_FAILURE);
	}
	
	arr->data[index] = value;
	return;
}


int da_get(DynA *arr, size_t index){
	if(index >= arr->size){
		fprintf(stderr,"index out of bounds");
		exit(EXIT_FAILURE);
	}
	return arr->data[index];
}

void da_free(DynA *arr){
	free(arr->data);
	arr->data = NULL;
	arr->size = 0;
	arr->capacity = 0;
}
