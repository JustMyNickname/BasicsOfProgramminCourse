#include <stdio.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"

void fillVectorFromOne(vector *v) {
    for (int i = 0; i < v->capacity; i++) {
        v->data[i] = i + 1;
    }
    v->size = v->capacity;
}

void test_atVector_notEmptyVector() {
    vector v = createVector(10);

    fillVectorFromOne(&v);

    assert(*atVector(&v, 2) == 3);
    assert(*atVector(&v, 4) == 5);
    assert(*atVector(&v, 8) == 9);
}
void test_atVector_requestToLastElement() {
    vector v = createVector(10);

    fillVectorFromOne(&v);

    assert(*atVector(&v, 0) == 1);

    assert(*atVector(&v, 9) == 10);
}
void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.data[0] = 1;
    v.size = 1;
    assert(*back(&v) == 1);
}
void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.data[0] = 1;
    v.size = 1;
    assert(*front(&v) == 1);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);

    pushBack(&v, 40);
    assert(v.data[0] == 40);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}


void test_pushBack_fullVector() {
    vector v = createVector(1);
    v.data[0] = 1;
    v.size = 1;
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
    test_atVector_notEmptyVector();
    test_popBack_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    tests();

    return 0;
}
