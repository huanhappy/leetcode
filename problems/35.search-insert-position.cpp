#include "stdafx.h"
// 
// ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
// ���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
// ����Լ������������ظ�Ԫ�ء�
// 
// ʾ�� 1:
// 
// ����: [1,3,5,6], 5
// ���: 2
// ʾ�� 2:
// 
// ����: [1,3,5,6], 2
// ���: 1
// ʾ�� 3:
// 
// ����: [1,3,5,6], 7
// ���: 4
// ʾ�� 4:
// 
// ����: [1,3,5,6], 0
// ���: 0
// 

class Solution {
public:
	int searchInsert(const vector<int>& nums, int target) {
// 		if (nums.empty())
// 			return 0;
// 		int low = 0, high = nums.size() - 1;
// 		while (low <= high)
// 		{
// 			int mid = low + (high - low) / 2;
// 			if (nums[mid] == target)
// 				return mid;
// 			else if (nums[mid] < target)
// 				low = mid + 1;
// 			else
// 				high = mid-1;
// 		}
// 		return high + 1;
		auto it = lower_bound(nums.begin(), nums.end(), target);;
		return it - nums.begin();
	}
};

int main()
{
	Solution s;
	cout << s.searchInsert({ 1, 3, 5, 6 }, 5);
	cout << s.searchInsert({ 1, 3, 5, 6 }, 2);
	cout << s.searchInsert({ 1, 3, 5, 6 }, 7);
	cout << s.searchInsert({ 1, 3, 5, 6 }, 0);
}