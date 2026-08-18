class Solution {
public:
    vector<string> result;
    void find(int open,int close,string &answer,int n)
    {
        if(answer.length() == 2*n)
        {   
            result.push_back(answer);
            return;
        }
        if(open<n)
        {
            answer.push_back('(');
            find(open+1,close,answer,n);
            answer.pop_back();
        }
        if(close<open)
        {      
            answer.push_back(')');
            find(open,close+1,answer,n);
            answer.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string answer;
        int open = 0;
        int close = 0;
        find(open,close,answer,n);
        return result;
    }
};