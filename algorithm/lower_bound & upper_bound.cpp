#include <iostream>
#include <vector>
using namespace std;

//implement lower_bound ; 
// find the first index , A[index] >= target

int lower_bound(vector<int>& A, int target) {
	int l = 0, r = A.size(); // very important , r = A.size(), rather than A.size() - 1
	while (l < r) {
		int m = l + (r - l)/2;
		if(A[m] < target){
			l = m + 1;   //search range [m+1, right]
		}else{
			r = m;       // search range [l, m], we should include m rather than m+1, 
		}
	}

	return l;
}

//implement lower_bound ; 
// find the first index , A[index] > target
int upper_bound(vector<int>& A, int target) {
	int l = 0, r = A.size();
	while (l < r) {
		int m = l + (r - l)/2;
		if(A[m] <= target){
			l = m + 1 ;   
		}else{
			r = m;   
		}    
	}

	return l;
}
int main(){
	vector<int> test0 {1};
	cout << lower_bound(test0, 2) << endl;
	cout << upper_bound(test0, 2) << endl;
	vector<int> test1 {1,2,2,3};
	cout << lower_bound(test1, 2) << endl;
	cout << upper_bound(test1, 2) << endl;
}
