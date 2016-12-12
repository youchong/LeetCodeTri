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
    }
}
