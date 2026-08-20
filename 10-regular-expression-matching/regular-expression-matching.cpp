class Solution {
public:

    bool call(string s,string p)
    {
        if(p.length()==0)
        {
            return s.length()==0;
        }
        bool match =  (s.length()>0) && (s[0]==p[0] || p[0]=='.');
        if(p[1] == '*'){
            bool not_take = call(s,p.substr(2));
            bool take = (match && call(s.substr(1),p));
            return take || not_take;
        }
        return match && call(s.substr(1),p.substr(1));
    }
    bool isMatch(string s, string p) {
        return call(s,p);   
    }
};