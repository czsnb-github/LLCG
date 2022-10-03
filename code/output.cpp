#include "template/template.h"
class Solution {
 public:
  map<int, int> a;
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      int v = target - nums[i];
      if (a.count(v)) {
        ans = {i, a[v]};
        break;
      }
      a[nums[i]] = i;
    }
    return ans;
  }
};
Solution* solution;
Timer timer;
int main() {
	timer.start();
	solution = new Solution();
	vector<int> var1{2,7,11,15};
	int var2{9};
	print(solution->twoSum(var1, var2));
	delete solution;
	print("Runtime: " + to_string(timer.end()) + " ms");

	timer.start();
	solution = new Solution();
	vector<int> var3{3,2,4};
	int var4{6};
	print(solution->twoSum(var3, var4));
	delete solution;
	print("Runtime: " + to_string(timer.end()) + " ms");

	timer.start();
	solution = new Solution();
	vector<int> var5{3,3};
	int var6{6};
	print(solution->twoSum(var5, var6));
	delete solution;
	print("Runtime: " + to_string(timer.end()) + " ms");
}