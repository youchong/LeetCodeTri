#include "Solution.h"
#include<unordered_map>


Solution::Solution()
{
}


Solution::~Solution()
{
}

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;

	for (size_t i = 0; i < nums.size(); i++)
	{
		int first = target - nums[i];
		if (hash.find(first) != hash.end())
		{
			result.push_back(hash[first]);
			result.push_back(i);
			break;
		}

		hash[nums[i]] = i;
	}
	return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;

	int cf = 0;
	ListNode* result = new ListNode(0);
	ListNode* curr = result;

	while (l1 != nullptr || l2 != nullptr || cf != 0)
	{
		int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + cf;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
		cf = sum / 10;
		l1 = l1 == nullptr ? nullptr : l1->next;
		l2 = l2 == nullptr ? nullptr : l2->next;
	}

	return result->next;
}