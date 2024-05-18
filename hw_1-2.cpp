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
