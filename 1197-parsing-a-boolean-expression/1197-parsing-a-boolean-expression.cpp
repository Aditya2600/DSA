class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops; // Stack to hold operators
        stack<vector<char>> operands; // Stack to hold operands (t/f values)

        for (char ch : expression) {
            if (ch == 't' || ch == 'f') {
                // Push the operand to the stack
                operands.top().push_back(ch);
            } 
            else if (ch == '!' || ch == '&' || ch == '|') {
                // Push operator to the operator stack
                ops.push(ch);
                operands.push(vector<char>()); // Start a new vector for operands
            } 
            else if (ch == ')') {
                // When we hit a closing parenthesis, we need to evaluate
                char op = ops.top(); // Get the operator
                ops.pop();
                vector<char> currentOperands = operands.top(); // Get the operands for the current operation
                operands.pop();
                
                // Apply the operator
                char result;
                if (op == '!') {
                    result = (currentOperands[0] == 't') ? 'f' : 't';
                } 
                else if (op == '&') {
                    result = 't';
                    for (char operand : currentOperands) {
                        if (operand == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } 
                else if (op == '|') {
                    result = 'f';
                    for (char operand : currentOperands) {
                        if (operand == 't') {
                            result = 't';
                            break;
                        }
                    }
                }
                // Push the result back as a single operand
                if (!operands.empty()) {
                    operands.top().push_back(result);
                } else {
                    operands.push({ result });
                }
            } 
            else if (ch == '(') {
                // Simply skip opening parentheses
                continue;
            }
        }
        
        // Final result should be the single remaining value in the stack
        return operands.top()[0] == 't';
    }
};
