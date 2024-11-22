#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string postfixToPrefix(string postfix){
	stack<string> s;

	for(char c: postfix){
		if (isOperator(c)){
			string op2=s.top();
			s.pop();
			string op1=s.top();
			s.pop();

			string prefix=c + op1 + op2;
			s.push(prefix);
		}

		else{
			s.push(string(1,c));
		}
	}

	return s.top();
	
}


int main(){
	string postfix = "abc*+";
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}      

















