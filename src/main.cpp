#include <iostream>
using namespace std;

class MaxHeap {
private:
    int *heapArray;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heapArray[left] > heapArray[largest])
            largest = left;
        if (right < size && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heapArray = new int[cap];
    }

    ~MaxHeap() { delete[] heapArray; }

    void insertRaw(int value) {
        if (size == capacity) {
            cout << "Heap penuh!\n";
            return;
        }
        heapArray[size++] = value;
    }

    void printArray() {
        cout << "Array sebelum Max-Heap: ";
        for (int i = 0; i < size; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyDown(i);
    }

    void printHeap() {
        cout << "Array setelah menjadi Max-Heap: ";
        for (int i = 0; i < size; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h(10);

    // Masukkan elemen tanpa heapify
    h.insertRaw(10);
    h.insertRaw(40);
    h.insertRaw(30);
    h.insertRaw(50);
    h.insertRaw(20);

    h.printArray();  // Output sebelum menjadi Max-Heap

    h.buildMaxHeap();  // Mengubah menjadi Max-Heap
    h.printHeap();  // Output setelah menjadi Max-Heap

    return 0;
}