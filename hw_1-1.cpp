/*
 * Условие задачи:
 * Вам надо написать функцию аналогичную Print, которая умеет печатать 
 * в поток std::cout элементы переданного контейнера через указанную 
 * строку-разделитель. 
 * 
 * Первый аргумент функции — контейнер. Гарантируется, что по этому 
 * контейнеру можно проитерироваться с помощью стандартного цикла 
 * range-based for, и что элементы контейнера можно напечатать в поток 
 * std::cout с помощью стандартного оператора <<.
 * 
 * Второй аргумент функции — строка-разделитель, которую надо печатать 
 * между элементами. В конце необходимо напечатать перевод строки \n.
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
