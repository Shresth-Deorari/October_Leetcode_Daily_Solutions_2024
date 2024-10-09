class Solution {
public:
    int minAddToMakeValid(string s) {
        int count =0;
        stack<char>st;
        for(auto i : s){
            if(i=='('){
                count++;
                st.push('(');
            }
            else if(i==')' &&!st.empty() && st.top()=='('){
                if(count){
                    count--;
                    st.pop();
                }
            }
            else{
                st.push(')');
            }
        }
        return st.size();
    }
};
