#include <stdlib.h>

typedef struct {
    int maxHeap[50001];
    int minHeap[50001];
    int sizeMax;
    int sizeMin;
} MedianFinder;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Max heapify up
void maxUp(MedianFinder* obj, int i) {
    while(i > 0 && obj->maxHeap[(i-1)/2] < obj->maxHeap[i]) {
        swap(&obj->maxHeap[i], &obj->maxHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Min heapify up
void minUp(MedianFinder* obj, int i) {
    while(i > 0 && obj->minHeap[(i-1)/2] > obj->minHeap[i]) {
        swap(&obj->minHeap[i], &obj->minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Max heapify down
void maxDown(MedianFinder* obj, int i) {
    int largest = i;
    int l = 2*i+1, r = 2*i+2;

    if(l < obj->sizeMax && obj->maxHeap[l] > obj->maxHeap[largest])
        largest = l;
    if(r < obj->sizeMax && obj->maxHeap[r] > obj->maxHeap[largest])
        largest = r;

    if(largest != i) {
        swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
        maxDown(obj, largest);
    }
}

// Min heapify down
void minDown(MedianFinder* obj, int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if(l < obj->sizeMin && obj->minHeap[l] < obj->minHeap[smallest])
        smallest = l;
    if(r < obj->sizeMin && obj->minHeap[r] < obj->minHeap[smallest])
        smallest = r;

    if(smallest != i) {
        swap(&obj->minHeap[i], &obj->minHeap[smallest]);
        minDown(obj, smallest);
    }
}

// Create
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->sizeMax = 0;
    obj->sizeMin = 0;
    return obj;
}

// Add number
void medianFinderAddNum(MedianFinder* obj, int num) {

    // Insert into maxHeap
    if(obj->sizeMax == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->sizeMax] = num;
        maxUp(obj, obj->sizeMax++);
    } else {
        obj->minHeap[obj->sizeMin] = num;
        minUp(obj, obj->sizeMin++);
    }

    // Balance heaps
    if(obj->sizeMax > obj->sizeMin + 1) {
        obj->minHeap[obj->sizeMin] = obj->maxHeap[0];
        minUp(obj, obj->sizeMin++);

        obj->maxHeap[0] = obj->maxHeap[--obj->sizeMax];
        maxDown(obj, 0);
    }
    else if(obj->sizeMin > obj->sizeMax) {
        obj->maxHeap[obj->sizeMax] = obj->minHeap[0];
        maxUp(obj, obj->sizeMax++);

        obj->minHeap[0] = obj->minHeap[--obj->sizeMin];
        minDown(obj, 0);
    }
}

// Find median
double medianFinderFindMedian(MedianFinder* obj) {
    if(obj->sizeMax == obj->sizeMin)
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    else
        return obj->maxHeap[0];
}

// Free
void medianFinderFree(MedianFinder* obj) {
    free(obj);
}