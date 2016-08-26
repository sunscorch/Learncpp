#include <iostream>
#include <algorithm>
using namespace std;

void Max_Heaptify(vector<int>& A, int start, int end){
	int daddy = start;
	int son =2 * daddy + 1;

	while(son <= end){
		if((son + 1) <= end && A[son] < A[son+1]){
			son++;
		}
		if(A[daddy] > A[son]){
			return;
		}else{
			swap(A[daddy], A[son]);
			daddy = son;
			son = 2 * daddy + 1;
		}	
	}
}

void heapSort(vector<int>& A){
	//start from the first daddy node , do the maxHeaptify, 
	for(int i = A.size()/2 - 1; i >= 0; i--){
		Max_Heaptify(A, i, A.size() - 1);
	}
	//get Top node, put it into the back , then heapify remaining elements, do this everytime until no node can be heaptify

	for(int i = A.size() - 1; i >= 0; i--){
		swap(A[0], A[i]);
		Max_Heaptify(A, 0, i - 1);
	}

}
int main(){
	vector<int> test = {0,2,0,87,6,53,4,1};
	heapSort(test);

	for(const auto& n: test){
		cout << n << endl;
	}
}
