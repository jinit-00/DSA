class Solution {
public:
    bool winnerOfGame(string colors) {
        int gooda = 0;
        int goodb = 0;
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i] == 'A' && colors[i] == colors[i-1] && colors[i] == colors[i+1])
            gooda++;
            else if(colors[i] == 'B' && colors[i] == colors[i-1] && colors[i] == colors[i+1])
            goodb++;
        }
        return gooda>goodb;
    }
};