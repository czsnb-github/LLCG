# Local Leetcode Code Generator (LLCG)

## Overview

Local Leetcode Code Generator (a.k.a., LLCG) is a code generator that generates LeetCode-style code to run locally.

Please feel free to contact me to give any comments or suggestions.

## Quick Start

1. Place your LeetCode-style code into **code/input.cpp**
2. Place your test case into **code/input.txt** (copy and paste from LeetCode is recommended)
3. Run `python main.py`
4. **code/output.cpp** can be run locally!

## Example

[Two_Sum](https://leetcode.cn/problems/two-sum/)

First, write your Solution here in **code/input.cpp**.

```cpp
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
```

And then paste your test case into **code/input.txt**.

```
[2,7,11,15]
9
[3,2,4]
6
[3,3]
6
```

Run `python main.py` and **code/output.cpp** will be generated.

```cpp
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
```

Build and run **code/output.cpp**, and you will get following output:

```
[1, 0]
Runtime: 0 ms
[2, 1]
Runtime: 0 ms
[1, 0]
Runtime: 0 ms
```

Correct!

## TODO

+  More infrastructure for this project
+  User interface
+  Version management
