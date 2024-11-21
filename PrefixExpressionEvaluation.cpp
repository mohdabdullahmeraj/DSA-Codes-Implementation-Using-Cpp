#include <bits/stdc++.h>
using namespace std;

double evaluatePrefix(const string& expression){
	stack<double> s;

	for (int i=expression.length()-1;i>=0;i--){

		if (expression[i]==' ')
			continue;

		if (isdigit(expression[i])){
			double val=0;
			int j=i;
			int mul=1;

			while(j>=0 && isdigit(expression[j])){
				val=val+(expression[j] - '0') * mul;
				mul *=10;
				j--;
			}

			s.push(val);
			i=j+1;
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
    cout << "Enter prefix expression: ";
    getline(cin, expression);

    
	    double result = evaluatePrefix(expression);
	    cout << "Result: " << result << endl;
	
    return 0;
}      

















