#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void CalculateHeights(const map<string, string>& familyTree) {
    map<string, int> heights;
    vector<string> roots;

    for (const auto& pair : familyTree) {
        heights[pair.first] = 0;
    }

    for (const auto& pair : familyTree) {
        if (heights.find(pair.second) == heights.end()) {
            roots.push_back(pair.second);
        }
    }

    for (const string& root : roots) {
        int height = 0;
        vector<string> stack{root};

        while (!stack.empty()) {
            string current = stack.back();
            stack.pop_back();

            for (const auto& pair : familyTree) {
                if (pair.second == current) {
                    stack.push_back(pair.first);
                    heights[pair.first] = height + 1;
                }
            }

            height++;
        }
    }

    for (const auto& pair : heights) {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main() {
    int n;
    cin >> n;

    map<string, string> familyTree;
    for (int i = 0; i < n-1; i++) {
        string child, parent;
        cin >> child >> parent;
        familyTree[child] = parent;
    }

    CalculateHeights(familyTree);

    return 0;
}

