#include "stdafx.h"

// ���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ����(i, ai) ��
// �������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ(i, ai) ��(i, 0)��
// �ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
// 
// ˵�����㲻����б�������� n ��ֵ����Ϊ 2��
// https://leetcode-cn.com/problems/container-with-most-water/description/
// ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ 49��
// 
// 
// 
// ��:
// 
// ���� : [1, 8, 6, 2, 5, 4, 8, 3, 7]
// ��� : 49
// 
// �Ѷȣ��е�
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