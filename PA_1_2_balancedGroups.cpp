// Jungjae Lee
// Boston University College of Engineering
// EC 330 Programming Assignment 1 Question 6b
// February 8, 2023

#include "PA_1_2_balancedGroups.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

Assignment balancedGroups(std::vector<int> const &birthdays) {
    int sum1 = 0;
    int sum2 = 0;
    vector<int> group1;
    vector<int> group2;

    vector<int> sorted = birthdays;
    sort(sorted.begin(), sorted.end(), greater<int>());


    for (int i : sorted) {
        if (sum1 <= sum2) {
            sum1 += i;
            group1.push_back(i);
        } else {
            sum2 += i;
            group2.push_back(i);
        }
    }


    int diff;
    if (sum1 == sum2) {
        diff = 0;
    } else if (sum1 > sum2) {
        diff = sum1 - sum2;
    } else {
        diff = sum2 - sum1;
    }

    cout << "group1: ";
    for (int i = 0; i < group1.size(); i++) {
        cout << group1[i] << " ";
    }
    cout << endl;

    cout << "group2: ";
    for (int i = 0; i < group2.size(); i++) {
    cout << group2[i] << " ";
    }
    cout << endl;

    cout << diff << endl;

    return Assignment(diff, {group1}, {group2});
}

int main() {
    int result;
    vector<int> const birthdays = {31, 27, 5, 19, 20};

    balancedGroups(birthdays);
    cout << endl;

    return 0;
}
