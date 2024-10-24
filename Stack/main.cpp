#include <string>
#include <iostream>

#include "stack.h"

int main() {
	std::cout << checkSeq("(())");
}

bool checkSeq(std::string s) {
	TStack<char> stack(10);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') stack.push(')');
		if (s[i] == ')') {
			if (stack.empty()) return false;
			stack.pop();
		}
		if (!stack.empty()) return false;
	}
	return true;
}