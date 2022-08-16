#include "template/template.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* lst = nullptr;
    ListNode* head = nullptr;
    int x = 0;
    for (; l1 || l2 || x; l1 = (l1 ? l1->next : l1), l2 = (l2 ? l2->next : l2)) {
      int a = l1 ? l1->val : 0;
      int b = l2 ? l2->val : 0;
      int c = a + b + x;
      if (c >= 10) {
        c -= 10;
        x = 1;
      } else {
        x = 0;
      }
      ListNode* cur = new ListNode(c);
      if (lst == nullptr) {
        head = cur;
      } else {
        lst->next = cur;
      }
      lst = cur;
    }
    return head;
  }
};

Solution* solution;
int main() {
	solution = new Solution();
	List var1{2,4,3};
	List var2{5,6,4};
	print(solution->addTwoNumbers(var1.head, var2.head));
	delete solution;
	solution = new Solution();
	List var3{0};
	List var4{0};
	print(solution->addTwoNumbers(var3.head, var4.head));
	delete solution;
	solution = new Solution();
	List var5{9,9,9,9,9,9,9};
	List var6{9,9,9,9};
	print(solution->addTwoNumbers(var5.head, var6.head));
	delete solution;
}