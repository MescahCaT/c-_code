#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


// ����һ���������� nums ����ĳ��Ԫ�ؽ����� һ�� �⣬����ÿ��Ԫ�ض�ǡ���� ���� �������ҳ��������Ǹ�ֻ������һ�ε�Ԫ�ء�
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
