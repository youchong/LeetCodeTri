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

        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            if (l1 == null)
                return l2;
            if (l2 == null)
                return l1;

            int cf = 0;
            ListNode result = new ListNode(0);
            ListNode curr = result;

            while (l1 != null || l2 != null || cf != 0)
            {
                int sum = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + cf;
                curr.next = new ListNode(sum % 10);
                curr = curr.next;
                cf = sum / 10;
                l1 = (l1 == null ? null : l1.next);
                l2 = (l2 == null ? null : l2.next);
            }

            return result.next;
        }

        public int LengthOfLongestSubstring(string s)
        {
            if (s.Length < 2)
                return s.Length;
            int i = 0;
            int j = 1;
            int maxLength = 1;
            Dictionary<char, int> dic = new Dictionary<char, int>();
            dic.Add(s[i], i);

            while (j < s.Length)
            {
                if (dic.ContainsKey(s[j]))
                {
                    if (dic[s[j]] >= i)
                    {
                        int length = j - i;
                        if (length > maxLength)
                            maxLength = length;
                        i = dic[s[j]] + 1;
                    }
                    dic[s[j]] = j;
                }
                else
                {
                    dic.Add(s[j], j);
                }
                ++j;
            }

            int len = j - i;
            if (len > maxLength)
                maxLength = len;

            return maxLength;
        }
    }
}
