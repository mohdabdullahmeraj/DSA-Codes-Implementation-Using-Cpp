#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string postfixToInfix(string postfix){
	stack<string> s;

	for(char c: postfix){
		if (isOperator(c)){
			string op2=s.top();
			s.pop();
			string op1=s.top();
			s.pop();

			string infix="(" + op1 + c + op2 + ")";
			s.push(infix);
		}

		else{
			s.push(string(1,c));
		}
	}

	return s.top();
	
}


int main(){
    string postfix = "abc*+d-";
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}      

















