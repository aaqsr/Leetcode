#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

vector<string> stickers ={ "with","example","science" };
unordered_set<char> available;
string target= "thehat";
list<unordered_map<char, int>>stickMap;
unordered_map<char, int> tarMap;

void extract(string s) {
	vector<unordered_map<char, int>>toRemove;
	unordered_map<char, int> tempMap;
	for (auto i : s) {
		if (tempMap[i] < tarMap[i]) {
			tempMap[i] += 1;
			available.insert(i);
		}
	}
	bool greater=false;
	bool lesser=false;
	bool replaced = false;
	for (auto &it : stickMap) {
		greater=true;
		lesser=true;
		for (auto x : tarMap) {
			if (tempMap[x.first] > it[x.first]) {
				lesser = false;
			}
			else if (tempMap[x.first] != it[x.first]) {
				greater = false;
			}
			if (greater == false && lesser == false) {
				break;
			}
		}
		if (greater) {
			toRemove.push_back(it);
		} else if (lesser) {
			break;
		}
	}
	for (auto it : toRemove) {
		stickMap.remove(it);
	}
	if (lesser == false || greater == true) {
		stickMap.push_back(tempMap);
	}
}

void recur(unordered_map<char, int>& actMap, int n, bool& enough) {
	for (auto it : stickMap) {
		unordered_map<char, int> temp=actMap;
		for (auto i : it) {
			if (temp[i.first] < tarMap[i.first]) {
				temp[i.first] += i.second;
			}
		}
		if (n > 1) {
			recur(temp, n - 1, enough);
		}
		else {
			enough = true;
			for (auto it : tarMap) {
				if (temp[it.first] < it.second) {
					enough=false;
					break;
				}
			} 
		}
		if (enough) {
			break;
		}
	}

}

int main()
{
	for (auto i : target) {
		if (tarMap.count(i)) {
			tarMap[i] += 1;
		}
		else {
			tarMap[i] = 1;
		}
	}
	for (auto st : stickers) {
		extract(st);
	}
	for (auto it : tarMap) {
		if (it.second!=0 && available.find(it.first) == available.end()) {
			return false;
		}
	}

	bool en = false;
	int n = 0;
	unordered_map<char, int> t={};
	while (en == false) {
		n = n += 1;
		recur(t, n, en);
	}
	return n;
}
