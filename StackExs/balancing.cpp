//Giovanni Rebosio gdr0051 10849933
//Had to fix some problems with getting input from the file as is was only reading up to the space per line.

#include <fstream>
#include "stack.hpp"

using namespace std;

int main(){
	ifstream infile("input_balanced.txt");
  string s,r;
  int line_counter;
  while(getline(infile, r)){
    Stack<char> stack;
    bool isBalanced = true;
    bool solution;
	int bracketCount = 0;
    if(r[0] == 'Y' || r[0] == 'y'){
      solution = true;
    }else{
      solution = false;
    }

    // The input file is in the format "expected_solution expression"
    // so variable solution tells you whether 'expression' is balanced or not

    for(int i=0; i<r.length(); ++i){
	//If next character is an open bracket, push onto stack.
	//If next character is a close bracket and the stack has the incorrect bracket, isBalanced = false andbreak for loop.
	//If next character is a close bracket and the stack has a corresponding open bracket, pop.
	//If there is an uneven count of brackets isBalanced = false.
	if(r[i] == '(' || r[i] == '[')
	{
		stack.push(r[i]);
		bracketCount++;
	}
	if(r[i] == ')' && stack.peek() == '[' || r[i] == ']' && stack.peek() == '(')
	{
		isBalanced = false;
		break;
	}
	if(r[i] == ')' && stack.peek() == '(' || r[i] == ']' && stack.peek() == '[')
	{
		stack.pop();
		bracketCount--;
	}
    }

	if(bracketCount != 0)
	{
		isBalanced = false;
	}

    // checking if you stored in isBalanced the correct value
    if(isBalanced == solution){
      cout << "line " << line_counter << ": OK [" << solution << " " << isBalanced << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << isBalanced << "]" << endl;
    }
    line_counter++;
  }
}
