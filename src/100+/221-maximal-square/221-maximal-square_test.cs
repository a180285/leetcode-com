using System;
using NUnit.Framework;

namespace p221
{
    public class Solution
    {
        public int MaximalSquare(char[][] m)
        {
            int r = m.Length;
            if (r == 0)
            {
                return 0;
            }
            int c = m[0].Length;
            if (c == 0)
            {
                return 0;
            }

            char[][] matrix = new char[r + 1][];

            matrix[0] = new char[c + 1];
            for (int i = 0; i < r; i++)
            {
                matrix[i + 1] = new char[c + 1];
                for (int j = 0; j < c; j++)
                {
                    matrix[i + 1][j + 1] = (char) ((m[i][j] == '1') ? 1 : 0);
                }
            }
            r += 1;
            c += 1;

            int[,] prefixSum = new int[r, c];
            for (int i = 1; i < r; i++)
            {
                for (int j = 1; j < c; j++)
                {
                    prefixSum[i, j] = matrix[i][j] + prefixSum[i - 1, j]
                        + prefixSum[i, j - 1] - prefixSum[i - 1, j - 1];
                }
            }


            int ret = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    for (int k = ret + 1; i + k < r && j + k < c; k++)
                    {
                        int area = prefixSum[i + k,j + k] - prefixSum[i,j + k]
                            - prefixSum[i + k,j] + prefixSum[i,j];
                        if (area != k * k)
                        {
                            break;
                        }
                        ret = k;
                    }
                }
            }

            return ret * ret;
        }
    }

    public class Tests_p221
    {
        [Test]
        public void Test_p221()
        {
            Solution s = new Solution();
            char[][] input = new char[][]
            {
                new char[]{ '1','0','1','0','0' },
                new char[]{ '1','0','1','1','1' },
                new char[]{ '1','1','1','1','1' },
                new char[]{ '1','0','0','1','0' }
            };

            Assert.AreEqual(4, s.MaximalSquare(input));
        }
    }
}
