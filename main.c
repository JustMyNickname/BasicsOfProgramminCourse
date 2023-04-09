#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"

void fillVectorFromOne(vector *v) {
    for (int i = 0; i < v->capacity; i++) {
        v->data[i] = i + 1;
    }
    v->size = v->capacity;
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);

    pushBack(&v, 40);
    assert(v.data[0] == 40);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);
    v.data[0] = 1;
    pushBack(&v, 2);
    assert(v.data[1] == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);

    pushBack(&v, 3);
    assert(v.data[2] == 3);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void tests() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void showMeCapacityAndSize(vector *v) {
    printf("\ncapacity = %zu\nsize = %zu\n", v->capacity, v->size);
}


void outputVector(vector * const v) {
    for (int i = 0; i < v->capacity; ++i) {
        printf("%d ", v->data[i]);
    }
}

int main() {
    vector v = createVector(0);

    fillVectorFromOne(&v);

    //assert(getVectorValue(&v, 5) == 6);
   // assert(getVectorValue(&v, 19) == 20);
    //assert(getVectorValue(&v, 0) == 1);
    //addElement(&v, 0, 7);
    //addElement(&v, 2, 66);

   // deleteElement(&v, 2);


    outputVector(&v);

    printf("\n%zu\n", v.size);

    printf("isNull? %d", v.data == NULL ? 1 : 0);


    free(v.data);

    return 0;
}
