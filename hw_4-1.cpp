/*
 * Условие задачи:
 * 1. Создать контейнер, содержащий 10 000 случайных величин.
 *    Важное требование: числа должны быть не псевдослучайными 
 *    (истинно случайными, например, полученными из аппаратного ГСЧ 
 *    или системного источника энтропии), а не сгенерированы 
 *    стандартным алгоритмом std::rand().
 * 2. Самостоятельно реализовать 2 различных алгоритма сортировки 
 *    (например, Пузырьком и Быстрая сортировка).
 * 3. Отсортировать контейнер каждым из алгоритмов.
 * 4. Засечь и вывести время выполнения каждой сортировки.
 * 5. Определить и вывести на экран название наиболее быстрой сортировки.
 */

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
