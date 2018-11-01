#include "stdafx.h"

// 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i, ai) 。
// 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为(i, ai) 和(i, 0)。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 
// 说明：你不能倾斜容器，且 n 的值至少为 2。
// https://leetcode-cn.com/problems/container-with-most-water/description/
// 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
// 
// 
// 
// 例:
// 
// 输入 : [1, 8, 6, 2, 5, 4, 8, 3, 7]
// 输出 : 49
// 
// 难度：中等
// 
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(const vector<int>& height)
	{
		int nMaxArea = 0;
		for (size_t i = 0; i < height.size(); ++i)
		{
			const int y1 = height[i];
			for (size_t j = i + 1; j < height.size(); ++j)
			{
				const int y2 = height[j];

				const int area = min(y1, y2) * (j - i);
				nMaxArea = max(nMaxArea, area);
			}
		}

		return nMaxArea;
	}
};

int main()
{
	Solution s;
	int m = s.maxArea({ 1, 8, 6, 2, 5, 4, 8, 3, 7 });

	return 0;
}