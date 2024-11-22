#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string prefixToPostfix(string prefix){
	stack<string> s;

	for(int i=prefix.length()-1; i>=0; i--){
		char c= prefix[i];

		if (isOperator(c)){
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();

			string postfix= op1 + op2 + c;
			s.push(postfix);
		}

		else{
			s.push(string(1,c));
		}
	}

	return s.top();
	
}


int main(){
	string prefix = "*+ABC";
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}      

















