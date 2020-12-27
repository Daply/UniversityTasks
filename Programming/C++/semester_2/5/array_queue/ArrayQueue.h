#include <iostream>

using namespace std;

class ArrayQueue
{
protected:
	int capacity;
	int* p;
	int head;
	int tail;
	ArrayQueue();
public:
	ArrayQueue(const int& capacity) :capacity(capacity), head(0), tail(0)
	{
		p = new int[capacity];
	}
	ArrayQueue(const ArrayQueue& q) : capacity(q.capacity), head(q.head), tail(q.tail)
	{
		p = new int[capacity];
		for (int i = head; i<tail; i++)
		{
			p[i] = q.p[i];
		}
	}
	virtual ~ArrayQueue()
	{
		tail = 0;
		head = 0;
		delete[]p;
	}
	void push(const int& n)
	{
		p[tail++] = n;
	}
	int pop()
	{
		return p[head++];
	}
	virtual bool is_empty() const
	{
		return tail == head;
	}
	virtual bool is_full() const
	{
		return tail == capacity;
	}
	virtual void print(ostream& out) const
	{
		for (int i = head; i<tail; i++)
		{
			out << p[i] << " ";
		}
		out << endl;
	}
	friend class ArrayQueueIterator;
	friend class ArrayDequeIterator;
};

class ArrayDeque: public ArrayQueue
{
public:
	ArrayDeque(const int& capacity) :ArrayQueue(capacity) {}
	ArrayDeque(const ArrayDeque& d) : ArrayQueue(d) {}
	void push_head(const int& n)
	{
		if (head == 0)
		{
			++tail;
			for (int i = tail - 1; i > 0; i--)
				p[i] = p[i - 1];
			p[0] = n;
		}
		else p[--head] = n;
	}
	void push_tail(const int& n)
	{
		p[tail++] = n;
	}
	int pop_head()
	{
		return p[head++];
	}
	int pop_tail()
	{
		return p[--tail];
	}
	bool is_empty() const
	{
		return tail == head;
	}
	bool is_full() const
	{
		return tail == capacity;
	}
	void print(ostream& out) const
	{
		ArrayQueue::print(out);
	}
};

class ArrayQueueIterator
{
protected:
	const ArrayQueue& q;
	int pos;
	ArrayQueueIterator();
public:
	ArrayQueueIterator(const ArrayQueue& q) :q(q), pos(q.head) {}
	virtual bool  in_range() const
	{
		return pos >= q.head && pos < q.tail;
	}
	virtual void reset_begin()
	{
		pos = q.head;
	}
	virtual int& operator *() const
	{
		if (in_range())
			return q.p[pos];
	}
	virtual void operator++()
	{
		pos++;
	}
};

class ArrayDequeIterator :public ArrayQueueIterator
{
public:
	ArrayDequeIterator(const ArrayQueue& q) :ArrayQueueIterator(q) {}
	bool  in_range() const
	{
		return ArrayQueueIterator::in_range();
	}
	void reset_begin()
	{
		ArrayQueueIterator::reset_begin();
	}
	int& operator *() const
	{
		return ArrayQueueIterator::operator*();
	}
	void operator++()
	{
		ArrayQueueIterator::operator++();
	}
	void reset_end()
	{
		pos = q.tail - 1;
	}
	void operator--()
	{
		pos--;
	}
};