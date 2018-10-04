#include "stdafx.h"

class Solution {
public:
// 	bool containsDuplicate(const vector<int>& nums) {
// 		unordered_set<int> st;
// 		for (const int& v : nums)
// 		{
// 			if (st.count(v) > 0)
// 				return true;
// 			st.insert(v);
// 		}
// 
// 		return false;
// 	}

	bool containsDuplicate(const vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[i] > nums[j])
				{
					break;
				}
				else if (nums[i] == nums[j])
				{
					return true;
				}
			}
		}
		return false;
	}
};

Solution g_s;

void test(const vector<int>& vecNums, bool expect) 
{
	bool b = g_s.containsDuplicate(vecNums);
	if (b != expect)
		cout << boolalpha << "expect " << expect << " face : " << b << endl;
	else
		cout << "equal" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	test({ 1, 2, 3, 4 }, false);
	test({ 1, 2, 1, 4 }, true);
	test({ 1, 2, 1 }, true);
	test({ 11, 24, 12, 4 }, false);
	test({1,25,2,30,3}, false);

}