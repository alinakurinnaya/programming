#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

int GenerateRandomNumber(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

void BubbleSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 10000;
    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        numbers[i] = GenerateRandomNumber(1, 10000);
    }

    vector<int> numbersBubble = numbers;

    auto startBubble = chrono::high_resolution_clock::now();
    BubbleSort(numbersBubble);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double> durationBubble = endBubble - startBubble;

    auto startStdSort = chrono::high_resolution_clock::now();
    sort(numbers.begin(), numbers.end());
    auto endStdSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationStdSort = endStdSort - startStdSort;


    if (durationBubble < durationStdSort) {
        cout << "Bubble sorting is faster." << endl;
        cout << "Bubble sorting run time is: " << durationBubble.count() << " seconds" << endl;
    } else {
        cout << "Standard sorting is faster." << endl;
        cout << "Standard sorting run time is: " << durationStdSort.count() << " seconds" << endl;
    }

    return 0;
}
