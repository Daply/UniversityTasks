#include <iostream>
using namespace std;

class AbstractContainer
{
public:
	virtual ~AbstractContainer() {}
	virtual bool is_empty() const = 0;
	virtual bool is_full() const = 0;
};

class AbstractStack :public AbstractContainer
{
public:
	virtual void push(const int& n) = 0;
	virtual int pop() = 0;
};

class AbstractQueue :public AbstractContainer
{
public:
	virtual void ins(const int& n) = 0;
	virtual int del() = 0;
	virtual void print(ostream& out) const = 0;
};

class ArrayStack : public AbstractStack
{
	int capacity;
	int *p;
	int top;
public:
	ArrayStack(const int& capacity = 5);
	ArrayStack(const ArrayStack &r);
	~ArrayStack();
	void push(const int& n);
	int pop();
	bool is_empty() const;
	bool is_full() const;
	friend class ArrayStackIterator;
};

class ListStack :public AbstractStack
{
	struct node
	{
		int item;
		node* prev;
	};
	node *top;
	bool is_full() const { return false; }
public:
	ListStack();
	ListStack(const ListStack& r);
	~ListStack();
	void push(const int& n);
	int pop();
	bool is_empty() const;
	friend class ListStackIterator;
};

class ArrayQueue : public AbstractQueue
{
protected:
	int capacity;
	int*p;
	int head, tail;
public:
	ArrayQueue(const int& capacity = 5);
	ArrayQueue(const ArrayQueue& r);
	virtual ~ArrayQueue();
	void ins(const int& n);
	int del();
	bool is_empty() const;
	bool is_full() const;
	void print(ostream &out) const;
	friend class ArrayQueueIterator;
	friend class ArrayDequeIterator;
};

class ListQueue :public AbstractQueue
{
protected:
	struct node
	{
		int item;
		node* next;
		node* prev;
	}
	*head, *tail;
	bool is_full() const { return false; }
public:
	ListQueue();
	ListQueue(const ListQueue& r);
	~ListQueue();
	void ins(const int& n);
	int del();
	bool is_empty() const;
	void print(ostream &out) const;
	friend class ListQueueIterator;
};

class ArrayDeque :public ArrayQueue
{
public:
	ArrayDeque(const int& capacity) :ArrayQueue(capacity) {}
	ArrayDeque(const ArrayDeque& r) :ArrayQueue(r) {}
	void ins_head(const int& n);
	void ins_tail(const int& n);
	int del_head();
	int del_tail();
	bool is_empty() const;
	bool is_full() const;
	void print(ostream &out) const;
};

class ListDeque :public ListQueue
{
public:
	ListDeque() :ListQueue() {}
	ListDeque(const ListDeque& r) : ListQueue(r){}
	void ins_head(const int& n);
	void ins_tail(const int& n);
	int del_head();
	int del_tail();
	bool is_empty() const;
	bool is_full() const;
	void print(ostream &out) const;
	friend class ListDequeIterator;
};

class AbstractIterator
{
public:
	virtual bool in_range() const = 0;
	virtual int& operator*() const = 0;
	virtual void operator++() = 0;
	virtual void reset_begin() = 0;
};

class ArrayStackIterator :public AbstractIterator
{
	ArrayStack& a;
	int pos;
public:
	ArrayStackIterator(ArrayStack& a) : a(a), pos(0) {}
	bool in_range() const
	{
		return pos >= 0 && pos <= a.top;
	}
	void reset_begin() { pos = 0; }
	void operator++()
	{
		++pos;
	}
	int& operator*() const
	{
		return a.p[pos];
	}
};

class ListStackIterator :public AbstractIterator
{
	const ListStack& a;
	ListStack::node* pos;
public:
	ListStackIterator(const ListStack& a) : a(a), pos(a.top) {}
	bool in_range() const { return pos; }
	void reset_begin() { pos = a.top; }
	int& operator*() const { return pos->item; }
	void operator++() { pos = pos->prev; }
};

class ArrayQueueIterator :public AbstractIterator
{
protected:
	const ArrayQueue& a;
	int pos;
public:
	ArrayQueueIterator(const ArrayQueue& a) : a(a), pos(a.head) {}
	virtual ~ArrayQueueIterator();
	virtual bool  in_range() const
	{
		return pos >= a.head && pos < a.tail;
	}
	virtual void reset_begin() { pos = a.head; }
	virtual int& operator *() const { return a.p[pos]; }
	virtual void operator++() { pos++; }
};

class ListQueueIterator :public AbstractIterator
{
	ListQueue& a;
	ListQueue::node* pos;
public:
	ListQueueIterator(ListQueue& a) : a(a), pos(a.head) {}
	bool in_range() const { return pos; }
	void reset_begin() { pos = a.head; }
	int& operator*() const { return pos->item; }
	void operator++() { pos = pos->next; }
};

class ArrayDequeIterator :public ArrayQueueIterator
{
public:
	ArrayDequeIterator(const ArrayQueue& a) :ArrayQueueIterator(a) {}
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
	void reset_end() { pos = a.tail - 1; }
	void operator--()
	{
		pos--;
	}
};