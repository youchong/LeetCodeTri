#include "Solution.h"



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

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
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

int Solution::lengthOfLongestSubstring(string s)
{
	if (s.length() < 2)
		return s.length();

	int i = 0, j = 1, maxLength = 1;
	unordered_map<char, int> umap;
	umap[s[i]] = i;

	while (j < s.length())
	{
		if (umap.find(s[j]) != umap.end())
		{
			if (umap[s[j]] >= i)
			{
				int length = j - i;
				if (length > maxLength)
					maxLength = length;
				i = umap[s[j]] + 1;
			}
		}

		umap[s[j]] = j;
		++j;
	}

	int len = j - i;
	if (len > maxLength)
		maxLength = len;

	return maxLength;
}

string Solution::longestPalindrome(string s)
{
	if (s.empty() || s.size() < 2)
		return s;
	int max_left = 0, max_len = 1;
	int s_len = s.size();
	for (int start = 0; start < s_len - 1 && s_len - start>max_len / 2; )
	{
		int i = start;
		int j = start;
		while (j<s_len-1&&s[j]==s[j+1])
		{
			j++;
		}
		start = j + 1;
		while (i > 0 && j < s_len - 1 && s[i - 1] == s[j + 1])
		{
			i--;
			j++;
		}
		if (j - i + 1 > max_len)
		{
			max_len = j - i + 1;
			max_left = i;
		}
	}

	return s.substr(max_left, max_len);
}
