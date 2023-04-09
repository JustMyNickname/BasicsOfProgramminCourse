#include "vector.h"

vector createVector(size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else {
        v->data = realloc(v->data, sizeof(int) * newCapacity);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    if (v->size > newCapacity)
        v->size = newCapacity;


}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = realloc(v->data, sizeof(int) * v->size); v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
}