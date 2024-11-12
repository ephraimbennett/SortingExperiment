#include "Insertion.h"

void insertionSort(std::vector<int> vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;

        // Move elements of vec[0..i-1] that are greater than key to one position ahead
        // of their current position
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}