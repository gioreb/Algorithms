//Giovanni Rebosio gdr0051 10849933

#include "stack.hpp"

using namespace std;

// Auxiliary method, you probably find it useful
// Operands are all lower case and upper case characters
bool isOperand(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Auxiliary method, you probably find it useful
int precedence(char c)
{
  if(c == '+' || c == '-'){
    return 0;
  }
  if(c == '*' || c == '/'){
    return 1;
  }
  if(c == '^'){
    return 2;
  }
  return -1;
}

int main(){
  freopen("input_infix2postfix.txt", "r", stdin);
  string input;
	char x;
	int stackCount;
  string solution;
  int line_counter = 0;
  while(cin >> solution){
    cin >> input;
    Stack<char> stack;
    string result;
	stackCount = 0;
     //The input file is in the format "expected_solution infix_expression", 
     //where expected_solution is the infix_expression in postfix format

    for(int i=0; i<input.length(); ++i){
      	//place current character into x as the code was treating it as an ascii character otherwise.
	//check character, separated parenthesis and exponents as they are special in terms of ordering on ascii table.
	//adds operands to result, pushes operators/parenthesis/exponents and pops previous operators depending on precedence.
	x = input[i];
	if(input[i] == '(')
	{
		stack.push(x);
		stackCount++;
	}
	else if(input[i] == ')')
	{
		while(stackCount > 0 && stack.peek() != '(' )
		{
			result =  result + stack.pop();
			stackCount--;
		}
		stack.pop();
		stackCount--;
	}
	else if(input[i] == '^')
	{
		while(stackCount > 0 && stack.peek() < 41 && stack.peek() > input[i])
		{
			result = result + stack.pop();
			stackCount--;
		}
		stack.push(x);
		stackCount++;
	}
	else if(input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-')
	{
		while(stackCount > 0 && stack.peek() != '(' && stack.peek() < input[i] || stack.peek() == '^')
		{
			result = result + stack.pop();
			stackCount--;
		}
		stack.push(x);
		stackCount++;
	}
	else
	{
		result = result + x;
	}
    }
    
    // You need to do some extra stuff here to store in 'result' the postfix transformation of 'input'
	while(stackCount > 0)
	{
		result = result + stack.pop();
		stackCount--;
	}

    // Checking whether the result you got is correct
    if(solution == result){
      cout << "line " << line_counter << ": OK [" << solution << " " << result << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << result << "]" << endl;
    }
    line_counter++;
  }
}
