#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//given an array of string, get the reverse polish array of it
//we can use the array to get to calulate the answer using evalRPN

bool isLowPority (const string &s1 , const string &s2) {
	if ((s1 == "+" || s1 == "-") &&
		(s2 == "*" || s1 == "/"))
		return true;
	return false;
}

bool isOperator(const string &s){
	if(s == "*" || s == "/" || s == "+" || s == "-") 
		return true;
	return false;
}

bool isParenthesis (const string &s) {
	if (s == "(" || s == ")")
		return true;
	return false;
}

vector<string> getReversePoilsh(vector<string> &A){
	stack<string> st;
	vector<string> res;

	for(auto& s : A){
		if (!isOperator(s) && !isParenthesis(s)){
			res.push_back(s);
		}else if (isOperator(s)){
			while (!st.empty() && 
					isLowPority(s, st.top()) &&
					(s != "(" && s != ")")) {
				cout << "st top is "<< st.top() <<endl; 
				res.push_back(st.top());
				st.pop();

			}
			st.push(s);
		}	

		else if (s == "(") st.push(s);
		else if( s == ")"){
			while (!st.empty() && st.top() != "(") {
				res.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
	}

	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}

	return res;
}
/*
int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++)
        {
        	if(tokens[i] != "*" &&
        	   tokens[i] != "+" &&
        	   tokens[i] != "-" &&
        	   tokens[i] != "/" )
        	{
        		int num = stoi(tokens[i]);
        		st.push(num);
        	}else
        	{
        		int a = st.top();
        		st.pop();
        		int b = st.top();
        		st.pop();
        		if(tokens[i] == "+") st.push(b+a);
        		if(tokens[i] == "-") st.push(b-a);
        		if(tokens[i] == "*") st.push(b*a);
        		if(tokens[i] == "/") st.push(b/a);
        	}
        }
        return st.top();
    }
   */

int main(){
	//string n0[] = {"a","*","b","+", "c"};
	//vector<string> test1(n, n+5);
	//vector<string> res0 = getReversePoilsh(test1);
	string n1[] = {"1","+","2","-","3","*","(","4","-","5",")"};
	vector<string> test2(n1, n1+11);
	vector<string> res1 = getReversePoilsh(test2);
	for(auto& s : res1){
		cout << s << endl;
	}
	return 0;
}
