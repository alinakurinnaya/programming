/*
 * Условие задачи (использование адаптеров контейнеров):
 * На вход подаётся скобочная последовательность — строка, состоящая 
 * из символов скобок: ()[]{}.
 * 
 * Необходимо определить, является ли эта последовательность правильной.
 * Правильная скобочная последовательность должна удовлетворять условиям:
 * 1. Каждой открывающей скобке соответствует ровно одна закрывающая 
 *    того же типа.
 * 2. Пары скобок корректно вложены друг в друга 
 *    (например, "({[]})" — правильно, а "([)]" — неправильно).
 */

#include <iostream>
#include <vector>

using namespace std;

void factorialBaseRepresentation(int n) {
    vector<int> representation;
    int factorial = 1;
    
    while (n > 0) {
        representation.push_back(n % (factorial + 1));
        n /= (factorial + 1);
        factorial++;
    }

    for (int i = representation.size() - 1; i >= 0; i--) {
        cout << representation[i];
        if (i != 0) {
            cout << ".";
        }
    }
}

int main() {
    int number = 463;

    cout << "Number representation " << number << " in the factorial number system: ";
    factorialBaseRepresentation(number);
    cout << endl;

    return 0;
}
