#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namwspace std;

string FindMostFrequentWord(const string& text) {
    map<string, int> wordCount;
    istringstream iss(text);

    string word;
    while (iss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }

    string mostFrequentWord;
    int maxCount = 0;

    for (const auto& pair : wordCount) {
        if (pair.second > maxCount or (pair.second == maxCount and pair.first < mostFrequentWord)) {
            mostFrequentWord = pair.first;
            maxCount = pair.second;
        }
    }

    return mostFrequentWord;
}

int main() {
    string text = "This is a sample text with some words. This text contains some words that repeat more often.";

    string mostFrequentWord = FindMostFrequentWord(text);

    cout << "The most frequent word is: " << mostFrequentWord << endl;

    return 0;
}

