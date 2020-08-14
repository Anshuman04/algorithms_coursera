#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int firstBracketPos = -1;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        Bracket temp(next, position+1);

        if (next == '(' || next == '[' || next == '{') {
            if (firstBracketPos == -1){
                firstBracketPos = position + 1;
                // std::cout << "## HIT ## " << firstBracketPos << std::endl;
            }
            opening_brackets_stack.push(temp);
            // Process opening bracket, write your code here
        }

        if (next == ')' || next == ']' || next == '}') {
            if (firstBracketPos == -1){
                std::cout << position + 1;
                return 1;
            }
            Bracket matchObj = opening_brackets_stack.top();
            if (!matchObj.Matchc(next)){
                std::cout << position + 1;
                return 2;
            } else {
                opening_brackets_stack.pop();
                if (opening_brackets_stack.empty()){
                    firstBracketPos = -1;

                }
            }
            // Process closing bracket, write your code here
        }
    }
    if (opening_brackets_stack.empty()){
        std::cout<< "Success";
    } else {
        std::cout<< firstBracketPos;
    }

    // Printing answer, write your code here

    return 0;
}
