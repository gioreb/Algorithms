//Giovanni Rebosio gdr0051 10849933

#include "stack.hpp"
#include<string>

using namespace std;

int main(){
  freopen("input_postfixEval.txt", "r", stdin);
  string s;
	string x;
	int a = 0;
	int b = 0;
  int solution;
  int line_counter = 0;
  while(cin>>solution){
    cin>>s;
    Stack<int> stack;
    
    // The input file is in the format "expected_solution postfix_expression"

    // We assume that all operands in the input are one digit (so they range from 0 to 9)
    for(int i=0; i<s.length(); ++i){
      	//place current character into x as the code was treating it as an ascii character otherwise.
	//push operands onto stack until an operator is encountered, then perform operator on popped values.
	x = s[i];
	if(s[i] == '+')
	{
		int b = stack.pop();
		int a = stack.pop();
		stack.push(a + b);
	}
	else if(s[i] == '-')
	{
		int b = stack.pop();
		int a = stack.pop();
		stack.push(a - b);
	}
	else if(s[i] == '*')
	{
		int b = stack.pop();
		int a = stack.pop();
		stack.push(a * b);
	}
	else if(s[i] == '/')
	{
		int b = stack.pop();
		int a = stack.pop();
		stack.push(a / b);
	}
	else
	{
		stack.push(stoi(x));
	}
    }

    // Checking whether the value you calculated is correct ...
    int value = stack.pop();

    if(solution == value){
      cout << "line " << line_counter << ": OK [" << solution << " " << value << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << value << "]" << endl;
    }
    line_counter++;
  }
}
