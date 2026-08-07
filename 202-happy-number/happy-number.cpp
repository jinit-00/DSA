class Solution {
public:
    bool isHappy(int n) {
        long long store = n;
        long long answer = 0;
        while(true)
        {
            answer = 0;
            while(store>0)
            {
                answer += (store%10)*(store%10);
                store = store/10;
            }
            if(answer == 1 || answer == 7)
            return true;
            else if(answer<10 && answer>1)
            return false;
            store = answer;
        }
    return true;
    }
};