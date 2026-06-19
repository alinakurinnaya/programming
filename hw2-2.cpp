/*
 * Условие задачи:
 * На основе заданного исходного списка необходимо сформировать два новых списка:
 * 1. В первый список поместить все положительные элементы.
 * 2. Во второй список поместить все отрицательные элементы.
 * 
 * Требование: элементы необходимо сортировать по возрастанию непосредственно 
 * в процессе их заполнения (при добавлении в новые списки).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SplitAndSort(const vector<int>& input, vector<int>& positive, vector<int>& negative) {
    for (int num : input) {
        if (num >= 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());
}

int main() {
    vector<int> input = {3, -2, 5, -1, 0, 4};
    vector<int> positive, negative;

    SplitAndSort(input, positive, negative);

    cout << "Positive elements sorted: ";
    for (int num : positive) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Negative elements sorted: ";
    for (int num : negative) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

