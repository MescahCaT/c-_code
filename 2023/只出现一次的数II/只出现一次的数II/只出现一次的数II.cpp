#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
// https://leetcode.cn/problems/single-number-ii/

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            int count = 0;
            for (int num : nums)
            {
                count += (num >> i) & 1;
            }
            ret |= (count % 4) << i;
        }

        return ret;
    }
};

int main()
{
    vector<int> v{ 1 ,1 ,1, 2, 1, 5 , 5,5,5 };
    cout << Solution().singleNumber(v) << endl;

	return 0;
}
