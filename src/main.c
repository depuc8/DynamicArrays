#include <stdio.h>
#include "DynA.h"

int main(void) {
    DynA arr; 

    printf("Initializing dynamic array...\n");
    da_init(&arr);

    printf("Pushing values:\n");
    for (int i = 0; i < 10; i++) {
        da_pushback(&arr, i * 10);
        printf("  pushed %d (size=%zu, capacity=%zu)\n",
               i * 10, arr.size, arr.capacity);
    }

    printf("\nArray contents:\n");
    for (size_t i = 0; i < arr.size; i++) {
        printf("  arr[%zu] = %d\n", i, da_get(&arr, i));
    }

    printf("\nSetting arr[5] = 999\n");
    da_set(&arr, 5, 999);

    printf("\nArray after set:\n");
    for (size_t i = 0; i < arr.size; i++) {
        printf("  arr[%zu] = %d\n", i, da_get(&arr, i));
    }

    printf("\nFreeing array...\n");
    da_free(&arr);

    printf("Done.\n");
    return 0;
}

