class Solution {
public:
    bool checkDivisibility(int n) {
        long long val = 0;
        long long val1 = 1;
        int a = n;
        int b = n;
        while(n>0)
        {
            val += n%10;
            n = n/10;
        }
        while(a>0)
        {
            val1 *= a%10;
            a = a/10;
        }
    long long val2 = val1+val;
    bool answer = false;
    if(b%val2==0)
    answer = true;
    return answer;
    }
};