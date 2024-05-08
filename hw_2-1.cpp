#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Container>
void Print(const Container& container, const string& delimiter) {
    auto it = container.begin();
    if (it != container.end()) {
        cout << *it;
        it++;
        for (; it != container.end(); it++) {
            cout << delimiter << *it;
        }
    }
    cout << endl;
}

int main() {
    vector<int> data = {1, 2, 3};
    Print(data, ", ");

    return 0;
}
