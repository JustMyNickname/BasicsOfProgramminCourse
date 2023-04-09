#ifndef GITHUBPROJECT_VECTOR_H
#define GITHUBPROJECT_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

bool isEmpty(vector *v);

bool isFull(vector *v);

int getVectorValue(vector *v, size_t i);

void addElement(vector *v, int pos, int number);

void deleteElement(vector *v, int pos);

void pushBack(vector *v, int x);

void popBack(vector *v);

#endif //GITHUBPROJECT_VECTOR_H
