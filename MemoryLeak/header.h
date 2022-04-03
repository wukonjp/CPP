#pragma once

class P
{
public:
	double x;

	void* operator new(size_t size)
	{
		void* heap = _malloc_dbg(size, _NORMAL_BLOCK, __FILE__, __LINE__);
		return heap;
	}

	void operator delete(void* heap)
	{
		_free_dbg(heap, _NORMAL_BLOCK);
	}

	P()
	{
		x = 1;
	}

	~P()
	{
		x = 0;
	}
};

class Q
{
public:
	double y;

	void* operator new(size_t size)
	{
		void* heap = _malloc_dbg(size, _NORMAL_BLOCK, __FILE__, __LINE__);
		return heap;
	}

	void operator delete(void* heap)
	{
		_free_dbg(heap, _NORMAL_BLOCK);
	}

	Q()
	{
		y = 2;
	}

	~Q()
	{
		y = 0;
	}
};

class A
{
public:
	P* p;

	A()
	{
		p = new P;
	}

	~A()
	{
		delete p;
	}
};

class B
{
public:
	Q* q;

	B()
	{
		q = new Q;
	}

	~B()
	{
		delete q;
	}
};

class C
{
private:
	A a;
	B b;

public:
	C()
	{
	}

	double Get()
	{
		return a.p->x + b.q->y;
	}
};

