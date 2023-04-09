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
        v->capacity = newCapacity;
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void addElement(vector *v, int pos, int number) {
    if (v->size < v->capacity) {
        fprintf(stderr, "Vector is full!");
        exit(1);
    }

    for (int i = v->size - 1; i >= pos; i--)
        v->data[i + 1] = v->data[i];

    v->data[pos] = number;
    v->size++;
}

void deleteElement(vector *v, int pos) {
    if (v->size == 0) {
        fprintf(stderr, "Vector is empty!");
        exit(1);
    }

    for (int i = pos; i < v->size - 1; i++)
        v->data[i] = v->data[i + 1];
    v->size--;
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
        v->data[v->size] = x;
        v->size++;
    } else if (v->capacity == v->size) {
        reserve(v, v->capacity * 2);
        v->data[v->size] = x;
        v->size++;
    } else {
        v->data[v->size] = x;
        v->size++;
    }
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Vector is empty!");
        exit(1);
    }

    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->capacity) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }

    int *p = v->data;
    for (int i = 0; i < index; i++) {
        p++;
    }

    return p;
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Vector is empty!");
        exit(1);
    }

    int *p = atVector(v, v->size - 1);

    return p;
}

int* front(vector *v) {
    return v->data;
}