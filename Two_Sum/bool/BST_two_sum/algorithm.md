# Two Sum in a BST — DFS + Hash Set

## Algorithm
- Traverse the BST using DFS.
- Maintain a hash set `visited` to store values seen so far.
- For each node:
  - If `k - node->val` is in `visited`, return `true`.
  - Else, insert `node->val` into `visited` and continue traversal.

## Code

```cpp
class Solution {
public:
    unordered_set<int> visited;

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (visited.count(k - root->val)) return true;
        visited.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
