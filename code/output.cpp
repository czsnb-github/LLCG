#include "template/template.h"
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};

Solution* solution;
int main() {
	solution = new Solution();
	Tree var1{"4","2","7","1","3","6","9"};
	print(solution->invertTree(var1.root));
	delete solution;
	solution = new Solution();
	Tree var2{"2","1","3"};
	print(solution->invertTree(var2.root));
	delete solution;
	solution = new Solution();
	Tree var3{};
	print(solution->invertTree(var3.root));
	delete solution;
}