//https://leetcode.com/problems/rotate-function/description/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0;
        int f=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            f+=nums[i]*i;
        }
        int ans=f;;
        for(int i=0;i<n;i++){
            f+=sum-nums[n-i-1]*n;
            ans=max(ans,f);
        }
        
        return ans;
    }
};
