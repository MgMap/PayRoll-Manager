//
// Created by minau on 4/27/2023.
//

#ifndef SFML_PROJECT_HEAP_H
#define SFML_PROJECT_HEAP_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Heap {
private:
    vector<T> heap;

    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    Heap() {}

    void push(T value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop() {
        if (heap.empty()) {
            return;
        }

        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    T top() const {
        return heap.front();
    }

    bool empty() const {
        return heap.empty();
    }
    int size()
    {
        return heap.size();
    }
    vector<T> getHeap()
    {
        return heap;
    }
};



#endif //SFML_PROJECT_HEAP_H
