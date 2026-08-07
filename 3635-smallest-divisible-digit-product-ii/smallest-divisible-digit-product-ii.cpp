class Solution {
public:
    int e2[10] = {0,0,1,0,2,0,1,0,3,0};
    int e3[10] = {0,0,0,1,0,0,1,0,0,2};
    int e5[10] = {0,0,0,0,0,1,0,0,0,0};
    int e7[10] = {0,0,0,0,0,0,0,1,0,0};

    int A,B,C,D;
    vector<vector<vector<vector<int>>>> dp;

    int minDigits(int a,int b,int c,int d){
        a = max(0, min(a,A));
        b = max(0, min(b,B));
        c = max(0, min(c,C));
        d = max(0, min(d,D));
        return dp[a][b][c][d];
    }

    void buildDP(){
        dp.assign(A+1, vector<vector<vector<int>>>(B+1,
                  vector<vector<int>>(C+1, vector<int>(D+1, INT_MAX))));
        dp[0][0][0][0] = 0;

        vector<array<int,4>> states;
        for(int a=0;a<=A;a++)
            for(int b=0;b<=B;b++)
                for(int c=0;c<=C;c++)
                    for(int d=0;d<=D;d++)
                        states.push_back({a,b,c,d});

        sort(states.begin(), states.end(), [](const array<int,4>&x, const array<int,4>&y){
            return (x[0]+x[1]+x[2]+x[3]) < (y[0]+y[1]+y[2]+y[3]);
        });

        for(auto &s : states){
            int a=s[0], b=s[1], c=s[2], d=s[3];
            if(a==0 && b==0 && c==0 && d==0) continue;
            int best = INT_MAX;
            for(int dig=2; dig<=9; dig++){
                int na = max(0, a - e2[dig]);
                int nb = max(0, b - e3[dig]);
                int nc = max(0, c - e5[dig]);
                int nd = max(0, d - e7[dig]);
                if(na==a && nb==b && nc==c && nd==d) continue; // no progress
                if(dp[na][nb][nc][nd] != INT_MAX)
                    best = min(best, dp[na][nb][nc][nd] + 1);
            }
            dp[a][b][c][d] = best;
        }
    }

    string fillSuffix(int r2,int r3,int r5,int r7,int L){
        string res;
        res.reserve(L);
        int cr2=r2, cr3=r3, cr5=r5, cr7=r7;
        for(int pos=0; pos<L; pos++){
            int remainAfter = L - pos - 1;
            for(int dig=1; dig<=9; dig++){
                int n2 = max(0, cr2-e2[dig]);
                int n3 = max(0, cr3-e3[dig]);
                int n5 = max(0, cr5-e5[dig]);
                int n7 = max(0, cr7-e7[dig]);
                if(minDigits(n2,n3,n5,n7) <= remainAfter){
                    res.push_back(char('0'+dig));
                    cr2=n2; cr3=n3; cr5=n5; cr7=n7;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        long long tt = t;
        int a=0,b=0,c=0,d=0;
        while(tt % 2 == 0){ tt/=2; a++; }
        while(tt % 3 == 0){ tt/=3; b++; }
        while(tt % 5 == 0){ tt/=5; c++; }
        while(tt % 7 == 0){ tt/=7; d++; }
        if(tt != 1) return "-1";

        A=a; B=b; C=c; D=d;
        buildDP();

        int n = num.size();
        vector<int> p2(n+1,0), p3(n+1,0), p5(n+1,0), p7(n+1,0);
        int firstZero = n;
        for(int i=0;i<n;i++){
            int dig = num[i]-'0';
            if(dig==0 && firstZero==n) firstZero = i;
            p2[i+1] = p2[i] + e2[dig];
            p3[i+1] = p3[i] + e3[dig];
            p5[i+1] = p5[i] + e5[dig];
            p7[i+1] = p7[i] + e7[dig];
        }

        string result;
        bool found = false;

        // Case: num itself (only possible if it's already zero-free)
        if(firstZero == n){
            int r2 = max(0, A - p2[n]);
            int r3 = max(0, B - p3[n]);
            int r5 = max(0, C - p5[n]);
            int r7 = max(0, D - p7[n]);
            if(r2==0 && r3==0 && r5==0 && r7==0){
                result = num;
                found = true;
            }
        }

        if(!found){
            int maxI = min(n-1, firstZero);
            for(int i = maxI; i >= 0 && !found; i--){
                int origDig = num[i]-'0';
                int r2_0 = max(0, A - p2[i]);
                int r3_0 = max(0, B - p3[i]);
                int r5_0 = max(0, C - p5[i]);
                int r7_0 = max(0, D - p7[i]);
                int remainLen = n - 1 - i;

                for(int dig = origDig+1; dig <= 9; dig++){
                    int r2 = max(0, r2_0 - e2[dig]);
                    int r3 = max(0, r3_0 - e3[dig]);
                    int r5 = max(0, r5_0 - e5[dig]);
                    int r7 = max(0, r7_0 - e7[dig]);
                    if(minDigits(r2,r3,r5,r7) <= remainLen){
                        string prefix = num.substr(0, i);
                        string suffix = fillSuffix(r2,r3,r5,r7, remainLen);
                        result = prefix + char('0'+dig) + suffix;
                        found = true;
                        break;
                    }
                }
            }
        }

        if(!found){
            int need0 = minDigits(A,B,C,D);
            int L = max(n+1, need0);
            result = fillSuffix(A,B,C,D,L);
        }

        return result;
    }
};