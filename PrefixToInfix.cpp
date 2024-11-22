#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string prefixToInfix(string prefix){
	stack<string> s;

	for(int i=prefix.length()-1; i>=0; i--){
		char c= prefix[i];

		if (isOperator(c)){
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();

			string infix= "(" + op1 + c + op2 + ")";
			s.push(infix);
		}

		else{
			s.push(string(1,c));
		}
	}

	return s.top();
	
}


int main(){
	string prefix = "+*abc";
    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}      

















