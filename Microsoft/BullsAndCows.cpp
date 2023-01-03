//https://leetcode.com/problems/bulls-and-cows/description/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        vector<int>sCount(10,0);
        vector<int>gCount(10,0);

        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) bulls++;
            else{
                sCount[secret[i]-'0']++;
                gCount[guess[i]-'0']++;
            }
        }

        for(int i=0;i<10;i++){
            cows+=min(sCount[i],gCount[i]);
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};
