#pragma once
#include<vector>
#include<unordered_map>
#include<string>
#include"ListNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	vector<int> twoSum(vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(string s);
};

