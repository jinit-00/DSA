class Solution {
public:
    long long countCommas(long long n) {
        long long answer = 0;
        long long val = 1000;
        while(val <= n)
        {
            answer += (n - val + 1);
            val *= 1000;
        }
    return answer;
    }
};