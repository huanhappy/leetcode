#include "stdafx.h"
// Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
// Examples:
// s = "leetcode"
// return 0.
// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
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