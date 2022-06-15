// Prefixes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> strs;

int main()
{
    int small = 999999;
    for (auto it : strs) {
        if (it.length() < small) {
            small = it.length();
        }
    }
    int pos=0;
    while (pos<small) {
        char temp = strs[0][pos];
        for (auto it : strs) {
            if (it[pos] != temp) {
                small = 0;
                pos -= 1;
                break;
            }
        }
        pos += 1;
    }
    cout << strs[0].substr(0, pos);
}