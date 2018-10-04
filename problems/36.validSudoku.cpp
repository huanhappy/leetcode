#include "stdafx.h"
// leetcode : 36 有效的数独
// 难度： 中等
/*
 *Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

 Each row must contain the digits 1-9 without repetition.
 Each column must contain the digits 1-9 without repetition.
 Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1 - 9 在每一行只能出现一次。
数字 1 - 9 在每一列只能出现一次。
数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。



上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入 :
	[
		["5", "3", ".", ".", "7", ".", ".", ".", "."],
		["6", ".", ".", "1", "9", "5", ".", ".", "."],
		[".", "9", "8", ".", ".", ".", ".", "6", "."],
		["8", ".", ".", ".", "6", ".", ".", ".", "3"],
		["4", ".", ".", "8", ".", "3", ".", ".", "1"],
		["7", ".", ".", ".", "2", ".", ".", ".", "6"],
		[".", "6", ".", ".", ".", ".", "2", "8", "."],
		[".", ".", ".", "4", "1", "9", ".", ".", "5"],
		[".", ".", ".", ".", "8", ".", ".", "7", "9"]
	]
输出: true
	示例 2 :

输入 :
   [
	   ["8", "3", ".", ".", "7", ".", ".", ".", "."],
	   ["6", ".", ".", "1", "9", "5", ".", ".", "."],
	   [".", "9", "8", ".", ".", ".", ".", "6", "."],
	   ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
	   ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
	   ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
	   [".", "6", ".", ".", ".", ".", "2", "8", "."],
	   [".", ".", ".", "4", "1", "9", ".", ".", "5"],
	   [".", ".", ".", ".", "8", ".", ".", "7", "9"]
   ]
输出: false
解释 : 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
	 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
 说明 :

	一个有效的数独（部分已被填充）不一定是可解的。
		只需要根据以上规则，验证已经填入的数字是否有效即可。
		给定数独序列只包含数字 1 - 9 和字符 '.' 。
		给定数独永远是 9x9 形式的。

*/


class Solution {
public:
	//  [2018/10/04  created by RockLee]
	bool isValidSudoku(vector<vector<char>>& board) {

		unordered_map<int, int> mp;
		//Each row must contain the digits 1 - 9 without repetition.
		for (int i = 0; i < 9; ++i)
		{
			mp.clear();
			const auto& row = board[i];
			for (int j = 0; j < 9; ++j)
			{
				if (row[j] != '.')
				{
					++mp[row[j]];
					if (mp[row[j]] >1)
						return false;
				}
			}
		}

		//Each column must contain the digits 1 - 9 without repetition.
		for (int i = 0; i < 9; ++i)
		{
			mp.clear();
			for (int j = 0; j < 9; ++j)
			{
				const char& ch = board[j][i];
				if (ch != '.')
				{
					++mp[ch];
					if (mp[ch] >1)
						return false;
				}
			}
		}

		//Each of the 9 3x3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
		for (int i = 0; i < 9; i+=3)
		{
			for (int j = 0; j < 9; j+=3)
			{
				mp.clear();
				// sub
				for (int ii = 0; ii < 3; ++ii)
				{
					for (int jj = 0; jj < 3; ++jj)
					{
						const char& ch = board[i+ii][j+jj];
						if (ch != '.')
						{
							++mp[ch];
							if (mp[ch] > 1)
								return false;
						}
					} // jj
				} // ii
			}// j
		} // i


		return true;
	}
};

int main()
{
	vector<vector<char> > v = 
	{
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	Solution s;
	cout << boolalpha;
	cout << s.isValidSudoku(v);

	v = {
		{ '8', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	cout << s.isValidSudoku(v);



	return 0;
}