#include "stdafx.h"
// Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
// Examples:
// s = "leetcode"
// return 0.
// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.
// ����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
// 
class Solution {
public:
	int firstUniqChar(string s) {
		if (s.empty())
			return -1;

		int mp[26];
		memset(mp, -1, sizeof(mp));
		for (size_t i = 0; i < s.size(); ++i)
		{
			int c = s[i] - 'a';
			if (mp[c] > -1)
				mp[c] = -2;
			if (mp[c] == -1)
				mp[c] = i;
		}
		int res = -1;
		for (int i = 0; i < 26; ++i)
		{
			if (mp[i]>-1)
			{
				if (res < 0 || res > mp[i])
					res = mp[i];
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.firstUniqChar("loveleetcode");



	return 0;
}