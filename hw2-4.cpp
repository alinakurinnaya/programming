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
#include <stack>
#include <string>

using namespace std;

bool IsBalanced(const string& brackets) {
    stack<char> stack;

    for (char bracket : brackets) {
        if (bracket == '(' or bracket == '[' or bracket == '{') {
            stack.push(bracket);
        } else if (bracket == ')' or bracket == ']' or bracket == '}') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((bracket == ')' and top != '(') ||
                (bracket == ']' and top != '[') ||
                (bracket == '}' and top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    string brackets;
    cout << "Enter a sequence of brackets: ";
    cin >> brackets;

    if (IsBalanced(brackets)) {
        cout << "The brackets sequence is balanced." << endl;
    } else {
        cout << "The brackets sequence is not balanced." << endl;
    }

    return 0;
}

