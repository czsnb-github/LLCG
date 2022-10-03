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