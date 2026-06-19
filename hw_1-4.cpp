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
