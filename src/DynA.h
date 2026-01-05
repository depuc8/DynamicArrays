#ifndef HEAP_H
#define HEAP_H

typedef struct DynamicArray{
	int *data;
	size_t size;
	size_t capacity;
}DynA;

void da_init(DynA *arr);
void da_resize(DynA *arr,size_t new_capacity);
void da_set(DynA *arr, size_t index, int value);
int da_get(DynA *arr, size_t index);
void da_pushback(DynA *arr, int value);
void da_free(DynA *arr);

#endif
