class Solution {
private:
    void helper(int k, int n, vector<int>v, vector<vector<int>> &ans){
        if(k==0){
            if(n==0) ans.push_back(v);
            return;
        }

        int start=v.empty()?1:v.back()+1;
        for(int i=start;i<=9;i++){
            v.push_back(i);
            helper(k-1,n-i,v,ans);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>v;
        helper(k,n,v,ans);
        return ans;
    }
};
