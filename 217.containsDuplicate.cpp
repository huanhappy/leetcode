#include "stdafx.h"

class Solution {
public:
	bool containsDuplicate(const vector<int>& nums) {
		unordered_set<int> st;
		for (const int& v : nums)
		{
			if (st.count(v) > 0)
				return true;
			st.insert(v);
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

}