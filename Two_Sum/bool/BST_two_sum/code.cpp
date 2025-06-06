
class Solution {
public:
    unordered_set<int>visited;
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        if(visited.count(k-root->val))return true;
        visited.insert(root->val);
        return(findTarget(root->left,k) ||
        findTarget(root->right,k));
    }
};
