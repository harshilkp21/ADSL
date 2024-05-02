#include <iostream>
#include <algorithm>

using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void heapSortDescending(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortAscending(int arr[], int n) {
    buildMinHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int size;
    cout << "Enter the size of the heap: ";
    cin >> size;
    int* maxHeap = new int[size];
    int* minHeap = new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> maxHeap[i];
        minHeap[i] = maxHeap[i];
    }
    heapSortDescending(maxHeap, size);
    heapSortAscending(minHeap, size);
    cout << "Sorted Max heap (descending order): ";
    for (int i = 0; i < size; i++) {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    cout << "Sorted Min heap (ascending order): ";
    for (int i = 0; i < size; i++) {
        cout << minHeap[i] << " ";
    }
    cout << endl;
    delete[] maxHeap;
    delete[] minHeap;
    return 0;
}
