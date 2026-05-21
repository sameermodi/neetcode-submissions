class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto ch: operations){
            if(ch == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1 + num2);
            }
            else if(ch == "D"){
                int num1 = st.top() ;
                st.push(2 * num1);
            }
            else if(ch == "C"){
                st.pop();
            }
            else {
                st.push(stoi(ch));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};