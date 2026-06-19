/*
 * Условие задачи:
 * Определим последовательность натуральных чисел рекурсивно: следующее число 
 * равно сумме квадратов цифр текущего числа. 
 * 
 * Если последовательность придёт к 1, то начальное число называется 
 * счастливым. 
 * Примеры:
 * - 19 — счастливое число (19 -> 82 -> 68 -> 100 -> 1).
 * - 2 — не счастливое число, последовательность зацикливается 
 *   (2 -> 4 -> 16 -> 37 -> 18 -> 65 -> 61 -> 37 -> ...).
 * 
 * Требование:
 * Написать функцию, которая проверяет, является ли переданное ей 
 * натуральное число счастливым.
 */

#include <iostream>
#include <unordered_set>

using namespace std;

int squareSumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappyNumber(int n, unordered_set<int>& visited) {
    if (n == 1) {
        return true;
    }

    if (visited.find(n) != visited.end()) {
        return false;
    }

    visited.insert(n);
    int next = squareSumOfDigits(n);
    return isHappyNumber(next, visited);
}

bool isHappy(int n) {
    unordered_set<int> visited;
    return isHappyNumber(n, visited);
}

int main() {
    int number = 2;

    if (isHappy(number)) {
        cout << number << " - lucky number" << endl;
    } else {
        cout << number << " - unlucky number" << endl;
    }

    return 0;
}
