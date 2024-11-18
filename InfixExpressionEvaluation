#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
	if (op=='+' || op=='-')
		return 1;
	if (op=='*' || op=='/')
		return 2;
	return 0;
}

double applyOperation(double a, double b, char op){
	switch(op){
	case '+': return a+b;
	case '-': return a-b;
	case '*': return a*b;
	case '/': return a/b;
	}

	return 0;
}

double evaluate(string expression){
	stack<double> values;
	stack<char> ops;

	for (int i=0;i<expression.length();i++){

		if (expression[i]==' '){
			continue;
		}

		if (isdigit(expression[i])){
			double val=0;
			while (i<expression.length() && (isdigit(expression[i]) || expression[i]=='.' )){

				if (expression[i]=='.'){
					i++;
					double decimal_place= 1;
					while (i<expression.length() && isdigit(expression[i])){
						decimal_place /=10;
						val +=(expression[i]-'0')* decimal_place;
						i++;
					}
					i--;
				} else {
					val= (val*10) + (expression[i]-'0');
				}
				i++;
			}
			values.push(val);
			i--;
		}

		else if(expression[i]=='('){
			ops.push(expression[i]);
		}

		else if(expression[i]==')'){
			while (!ops.empty() && ops.top() !='('){
				double val2 = values.top();
				values.pop();

				double val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOperation(val1, val2, op));
			}

			if (!ops.empty()){
				ops.pop();
			}
		}

		else{
			while(!ops.empty() && precedence(ops.top()) >= precedence(expression[i])){
				double val2 = values.top();
				values.pop();

				double val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOperation(val1, val2, op));
			}

			ops.push(expression[i]);
		}
	}

	while (!ops.empty()) {
        double val2 = values.top();
        values.pop();

        double val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}



int main(){
	string expression;
    cout << "Enter infix expression: ";
    getline(cin, expression);

    double result = evaluate(expression);
    cout << "Result: " << result << endl;

    return 0;
}      

















