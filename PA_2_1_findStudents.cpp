// Jungjae Lee
// Boston University College of Engineering
// EC 330 Programming Assignment 2 Question 2a
// February 20, 2023

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector<int> findStudents(vector<int> id) {
    vector<pair<int, int>> idVec;               // ID Vectors
    vector<pair<int, int>> sorted_idVec;        // Sorted ID Vectors
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    vector<int> results;

    //// ======================================== Assign {number, id[]} on idVec =======================================
    for (int i = 0; i < id.size(); i++) {
        idVec.push_back(make_pair(i, id[i]));
    }

    //// ================================= Assign {number, id[] % 330} on sorted_idVec =================================
    for (int i = 0; i < id.size(); i++) {
        sorted_idVec.push_back(make_pair(i, id[i]%330));
    }

    //// ====================== Sorting sorted_idVec of the second row from the least to greatest ======================
    sort(sorted_idVec.begin(), sorted_idVec.end(), [](pair<int, int> a, const pair<int, int> b) {
        return a.second < b.second;
    });

    //// ======================= Compare (smallest + greatest) with (smallest + second smallest) =======================
    int idVecSize = sorted_idVec.size();        // size of the vectors, so we can use it for loops
    int low = 0;                                    // start from 0 and increments (increases the smallest vector)
    int high = 1;
    int max = 0;
    int counter = 0;

    for (int i = 1; i <= idVecSize; i++) {
        max += i;
    }

    bool test = true;
    while (test) {
        if ((low == high) || (high == idVecSize)) {
            // change low & reset high
            low++;
            high = low + 1;
        } else {
            v1.push_back(sorted_idVec[low]);        // least modules in k
            v1.push_back(sorted_idVec[high]);
            high++;
        }
        counter++;
        if ((counter == max) || (low == high)) {
            test = false;
        } else {
            test = true;
        }
    }

    //// ============================================== Compare all in v1 ==============================================
    int sizeofv1 = v1.size();

    int z = 0;
    for (int i = 0; i < sizeofv1; i++) {
        v2.push_back(make_pair(z, (v1[i].second + v1[i+1].second)%330));
        i++;
        z++;
    }

    sort(v2.begin(), v2.end(), [](pair<int, int> a, const pair<int, int> b) {
        return a.second < b.second;
    });

    int r1 = (v2[0].first)*2;
    int r2 = (v1[r1].first);
    int r3 = (v1[r1 + 1].first);

    results.push_back(idVec[r2].second);
    results.push_back(idVec[r3].second);

    return results;
}


int main () {
    //// ================================================== Test Sets ==================================================
    vector<int> const BU_test_0 = {7305, 2204, 1573};                                       // PASS!!
    vector<int> const BU_test_1 = {8627, 2899, 4444, 2671, 4597};                           // PASS!!
    vector<int> const BU_test_3 = {2428, 2324, 1698, 6141, 3698, 3839};                     // PASS!!
    vector<int> const BU_test_5 = {6589, 6851, 5990, 4193, 7509, 6606, 9356};               // failed - received {5990, 6589}, should be {4193, 9356}
    vector<int> const BU_test_6 = {9174, 1881, 2266, 4572, 7208, 8650, 9118, 8531};         // failed - received {2266, 8650}, should be {8650, 9174}
    vector<int> const BU_test_8 = {5338, 2148, 5809, 5698, 8713, 3078, 7611, 3266, 9612};   // failed - received {3266, 9612}, should be {5809, 8713}
    vector<int> const BU_test_11 = {1630, 9239, 1067, 7826, 4469, 5275, 7630, 5947, 8502, 5710};
    vector<int> const BU_test_12 = {9055, 2131, 7035, 6506, 7982, 3709, 9762, 7959, 4880, 6680};
    vector<int> const BU_test_13 = {3199, 8987, 3639, 6511, 9991, 3443, 3937, 2710, 3838, 3231, 8874};
    vector<int> const BU_test_14 = {9148, 4822, 4997, 8315, 2223, 9052, 8008, 7007, 5293, 7233, 2897};
    vector<int> const BU_test_15 = {1804, 9086, 5940, 4625};                                // failed - received {5940, 4625}, should be {1804, 9086}
    vector<int> const BU_test_16 = {1853423596, 2057650620, 2087397582, 1015940687, 1281688355, 1092615236, 1457380756, 1750268862};    // PASS!!
    vector<int> const BU_test_18 = {111, 174, 96, 58, 161, 160, 194};                       // PASS!!


    cout << "=============== Set 1 ===============" << endl;
    cout << "Numbers: ";
    for (int i : BU_test_13) {
        cout << i << ", ";
    }
    cout << endl;

    vector<int> results = findStudents(BU_test_13);
    cout << "=============== Set Completed ===============" << endl;

    cout << "results: ";
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << ", ";
    }
    cout << endl;

    return 0;
}
