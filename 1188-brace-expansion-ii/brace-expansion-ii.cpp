class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> res;
        
        if (s[i] == '{') {
            i++; // skip '{'
            
            while (true) {
                set<string> cur = parse(s, i);
                res.insert(cur.begin(), cur.end());
                
                if (s[i] == ',') {
                    i++;
                } else {
                    break;
                }
            }
            
            i++; // skip '}'
        } 
        else {
            res.insert(string(1, s[i]));
            i++;
        }
        
        // Handle concatenation
        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> next = parse(s, i);
            set<string> temp;
            
            for (string a : res) {
                for (string b : next) {
                    temp.insert(a + b);
                }
            }
            
            res = temp;
        }
        
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        
        return vector<string>(ans.begin(), ans.end());
    }
};