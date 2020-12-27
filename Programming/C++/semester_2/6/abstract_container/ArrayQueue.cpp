#include "classes.h"

ArrayStack::ArrayStack(const int& capacity) :capacity(capacity), top(-1)
{
	if (capacity <= 0)
		throw "Bad capacity";
	p = new int[capacity];
}
ArrayStack::ArrayStack(const ArrayStack &r)
{
	capacity = r.capacity;
	top = r.top;
	p = new int[capacity];
	for (int i = 0; i < top; i++)
		p[i] = r.p[i];
}
ArrayStack::~ArrayStack()
{
	delete[]p;
}
void ArrayStack::push(const int& n)
{
	if (!is_full())
		p[++top] = n;
}
int ArrayStack::pop()
{
	return p[top--];
}
bool ArrayStack::is_empty() const
{
	return top == -1;
}
bool ArrayStack::is_full() const
{
	return (top == capacity - 1);
}


ListStack::ListStack() :top(0) {}
ListStack::ListStack(const ListStack& r)
{
	top = 0;
	node* tmp = r.top;
	while (tmp)
	{
		push(tmp->item);
		tmp = tmp->prev;
	}
}
ListStack::~ListStack()
{
	node* tmp;
	while (top)
	{
		tmp = top;
		top = top->prev;
		delete tmp;
	}
}
void ListStack::push(const int& n)
{
	node* tmp = new node;
	tmp->prev = top;
	tmp->item = n;
	top = tmp;
}
int ListStack::pop()
{
	node* tmp = top;
	int t = top->item;
	top = top->prev;
	delete tmp;
	return t;
}
bool ListStack::is_empty() const
{
	return top == 0;
}


ArrayQueue::ArrayQueue(const int& capacity) :capacity(capacity), head(0), tail(0)
{
	if (capacity <= 0)
		throw "Wrong capacity!";
	p = new int[capacity];
}
ArrayQueue::ArrayQueue(const ArrayQueue& r) :capacity(r.capacity), head(r.head), tail(r.tail)
{
	p = new int[capacity];
	for (int i = head; i < tail; i++)
		p[i] = r.p[i];
}
ArrayQueue::~ArrayQueue()
{
	head = 0;
	tail = head;
	delete[]p;
}
void ArrayQueue::ins(const int& n)
{
	if (is_full())
		throw "Queue is full!";
	p[tail++] = n;
}
int ArrayQueue::del()
{
	return p[head++];
}
bool ArrayQueue::is_empty() const
{
	return tail == head;
}
bool ArrayQueue::is_full() const
{
	if (head != 0)
		return tail == head;
	else return tail == capacity;
}
void ArrayQueue::print(ostream &out) const
{
	for (int i = head; i < tail; i++)
		out << p[i] << " ";
	out << endl;
}


ListQueue::ListQueue() :head(0), tail(0) {}
ListQueue::ListQueue(const ListQueue& r) : head(r.head), tail(r.tail)
{
	node* tmp = r.head;
	while (tmp != r.tail)
	{
		ins(tmp->item);
		tmp = tmp->next;
	}
	if (head == tail) ins(tmp->item);
}
ListQueue::~ListQueue()
{
	while (!is_empty())
		del();
}
void ListQueue::ins(const int& n)
{
	node* tmp = new node;
	tmp->item = n;
	tmp->next = NULL;
	if (head != NULL)
	{
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = tmp;
		tail = head;
	}
}
int ListQueue::del()
{
	node* tmp = head;
	int res = tmp->item;
	head = head->next;
	delete tmp;
	return res;
}
bool ListQueue::is_empty() const
{
	return head == 0;
}
void ListQueue::print(ostream &out) const
{
	node* tmp = head;
	while (tmp != tail)
	{
		out << tmp->item << " ";
		tmp = tmp->next;
	}
	out << tmp->item << endl;
}

void ArrayDeque::ins_head(const int& n)
{
	if (!head)
	{
		head = capacity;
	}
	p[--head] = n;
}
void ArrayDeque::ins_tail(const int& n)
{
	ins(n);
}
int ArrayDeque::del_head()
{
	return del();
}
int ArrayDeque::del_tail()
{
	return p[--tail];
}
bool ArrayDeque::is_empty() const
{
	return ArrayQueue::is_empty();
}
bool ArrayDeque::is_full() const
{
	return ArrayQueue::is_full();
}
void ArrayDeque::print(ostream &out) const
{
	if (head > tail)
	{
		for (int i = head; i < capacity; i++)
			out << p[i] << " ";
		for (int i = 0; i < tail; i++)
			out << p[i] << " ";
		out << endl;
	}
	else ArrayQueue::print(out);
}

void ListDeque::ins_head(const int& n)
{
	node* tmp = new node;
	tmp->item = n;
	tmp->prev = NULL;
	if (tail != NULL)
	{
		head->prev = tmp;
		head = tmp;
	}
	else
	{
		tail = tmp;
		head = tail;
	}
}
void ListDeque::ins_tail(const int& n)
{
	ins(n);
}
int ListDeque::del_head()
{
	return del();
}
int ListDeque::del_tail(){ return 0; }
bool ListDeque::is_empty() const
{
	return ListQueue::is_empty();
}
bool ListDeque::is_full() const{ return 0; }
void ListDeque::print(ostream &out) const
{

	ListQueue::print(out);
}