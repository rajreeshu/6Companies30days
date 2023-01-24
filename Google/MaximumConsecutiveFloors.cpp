//https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxi=abs(bottom-special[0]);
        
        for(int i=1;i<special.size();i++){
            maxi=max(maxi,special[i]-special[i-1]-1);
        }
        maxi=max(maxi,top-special.back());

        return maxi;
    }
};
