#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens){
    stack<int> op;
    for (auto& token : tokens){ //token is a string here
        if (token == "+" || token == "-" || token == "*" || token == "/"){
            int op2 = op.top();
            op.pop();
            int op1 = op.top();
            op.pop();

            switch(token[0]) {
                case '+' : op.push(op1 + op2);
                            break;
                case '-' : op.push(op1 - op2);
                            break;
                case '*' : op.push(op1 * op2);
                            break;
                case '/' : op.push(op1 / op2);
                            break;
            }
        }
        else {
            op.push(stoi(token));
        }
    }
    return op.top();
}