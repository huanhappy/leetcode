#include "stdafx.h"

// 258. ��λ���
// ����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����
// 
// ʾ��:
// 
// ����: 38
// ���: 2 
// ����: ��λ��ӵĹ���Ϊ��3 + 8 = 11, 1 + 1 = 2�� ���� 2 ��һλ�������Է��� 2��
// ����:
// ����Բ�ʹ��ѭ�����ߵݹ飬���� O(1) ʱ�临�Ӷ��ڽ�����������
// 
class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;

		int a = num % 10;
		while (num / 10)
		{
			num /= 10;
			a += num % 10;
		}

		return addDigits(a);
	}
};