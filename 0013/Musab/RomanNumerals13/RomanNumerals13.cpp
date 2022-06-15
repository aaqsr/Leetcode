// RomanNumerals13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
string s = "CIX";

int main()
{
    int tally = 0;
    unordered_map<string, int> convertMap {{"I", 1}, { "V", 5 }, { "X", 10 }, { "L",50 }, { "C",100 }, { "D",500 }, { "M",1000 }, { "IV",4 }, { "IX",9 }, { "XL",40 }, { "XC",90 }, { "CD",400 }, { "CM",900 }};
    for (int i = 0; i < s.length();i++) {
        if (i<s.length() - 1 && convertMap.count(s.substr(i, 2))) {
            tally += convertMap[s.substr(i, 2)];
            i++;
        }
        else {
            tally += convertMap[s.substr(i, 1)];
        }
    }
    cout << tally;
}
