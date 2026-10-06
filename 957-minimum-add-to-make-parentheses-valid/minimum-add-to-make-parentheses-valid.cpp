class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {   
            if(s[i] == '(')
            st.push('(');

            else if(s[i] == ')')
            {
                if(st.size()>0 && st.top() == '(')
                st.pop();
                else
                st.push(')');
            }
        }
    return st.size();
    }
};