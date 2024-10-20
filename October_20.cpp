class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        bool ans = false;
        for(auto i : expression){
            if(i==',' || i=='(')continue;

            if(i == ')'){
                bool hasTrue = false;
                bool hasFalse = false;

                while(st.top()!='!' && st.top()!='&' && st.top()!='|'){
                    if(st.top()=='f')
                        hasFalse = true;
                    else
                        hasTrue = true;
                    st.pop();
                }

                char op = st.top();
                st.pop();
                if(op=='&'){
                    st.push(hasFalse?'f':'t');
                }
                else if(op=='|'){
                    st.push(hasTrue?'t':'f');
                }
                else{
                    st.push(hasFalse?'t':'f');
                }

            }
            else{
                st.push(i);
            }
        }
        return st.top()=='t';
    }
};