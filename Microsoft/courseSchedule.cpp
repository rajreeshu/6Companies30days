//https://leetcode.com/problems/course-schedule/description/
class Solution {
private:
    void helper(unordered_map<int,vector<int>>&m,  unordered_set<int>&s){
        int pre=s.size();
        for(auto it:m){
            if(s.find(it.first)!=s.end()) continue;
            bool flag=true;
            for(int i=0;i<it.second.size();i++){
                if(s.find(it.second[i])==s.end()) flag=false;
            }
            if(flag==true)s.insert(it.first);
        }
        if(s.size()>pre) helper(m,s);
    }
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        unordered_map<int,vector<int>>m;
        unordered_set<int>s;

        for(int i=0;i<pr.size();i++){
            vector<int>temp=pr[i];
            m[temp[0]].push_back(temp[1]);
        }

        for(int i=0;i<n;i++){
            if(m.find(i)==m.end()) s.insert(i);
        }

        helper(m,s);
        cout<<s.size();
        cout<<endl;
        for(auto it:s) cout<<it<<" ";
        
        if(s.size()==n) return true;
        return false;
    }
};
