// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        vector<int>ans;
        while(root1 || root2 || !st1.empty() || !st2.empty()){
            if(root1!=NULL){
                st1.push(root1);
                root1=root1->left;
            }
            if(root2!=NULL){
                st2.push(root2);
                root2=root2->left;
            }

            if(root1==root2 && root1==NULL){
                if(st2.empty() || (!st1.empty() && st1.top()->val<=st2.top()->val)){
                    root1=st1.top();
                    ans.push_back(root1->val);
                    st1.pop();
                    root1=root1->right;
                }else{
                    root2=st2.top();
                    ans.push_back(root2->val);
                    st2.pop();
                    root2=root2->right;
                }
            }
                
        }
        return ans;
    }
};
