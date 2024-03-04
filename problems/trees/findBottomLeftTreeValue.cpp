/*
 * FIND BOTTOM LEFT TREE VALUE
 * FROM: LeetCode
 * NUMBER: 513
 * DIFFICULTY: Medium
 * LANGUAGE: C++
 * Given the root of a binary tree, return the leftmost value in the last row of
 * the tree.
 */
#include <algorithm>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  private:
    int treeHeight;
    int inf = -10000;

  public:
    int findBottomLeftValue(TreeNode *root) {
        treeHeight = heightOfTree(root);
        return leftPathTraversal(root, 1);
    }

    int leftPathTraversal(TreeNode *node, int currHeight) {
        if (node == nullptr) {
            return inf;
        } else if (currHeight == treeHeight) {
            return node->val;
        }
        int leftSubtree = leftPathTraversal(node->left, currHeight + 1);
        return leftSubtree != inf
                   ? leftSubtree
                   : leftPathTraversal(node->right, currHeight + 1);
    }

    int heightOfTree(TreeNode *node) {
        if (node == nullptr) { return 0; }
        return 1 + max(heightOfTree(node->left), heightOfTree(node->right));
    }

    TreeNode *parseTree(vector<int> tree) {
        TreeNode *root = new TreeNode(tree[0]);
        for (int i = 1; i < tree.size(); i++) {}

        return root;
    }
};
