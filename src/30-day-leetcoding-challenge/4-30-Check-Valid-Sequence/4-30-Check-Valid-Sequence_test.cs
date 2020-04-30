using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace p_4_30
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
        public bool IsValidSequence(TreeNode root, int[] arr)
        {
            return dfs(root, arr, 0);
        }

        private bool dfs(TreeNode root, int[] arr, int i)
        {
            if (root == null)
            {
                return false;
            }

            var v = arr[i];
            if (root.val != v)
            {
                return false;
            }

            if (i + 1 == arr.Length)
            {
                return root.left == null && root.right == null;
            }

            return dfs(root.left, arr, i + 1) || dfs(root.right, arr, i + 1);
        }
    }


    public class Tests_p_4_30
    {
        [Test]
        public void Test_p_4_30()
        {

        }
    }
}
