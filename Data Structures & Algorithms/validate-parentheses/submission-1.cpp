class Solution {
public:
    bool IsOpenBracket(char ch){
        if(ch == '(' || ch == '{' || ch == '[') return true;
        else return false;
    }
    char corresponding_bracket(char ch){
        if(ch == ')') return '(';
        else if(ch == '}') return '{';
        else return '[';
    }

    bool isValid(string s) {
        stack<char> st;

        for(char ch: s){
            if(IsOpenBracket(ch)){
                st.push(ch);
            }
            else {//closed bracket
                if(!st.empty() && st.top() == corresponding_bracket(ch)) st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
