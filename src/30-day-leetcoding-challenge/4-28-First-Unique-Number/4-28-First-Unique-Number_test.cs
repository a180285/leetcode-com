using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace p_4_28
{

    public class FirstUnique
    {
        Dictionary<int, int> numCount;
        List<int> numbers;
        int uniqueIndex;

        public FirstUnique(int[] nums)
        {
            numCount = new Dictionary<int, int>();
            numbers = new List<int>(nums);
            for (int i = 0; i < numbers.Count; i++)
            {
                int v = numbers[i];
                if (!numCount.ContainsKey(v))
                {
                    numCount.Add(v, 0);
                }
                numCount[numbers[i]]++;
            }
            while (uniqueIndex < numbers.Count)
            {
                var v = numbers[uniqueIndex];
                if (numCount[v] == 1)
                {
                    break;
                }
                uniqueIndex++;
            }
        }

        public int ShowFirstUnique()
        {
            if (uniqueIndex < numbers.Count)
            {
                return numbers[uniqueIndex];
            }
            else
            {
                return -1;
            }
        }

        public void Add(int value)
        {
            numbers.Add(value);
            if (!numCount.ContainsKey(value))
            {
                numCount.Add(value, 0);
            }
            numCount[value]++;

            while (uniqueIndex < numbers.Count)
            {
                var v = numbers[uniqueIndex];
                if (numCount[v] == 1)
                {
                    break;
                }
                uniqueIndex++;
            }
        }
    }

    /**
     * Your FirstUnique object will be instantiated and called as such:
     * FirstUnique obj = new FirstUnique(nums);
     * int param_1 = obj.ShowFirstUnique();
     * obj.Add(value);
     */
    public class Tests_p_4_28
    {
        [Test]
        public void Test_p_4_28()
        {
            Console.WriteLine("Start test.");

            FirstUnique firstUnique = new FirstUnique(new int[] { 809 });

            Console.WriteLine("init done.");

            var ret = firstUnique.ShowFirstUnique(); // return 809
            Assert.AreEqual(809, ret);
            firstUnique.Add(809);          // the queue is now [809,809]
            ret = firstUnique.ShowFirstUnique(); // return -1
            Assert.AreEqual(-1, ret);
        }
    }
}
