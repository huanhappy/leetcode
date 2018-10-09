#include "stdafx.h"

// ������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
// ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
// ���ʵ��Ӧ��֧�����²�����
// 
// MyCircularQueue(k) : �����������ö��г���Ϊ k ��
// Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
// 	Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
// 		   enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
// 		   deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
// 		   isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
// 		   isFull() : ���ѭ�������Ƿ�������
// 		   ʾ����
// 
// 		   MyCircularQueue circularQueue = new MycircularQueue(3); // ���ó���Ϊ3
// 
// circularQueue.enQueue(1);  // ����true
// circularQueue.enQueue(2);  // ����true
// circularQueue.enQueue(3);  // ����true
// circularQueue.enQueue(4);  // ����false,��������
// circularQueue.Rear();  // ����3
// circularQueue.isFull();  // ����true
// circularQueue.deQueue();  // ����true
// circularQueue.enQueue(4);  // ����true
// circularQueue.Rear();  // ����4
// ��ʾ��
// ���е�ֵ���� 1 �� 1000 �ķ�Χ�ڣ�
// ���������� 1 �� 1000 �ķ�Χ�ڣ�
// �벻Ҫʹ�����õĶ��п�
// 
class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		m_array.resize(k);
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
			return false;

		if (isEmpty())
			m_posFront = m_posBack = 0;
		else
		{
			++m_posBack;
			m_posBack %= m_array.size();
		}
		
		m_array[m_posBack] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
			return false;

		if (m_posFront == m_posBack)
		{
			m_posFront = m_posBack = -1;
		}
		else
		{
			++m_posFront;
			m_posFront %= m_array.size();
		}

		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty())
			return -1;
		return m_array[m_posFront];

	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty())
			return -1;
		return m_array[m_posBack];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return m_posFront == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return (m_posBack + m_array.size() - m_posFront) % m_array.size() + 1 == m_array.size();

	}

private:
	std::vector<int> m_array;
	int m_posFront = -1;
	int m_posBack = -1;
};

/**
* Your MyCircularQueue object will be instantiated and called as such:

*/

int main()
{
	MyCircularQueue obj = MyCircularQueue(3);
	cout << boolalpha;
	cout << " " << obj.enQueue(1);
	cout << " " << obj.enQueue(2);
	cout << " " << obj.enQueue(3);
	cout << " " << obj.enQueue(4);
	cout << " " << obj.Rear();
	cout << " " << obj.isFull();
	cout << " " << obj.deQueue();
	cout << " " << obj.enQueue(4);
	cout << " " << obj.Rear();

	return 0;
}