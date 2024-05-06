#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>

using namespace std;

void findMaxSum(const vector<int>& data, int& result, int start, int end) {
    vector<int> subArray(data.begin() + start, data.begin() + end);
    sort(subArray.begin(), subArray.end(), greater<int>());
    
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += subArray[i];
    }
    
    result = sum;
}

int main() {
    const int size = 1000;
    vector<int> data(size);
    
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 1000;
    }
    
    int result1, result2;
    
    thread t1(findMaxSum, ref(data), ref(result1), 0, size/2);
    thread t2(findMaxSum, ref(data), ref(result2), size/2, size);
    
    t1.join();
    t2.join();
    
    cout << "Total sum of the 3 largest elements: " << result1 + result2 << endl;
    
    return 0;
}
