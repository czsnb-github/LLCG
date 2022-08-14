#ifndef LIST_H
#define LIST_H

#include <bits/stdc++.h>

#include "list_node.h"

using namespace std;

struct List {
  ListNode* head;
  List(initializer_list<int> _a) {
    vector<int> a{_a};
    int n = a.size();
    head = nullptr;
    for (int i = n - 1; i >= 0; --i) {
      ListNode* cur = new ListNode(a[i], head);
      head = cur;
    }
  }
  ~List() {
    for (; head;) {
      ListNode* nxt = head->next;
      delete head;
      head = nxt;
    }
  }
};

#endif  // LIST_H