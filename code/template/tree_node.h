#ifndef TREE_NODE_H
#define TREE_NODE_H

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  static string GetVal(TreeNode* cur) { return cur ? to_string(cur->val) : "null"; }
  friend ostream& operator<<(ostream& outs, TreeNode* node) {
    vector<string> res;
    if (node) {
      queue<TreeNode*> q;
      q.emplace(node);
      res.emplace_back(GetVal(node));
      for (; !q.empty(); q.pop()) {
        TreeNode* cur = q.front();
        if (cur->left || cur->right) {
          res.emplace_back(GetVal(cur->left));
          res.emplace_back(GetVal(cur->right));
          if (cur->left) {
            q.emplace(cur->left);
          }
          if (cur->right) {
            q.emplace(cur->right);
          }
        }
      }
    }
    for (; !res.empty() && res.back() == "null"; res.pop_back())
      ;
    outs << '[';
    int len = res.size();
    for (int i = 0; i < len; ++i) {
      outs << res[i];
      if (i < len - 1) {
        outs << ", ";
      }
    }
    outs << ']';
    return outs;
  }
};

#endif  // TREE_NODE_H
