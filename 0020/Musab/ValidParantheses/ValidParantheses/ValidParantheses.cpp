// ValidParantheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;

int main()
{
    stack<char> paran;

    for (auto it : s) {
        if (it == '(' || it == '{' || it == '[') {
            paran.push(it);
        }
        else {
            if (paran.size() > 0) {
                char temp = paran.top();
                paran.pop();
                if (not( (temp=='(' && it == ')') || (temp=='[' && it == ']') || (temp=='{' && it == '}'))) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    if (paran.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}

