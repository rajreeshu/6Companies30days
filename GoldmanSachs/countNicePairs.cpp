//https://leetcode.com/problems/count-nice-pairs-in-an-array/description/
class Solution {
private:
int mod=1e9+7;
int rev(int n){
    int ans=0;
    while(n>0)
        ans=(ans*10)+(n%10),
        n=n/10;    
    return ans;
}
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        for(auto it:nums){
            ans+= (m[it-rev(it)]++)%mod;
            ans%=mod;
        }
        return ans;
    }
};
