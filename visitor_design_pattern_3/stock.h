#pragma once

#include <iostream>

class apple;
class google;

class visitor
{
public:
	virtual void visit(apple*) = 0;
	virtual void visit(google*) = 0;

	static int m_num_apple;
	static int m_num_google;

	void total_stocks()
	{
		std::cout << "number of apples: " << m_num_apple << '\n';
		std::cout << "number of google: " << m_num_google << '\n';
	}
};

int visitor::m_num_apple = 0;
int visitor::m_num_google = 0;

class stock
{
public:
	virtual void accept(class visitor*) = 0;
};

class apple : public stock
{
public:
	void accept(visitor* v)
	{
		v->visit(this);
	}

	void buy()
	{
		std::cout << "apple::buy\n";
	}

	void sell()
	{
		std::cout << "apple::sell\n";
	}
};

class google : public stock
{
public:
	void accept(visitor* v)
	{
		v->visit(this);
	}

	void buy()
	{
		std::cout << "google::buy\n";
	}

	void sell()
	{
		std::cout << "google::sell\n";
	}
};

class buy_visitor : public visitor
{
public:
	buy_visitor()
	{
		// m_num_apple = m_num_google = 0;
	}

	void visit(apple* a) override
	{
		++m_num_apple;
		a->buy();
		std::cout << "m_num_apple: " << m_num_apple << '\n';
	}

	void visit(google* g) override
	{
		++m_num_google;
		g->buy();
		std::cout << "m_num_google: " << m_num_google << '\n';
	}
};

class sell_visitor : public visitor
{
public:
	sell_visitor()
	{
		// m_num_apple = m_num_google = 0;
	}

	void visit(apple* a) override
	{
		--m_num_apple;
		a->sell();
		std::cout << "m_num_apple: " << m_num_apple << '\n';
	}

	void visit(google* g) override
	{
		--m_num_google;
		g->sell();
		std::cout << "m_num_google: " << m_num_google << '\n';
	}
};
