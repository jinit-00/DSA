class Solution {
public:
    int minPartitions(string n) {
        int val = INT_MIN;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]-'0'>val)
            val = n[i]-'0';
        }
    return val ;
    }
};