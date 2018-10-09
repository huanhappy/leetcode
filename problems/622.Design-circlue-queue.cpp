#include "stdafx.h"

// 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
// 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
// 你的实现应该支持如下操作：
// 
// MyCircularQueue(k) : 构造器，设置队列长度为 k 。
// Front : 从队首获取元素。如果队列为空，返回 - 1 。
// 	Rear : 获取队尾元素。如果队列为空，返回 - 1 。
// 		   enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
// 		   deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
// 		   isEmpty() : 检查循环队列是否为空。
// 		   isFull() : 检查循环队列是否已满。
// 		   示例：
// 
// 		   MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为3
// 
// circularQueue.enQueue(1);  // 返回true
// circularQueue.enQueue(2);  // 返回true
// circularQueue.enQueue(3);  // 返回true
// circularQueue.enQueue(4);  // 返回false,队列已满
// circularQueue.Rear();  // 返回3
// circularQueue.isFull();  // 返回true
// circularQueue.deQueue();  // 返回true
// circularQueue.enQueue(4);  // 返回true
// circularQueue.Rear();  // 返回4
// 提示：
// 所有的值都在 1 至 1000 的范围内；
// 操作数将在 1 至 1000 的范围内；
// 请不要使用内置的队列库
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