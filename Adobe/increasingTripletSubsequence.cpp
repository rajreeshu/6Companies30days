//https://leetcode.com/problems/increasing-triplet-subsequence/

//My first solution
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        if(s.size()<3)return false;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>=nums[j])continue;
                for(int k=j+1;k<n;k++){
                    if(nums[j]>=nums[k])continue;
                    return true;
                }
            }
        }
        return false;
    }
};

//revised solution
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX, b=INT_MAX;
        for(auto it:nums){
            if(it<=a)a=it;
            else if(it<=b)b=it;
            else return true;
        }
        return false;
    }
};
