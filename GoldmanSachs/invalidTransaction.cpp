//https://leetcode.com/problems/invalid-transactions/description/

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<vector<string>>inp;
        for(int i=0;i<transactions.size();i++){
            string temp="";
            vector<string>ins;
            for(int j=0;j<transactions[i].size();j++){
                if(transactions[i][j]==','){
                    ins.push_back(temp);
                    temp="";
                }else{
                    temp+=transactions[i][j];
                }
            }
            if(temp!="") ins.push_back(temp);
            inp.push_back(ins);
        }

        set<int>invalid;
        for(int i=0;i<transactions.size();i++){
            
            if(stoi(inp[i][2])>1000){
                    invalid.insert(i);
                    continue;
                }
            for(int j=0;j<transactions.size();j++){
                if(i==j) continue;
                if(abs(stoi(inp[i][1])-stoi(inp[j][1]))<=60 && inp[i][3]!=inp[j][3] && inp[i][0]==inp[j][0]){
                    invalid.insert(i);
                    if(stoi(inp[j][2])<=1000){
                        invalid.insert(j);
                        continue;
                    }
                }
            }
        }
        vector<string>ans;
        for(auto it:invalid){
            ans.push_back(transactions[it]);
        }
        return ans;
    }
};
