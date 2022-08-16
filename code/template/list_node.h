#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  friend ostream& operator<<(ostream& outs, ListNode* node) {
    outs << '[';
    ListNode* cur = node;
    for (; cur; cur = cur->next) {
      outs << cur->val << (cur->next ? ", " : "]");
    }
    return outs;
  }
};

#endif  // LIST_NODE_H
