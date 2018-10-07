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
		unordered_map<char, int> mp;
		for (const auto& v : s)
			++mp[v];
		for (size_t i = 0; i < s.size(); ++i)
			if (mp[s[i]] < 2)
				return i;
		return -1;
	}
};

int main()
{
	Solution s;
	cout << s.firstUniqChar("loveleetcode");



	return 0;
}