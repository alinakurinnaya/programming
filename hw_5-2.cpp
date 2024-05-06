#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

void merge(vector<int>& data, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    vector<int> left(n1);
    vector<int> right(n2);
    
    for (int i = 0; i < n1; ++i) {
        left[i] = data[start + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = data[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = start;
    
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            ++i;
        } else {
            data[k] = right[j];
            ++j;
        }
        ++k;
    }
    
    while (i < n1) {
        data[k] = left[i];
        ++i;
        ++k;
    }
    
    while (j < n2) {
        data[k] = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& data, int start, int end) {
    if (start >= end) {
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    thread t1(mergeSort, ref(data), start, mid);
    thread t2(mergeSort, ref(data), mid + 1, end);
    
    t1.join();
    t2.join();
    
    merge(data, start, mid, end);
}

int main() {
    const int size = 10;
    vector<int> data = {9, 4, 6, 7, 3, 8, 5, 2, 1, 10};
    
    mergeSort(data, 0, size - 1);
    
    cout << "Sorted array: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
