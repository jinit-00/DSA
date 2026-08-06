class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;

        while (true) {
            int temp = i;
            int val = 1;

            while (temp > 0) {
                val *= (temp % 10);
                temp /= 10;
            }

            if (val % t == 0)
                return i;

            i++;
        }
    }
};