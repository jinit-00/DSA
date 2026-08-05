class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i=0;i<31;i++)
        {
            int bit = n&1;
            n = n>>1;
            bit = bit<<(31-i);
            res = res | bit;
        }
        return res;
    }
};