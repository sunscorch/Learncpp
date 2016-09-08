#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildPreArray(const string& pattern) {
	vector<int> res(pattern.size(), 0);
	int index = 0;
	for (int i = 1; i < pattern.size(); ) {
		if (res[i] == pattern[index]) {
			res[i] = index + 1;
			i++;
			index++;
		}else {
			//ex : aabaabaaa   res : 010123452 // last a  match index5 b not match, then match res[5-1] = 2, 
			// which is still not match, then match res[2-1], final match , here j = 1, 
			if (index != 0) {
				index = res[index-1];
			}else {
				res[i] = 0;
				i++;
			}
		}
	}
	return res;
} 
bool KMP(const string& text, const string& target) {
	vector<int> preArray;
	preArray = buildPreArray(target);
	int i = 0, j = 0;
	while (i < text.size() && j < target.size()) {
		if (text[i] == target [j]) {
			i++;
			j++;
		}else {
			if (j != 0) {
				j = preArray[j-1];
			}else {
				i++;
			}
		}
		if (j == target.size()) cout <<(i - j) << endl;
		if (j == target.size()) return true; 
	}
	return false;
}

int main() {
	 string str = "abacababc";
	 string target = "abab";
	 KMP(str, target);
}



