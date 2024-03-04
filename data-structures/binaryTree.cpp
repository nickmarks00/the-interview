#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class BinaryTree {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }

  private:
    void inorder(TreeNode *node, vector<int> &nodes) {

        if (!node) { return; }

        inorder(node->left, nodes);
        nodes.push_back(node->val);
        inorder(node->right, nodes);
    }
};
