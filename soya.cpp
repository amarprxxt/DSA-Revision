#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a city is a Type A city (connected to all other Type A cities)
bool isTypeACity(int **arr, int n, int city) {
    for (int i = 0; i < n; ++i) {
        if (i != city) {
            if (arr[city][i] != 1 || arr[i][city] != 1) {
                return false;
            }
        }
    }
    return true;
}

void connectedVertex(int **arr, int n) {
    vector<int> typeA;

    // Step 1: Find Type A cities (fully connected with all others)
    for (int i = 0; i < n; ++i) {
        bool isTypeA = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && (arr[i][j] != 1 || arr[j][i] != 1)) {
                isTypeA = false;
                break;
            }
        }
        if (isTypeA) {
            typeA.push_back(i);
        }
    }

    vector<int> typeB;

    // Step 2: Cities connected to all Type A cities are Type B
    for (int i = 0; i < n; ++i) {
        if (find(typeA.begin(), typeA.end(), i) != typeA.end()) continue; // skip Type A

        bool isTypeB = true;
        for (int a : typeA) {
            if (arr[i][a] != 1 || arr[a][i] != 1) {
                isTypeB = false;
                break;
            }
        }
        if (isTypeB) typeB.push_back(i);
    }

    sort(typeB.begin(), typeB.end());
    for (int i = 0; i < typeB.size(); ++i) {
        if (i > 0) cout << " ";
        cout << typeB[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    connectedVertex(arr, n);
    return 0;
}
