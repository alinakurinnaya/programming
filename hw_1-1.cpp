/*
 * Условие задачи:
 * Написать функцию, которая выполняет поиск заданного объекта в массиве.
 * 
 * Требования:
 * - Если объект найден в массиве, функция должна вернуть его индекс.
 * - Если объект отсутствует в массиве, функция должна вернуть -1.
 */

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};

    int target = 7;
    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Element found at position: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
