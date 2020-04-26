using System;
using NUnit.Framework;

namespace p1143
{
    public class Solution
    {
        public int LongestCommonSubsequence(string text1, string text2)
        {
            text1 = "+" + text1;
            text2 = "-" + text2;
            int[,] dp = new int[text1.Length, text2.Length];
            for (int i = 1; i < text1.Length; i++) {
                for (int j = 1; j < text2.Length; j++) {
                    dp[i, j] = Math.Max(dp[i - 1, j - 1] + (text1[i] == text2[j] ? 1 : 0),
                        Math.Max(dp[i - 1, j], dp[i, j - 1])) ;
                }
            }
            return dp[text1.Length - 1, text2.Length - 1];
        }
    }

    public class Tests_p1143
    {
        [Test]
        public void Test_p1143()
        {
            Solution s = new Solution();
            Assert.AreEqual(s.LongestCommonSubsequence("abcde", "ace"), 3);
        }
    }
}