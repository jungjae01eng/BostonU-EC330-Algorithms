// Jungjae Lee
// Boston University College of Engineering
// EC 330 Assignment 1 Question 6a
// February 8, 2023

#include "PA_1_1_fun.h"
#include <iostream>
#include <map>

using namespace std;
map<pair<int, int>, int> DICTIONARY;

unsigned int fun(unsigned int x, unsigned int y) {
    unsigned int result;

    if (y == 0) {
        if (x == 0) {
            return 1;       // when both x and y are zero
        } else {
            return x+1;     // when only y are zero
        }
    } else if (x == 0) {    // when only x are zero
        if (DICTIONARY[make_pair(0, y)] == 0) {
            return DICTIONARY[make_pair(0, y)] = fun(1, y-1);  // it doesn't exist
        } else {
            return DICTIONARY[make_pair(0, y)];         // it already exist
        }
    } else {
        if (DICTIONARY[make_pair(x, y)] == 0) {
            return DICTIONARY[make_pair(x, y)] = fun(x-1, fun(x-1, y-1));  // it doesn't exist
        } else {
            return DICTIONARY[make_pair(x, y)];         // it already exist
        }
    }
}

int main() {
    unsigned int user_x;
    unsigned int user_y;

    cout << "Please enter x: ";
    cin >> user_x;

    cout << "Please enter y: ";
    cin >> user_y;

    unsigned int result = fun(user_x, user_y);

    cout << "result: " << result << endl;

    return 0;
}