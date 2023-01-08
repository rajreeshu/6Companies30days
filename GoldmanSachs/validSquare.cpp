//https://leetcode.com/problems/valid-square/description/
class Solution {
private:
    int dis(vector<int>p1,vector<int>p2){
        return (pow(p2[0]-p1[0],2)+pow(p2[1]-p1[1],2));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<int>s({dis(p1,p2),dis(p1,p3),dis(p1,p4),dis(p2,p3),dis(p2,p4),dis(p3,p4)});
        return !s.count(0) && s.size()==2;
    }
};
