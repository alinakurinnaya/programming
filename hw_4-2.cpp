/*
 * Условие задачи (сравнение производительности контейнеров):
 * Необходимо использовать красно-черное дерево (в C++ стандартной 
 * реализацией является std::map или std::set) и любой другой контейнер 
 * на выбор (например, std::vector, std::list или std::unordered_set).
 * 
 * Требования:
 * 1. Сгенерировать 500 случайных неповторяющихся чисел и заполнить 
 *    ими оба выбранных контейнера.
 * 2. Засечь и сравнить время выполнения операции поиска элемента 
 *    в обоих контейнерах.
 * 3. Засечь и сравнить время выполнения операции добавления 
 *    нового элемента в оба контейнера.
 */

#include <iostream>
#include <set>
#include <map>
#include <random>
#include <chrono>

using namespace std;

template <typename Key, typename Value>
using RedBlackTree = map<Key, Value>;

template <typename T>
using Container = set<T>;

int main() {
    const int N = 500;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, N * 2);

    RedBlackTree<int, int> rbTree;
    Container<int> container;

    for (int i = 0; i < N; ++i) {
        int num = dis(gen);
        rbTree[num] = num;
        container.insert(num);
    }

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int num = dis(gen);
        rbTree.find(num);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> searchTime = end - start;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        int num = dis(gen);
        rbTree[num] = num;
    }
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> insertTime = end - start;

    cout << "Search time in a red-black tree is: " << searchTime.count() << " seconds" << endl;
    cout << "Time of adding a new item to a red-black tree: " << insertTime.count() << " seconds" << endl;

    return 0;
}

