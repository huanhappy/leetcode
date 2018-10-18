#include "stdafx.h"
#include <sstream>

// The count-and-say sequence is the sequence of integers with the first five terms as following:
// 
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// 
// Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.
// 
// Note: Each term of the sequence of integers will be represented as a string.
// 
//  
// 
// Example 1:
// 
// Input: 1
// Output: "1"
// Example 2:
// 
// Input: 4
// Output: "1211"
// 

class Solution {
public:
	string countAndSay(int n) {

		string res = "1";
		while (n-- > 1)
		{
			string s;
			int ct = 1;
			char c = res.front();
			for (int i = 1; i < res.length(); ++i)
			{
				if (res[i] == c)
					++ct;
				else
				{
					s += tostr(ct, c);
					ct = 1;
					c = res[i];
				}
			}

			if (ct > 0)
				s += tostr(ct, c);

			res = s;
		}

		return res;
	}

	string tostr(int ct, char c)
	{
		stringstream ss;
		ss << ct << c;
		return ss.str();
	}
};

int lengthOfLastWord(string s) {
	if (s == "" || s == " ")
		return 0;

	int posEnd = s.size() - 1;


	while (s[posEnd] == ' '&& posEnd >= 0)
		--posEnd;
	int posFirst = posEnd;

	while (s[posFirst] != ' '&&posFirst >= 0)
		--posFirst;
	return posEnd - posFirst;
}

int main()
{
	string ss = "c";
	cout << lengthOfLastWord(ss);
	return 0;

	Solution s;

	for (int i = 1; i < 7; ++i)
		cout << i << ":"<<  s.countAndSay(i) << endl;

	return 0;
}