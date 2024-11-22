#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
	if (op=='+' || op=='-') return 1;
	if (op=='*' || op=='/') return 2;
	if (op=='^') return  3;
	return 0;
}

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string infixToPostfix(string infix){
	stack<char> s;
	string postfix;

	for (char c: infix){
		if ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
			postfix +=c;
		}

		else if (c=='('){
			s.push(c);
		}

		else if (c==')'){
			while(!s.empty() && s.top() != '('){
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}

		else if (isOperator(c)){
			while(!s.empty() && precedence(s.top())>= precedence(c)){
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		}

	}

	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

string infixToPrefix(string infix){
	reverse(infix.begin(),infix.end());

	for (int i=0; i<infix.length(); i++){
		if (infix[i] == '('){
			infix[i]=')';
		}
		else if(infix[i] == ')' ){
			infix[i] = '(';
		}
	}

	string postfix= infixToPostfix(infix);

	reverse(postfix.begin(), postfix.end());

	return postfix;
}


int main(){
    string infix = "A+B*(C^D-E)^(F+G*H)-I";
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;
    return 0;
}      

















