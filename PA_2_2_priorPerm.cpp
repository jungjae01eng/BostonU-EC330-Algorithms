// Jungjae Lee
// Boston University College of Engineering
// EC 330 Programming Assignment 1 Question 2b
// February 23, 2023

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> priorPerm(vector<int> P) {
    bool run = true;
    int P_size = P.size();
    int i = P_size - 1;

    while (run) {
        if (P[i] < P[i-1]) {
            if (i == (P_size - 1)) {
                swap(P[i - 1], P[i]);
            } else if (P[i - 1] < P[i + 1]) {
                swap(P[i], P[i - 1]);
                swap(P[i], P[P_size-1]);
            } else if (P[i - 1] > P[i + 1]) {
                swap(P[i - 1], P[i + 1]);
                swap(P[i], P[P_size-1]);
            }

            if ((i == 1) && (P[i-1] < P[P_size])) {
                P.insert(begin(P), P.back());
                P.pop_back();
            }
            run = false;
        } else {
            i--;
            if (i == 0) {
                run = false;
            }
        }
    }

    return P;
}

int main() {
    vector<int> const BU_test_0 = {1573, 7305, 2204};
    vector<int> const BU_test_1 = {1573, 2204, 7305};
    vector<int> const BU_test_2 = {2204, 1573, 7305};
    vector<int> const BU_test_3 = {5904, 2429, 3681, 4102};

    cout << "BU_test: ";
    for (int i = 0; i < BU_test_2.size(); i++) {
        cout << BU_test_2[i] << ", ";
    }
    cout << endl;

    priorPerm(BU_test_2);

    return 0;
}