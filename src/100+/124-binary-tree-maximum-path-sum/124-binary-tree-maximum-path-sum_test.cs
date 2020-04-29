using System;
using NUnit.Framework;

namespace p124
{
     public class TreeNode {
         public int val;
         public TreeNode left;
         public TreeNode right;
         public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
             this.val = val;
             this.left = left;
             this.right = right;
         }
     }


    public class Solution
    {
        public int MaxPathSum(TreeNode root)
        {
            return _MaxPathSum(root).Item1;
        }

        (int, int) _MaxPathSum(TreeNode root)
        {
            if (root == null)
            {
                return (int.MinValue, 0);
            }
            var left = _MaxPathSum(root.left);
            var right = _MaxPathSum(root.right);

            int singlePath = Math.Max(left.Item2, right.Item2) + root.val;
            singlePath = Math.Max(0, singlePath);

            int maxSum = left.Item2 + right.Item2 + root.val;
            maxSum = Math.Max(maxSum, left.Item1);
            maxSum = Math.Max(maxSum, right.Item1);

            return (maxSum, singlePath);
        }
    }

    public class Tests_p124
    {
        [Test]
        public void Test_p124()
        {
            //Solution s = new Solution();
            //Assert.AreEqual(0, s.MaxPathSum());
        }
    }
}
