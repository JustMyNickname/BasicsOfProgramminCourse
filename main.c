#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"

void fillVector(vector *v) {
    for (int i = 0; i < v->capacity; i++) {
        v->data[i] = i + 1;
    }
    v->size = v->capacity;
}

void outputVector(vector * const v) {
    for (int i = 0; i < v->capacity; ++i) {
        printf("%d ", v->data[i]);
    }
}

int main() {
    vector v = createVector(20);

    fillVector(&v);

    outputVector(&v);

    printf("\n%zu\n", v.size);

    printf("isNull? %d", v.data == NULL ? 1 : 0);


    free(v.data);

    return 0;
}
