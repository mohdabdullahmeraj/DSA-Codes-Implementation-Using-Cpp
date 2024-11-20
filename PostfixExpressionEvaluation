#include <bits/stdc++.h>
using namespace std;

double evaluatePostfix(const string& expression){
	stack<double> s;

	for (int i=0;i<expression.length();i++){

		if (expression[i]==' ')
			continue;

		if (isdigit(expression[i])){
			double val=0;

			while(i<expression.length() && isdigit(expression[i])){
				val=(val*10) + (expression[i] - '0') ;
				i++;
			}

			s.push(val);
			i--;
		}

		else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
			double op2=s.top();
			s.pop();
			double op1=s.top();
			s.pop();

			switch (expression[i]){
			case '+':
				s.push(op1+op2);
				break;

			case '-':
				s.push(op1-op2);
				break;	

			case '*':
				s.push(op1*op2);
				break;

			case '/':
				s.push(op1/op2);
				break;


			}
		}
	}

	return s.top();
}



int main(){
	string expression;
    cout << "Enter postfix expression: ";
    getline(cin, expression);

    
	    double result = evaluatePostfix(expression);
	    cout << "Result: " << result << endl;
	
    return 0;
}      

















