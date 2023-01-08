//https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX;
        unordered_map<int,int>m;
        for(int i=0;i<cards.size();i++){
            if(m.find(cards[i])==m.end()){
                m[cards[i]]=i;
            }else{
                ans=min(ans,i-m[cards[i]]);
                m[cards[i]]=i;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans+1;
    }
};
