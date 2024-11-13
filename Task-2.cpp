// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool helper(TreeNode* node, long min_val, long max_val) {
        if (node == nullptr) {
            return true;
        }

        // Checking if the current node's value is within the valid range
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // Recursively checking the left and right subtrees
        return helper(node->left, min_val, node->val) && helper(node->right, node->val, max_val);
    }
};


Time complexity: O(n)    //n is the number of nodes in the tree
Space Complexity: O(h)  //h is the height of the tree
