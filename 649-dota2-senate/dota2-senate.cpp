class Solution {
public:
    void remove(string senate,int len,char a,vector<bool> &track)
    {  
        while(true)
        {
            if(senate[len] == a && !track[len])
            {
                track[len] = true;
                return;
            }
        len = (len+1)%senate.length();
        }
    }
    string predictPartyVictory(string senate) {
        int r = count(begin(senate),end(senate),'R');
        int d = count(begin(senate),end(senate),'D');
        int idx = 0;
        vector<bool> track(senate.size(),false);
        while(r>0 && d>0){
        if(track[idx] == false)
        {          
          if(senate[idx] == 'R')
                {
                    remove(senate,(idx+1)%senate.length(),'D',track);
                    d--;
                }
                else
                {
                    remove(senate,(idx+1)%senate.length(),'R',track);
                    r--; 
                }
                 
        }
                idx = (idx+1) % senate.length();
    }
        return d==0 ? "Radiant" : "Dire";
    }
};