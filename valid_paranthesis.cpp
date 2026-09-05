class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i = 0; i < str.size(); i++){
            // If it's an opening bracket, push to stack
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            } 
            // Otherwise, it's a closing bracket
            else {
                // If the stack is empty, there is no matching opening bracket
                if(st.empty()){
                    return false;
                }
                
                // Check if the top of the stack matches the closing bracket
                if((st.top() == '(' && str[i] == ')') ||
                   (st.top() == '{' && str[i] == '}') || 
                   (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        // If the stack is empty at the end, all brackets were matched
        return st.empty();
    }
};