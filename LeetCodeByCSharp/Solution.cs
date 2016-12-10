using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCodeByCSharp
{
    class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int[] result = new int[2];
            Hashtable ht = new Hashtable();

            for (int i = 0; i < nums.Length; i++)
            {
                int OneTarget = target - nums[i];
                if (ht.ContainsKey(OneTarget))
                {
                    result[0] = i;
                    result[1] = (int)ht[OneTarget];
                    return result;
                }

                if (!ht.ContainsKey(nums[i]))
                {
                    ht.Add(nums[i], i);
                }
            }
            return result;
        }
    }
}
