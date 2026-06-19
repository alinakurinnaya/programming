/*
 * Условие задачи:
 * Вам надо написать функцию аналогичную Print, которая умеет печатать 
 * в поток std::cout элементы переданного контейнера через указанную 
 * строку-разделитель. 
 * 
 * Первый аргумент функции — контейнер. Гарантируется, что по этому 
 * контейнеру можно проитерироваться с помощью стандартного цикла 
 * range-based for, и что элементы контейнера можно напечатать в поток 
 * std::cout с помощью стандартного оператора <<.
 * 
 * Второй аргумент функции — строка-разделитель, которую надо печатать 
 * между элементами. В конце необходимо напечатать перевод строки \n.
 */

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
