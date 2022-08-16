#ifndef TREE_H
#define TREE_H

#include <bits/stdc++.h>

#include "tree_node.h"

using namespace std;

struct Tree {
  TreeNode* root = nullptr;
  Tree(initializer_list<string> _a) {
    vector<string> a{_a};
    if (a.empty()) {
      return;
    }
    int n = a.size();
    queue<TreeNode*> q;
    root = new TreeNode(stoi(a[0]));
    q.emplace(root);
    for (int i = 1; !q.empty(); q.pop()) {
      TreeNode* cur = q.front();
      for (int j = 0; j < 2; ++j) {
        if (i < n) {
          if (a[i] != "null") {
            TreeNode* nxt = new TreeNode(stoi(a[i]));
            (j == 0 ? cur->left : cur->right) = nxt;
            q.emplace(nxt);
          }
          ++i;
        } else {
          break;
        }
      }
    }
  }
  void Destruct(TreeNode* cur) {
    if (!cur) {
      return;
    }
    Destruct(cur->left);
    Destruct(cur->right);
    delete cur;
  }
  ~Tree() { Destruct(root); }
};

#endif  // TREE_H