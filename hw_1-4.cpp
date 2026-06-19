/*
 * Условие задачи:
 * Число N, записанное в факториальной системе счисления как 
 * N = an an-1 ... a3 a2 a1 (где ak <= k), означает, что:
 * N = a1 * 1! + a2 * 2! + a3 * 3! + ... + an-1 * (n-1)! + an * n!
 * 
 * Требование:
 * Написать функцию, которая принимает натуральное число и печатает 
 * на экран его представление в факториальной системе счисления.
 * 
 * Важное замечание по формату вывода:
 * Разряды необходимо отделять друг от друга точками, так как 
 * значение разряда может быть больше одной цифры (например, 12.3.1.0).
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
