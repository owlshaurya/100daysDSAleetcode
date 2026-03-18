#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(KthLargest* obj, int i) {
    while(i > 0 && obj->heap[(i-1)/2] > obj->heap[i]) {
        swap(&obj->heap[(i-1)/2], &obj->heap[i]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(KthLargest* obj, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < obj->size && obj->heap[left] < obj->heap[smallest])
        smallest = left;

    if(right < obj->size && obj->heap[right] < obj->heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&obj->heap[i], &obj->heap[smallest]);
        heapifyDown(obj, smallest);
    }
}

// Insert into heap
void insert(KthLargest* obj, int val) {
    obj->heap[obj->size] = val;
    heapifyUp(obj, obj->size);
    obj->size++;
}

// Remove min
void removeMin(KthLargest* obj) {
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;
    heapifyDown(obj, 0);
}

// Constructor
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * 10001);
    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++) {
        insert(obj, nums[i]);
        if(obj->size > k)
            removeMin(obj);
    }

    return obj;
}

// Add element
int kthLargestAdd(KthLargest* obj, int val) {
    insert(obj, val);

    if(obj->size > obj->k)
        removeMin(obj);

    return obj->heap[0];  // kth largest
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}