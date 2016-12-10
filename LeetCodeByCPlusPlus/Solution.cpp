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