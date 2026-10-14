#include<limits>
#include<stdexcept>
#include<cmath>
#include<iomanip>
#include<cassert>
#include "rpn.h"

RPN::RPN() :
	total_counter{ 0 },
	curr_counter{ 0 }
{
	
}
// only calculate the answer of an expression, can be const.
double RPN::calc(double x, double y, const std::string& op) const
{
	double res = 0;
	if (op == "+")
	{
		res = x + y;
	}
	else if (op == "-")
	{
		res = x - y;
	}
	else if (op == "*")
	{
		res = x * y;
	}
	else if (op == "/")
	{
		if (y == 0)
		{
			throw std::runtime_error("Division by zero is undefined!");
		}
		res = x / y;
	}
	else if (op == "^")
	{
		res = std::pow(x, y);
	}
	else
	{
		assert(false && "Invalid operand, Check if you added the operand in \"is_op\" function");
		throw std::runtime_error("Programmer bug : Unhandled Operator!");
	}
	return res;
}

// checks whether an expression is an operators or not, can be const.
bool RPN::is_op(const std::string& op) const
{
	for (auto& s : operators)
	{
		if (op == s)
		{
			return true;
		}
	}
	return false;
}

// checks stack size, can be const.
bool RPN::valid_res() const
{
	return st.size() == 1;
}

// doesn't change any member value, therefore can be const.
double RPN::get_ans() const
{
	if (st.empty())
	{
		throw std::runtime_error("Stack is Empty, Please Enter a valid expression ");
	}
	return st.top();
}

void RPN::success()
{
	total_counter += curr_counter;
}

void RPN::reset_counter()
{
	total_counter = 0;
}

void RPN::reset_calculator()
{
	while (!st.empty())
	{
		st.pop();
	}
	curr_counter = 0;
}

// only gets the counter, can be const.
int RPN::get_cnt() const
{
	return total_counter;
}

void RPN::work(const std::string& curr)
{
	if (is_op(curr))
	{
		if (st.size() < 2)
		{
			throw std::runtime_error("Not enough operands to perform operation!");
		}
		double y = st.top();
		st.pop();
		double x = st.top();
		st.pop();
		double result = calc(x, y, curr);
		// result is oo, -oo, Nan, or so on...
		if (!std::isfinite(result))
		{
			throw std::runtime_error("Invalid Result!");
		}
		st.push(result);
		curr_counter++;
	}
	else
	{
		std::size_t pos = 0;
		double x = std::stod(curr, &pos);
		/*
			pos is the position after the last one processed
			if its smaller than the string size, that means
			the string wasn't fully processed.

			something like 3abc.
		*/
		if (pos < curr.size())
		{
			throw std::invalid_argument("");
		}
		// result is oo, -oo, Nan, or so on...
		if (!std::isfinite(x))
		{
			throw std::runtime_error("Invalid Input!");
		}
		st.push(x);
	}
}

// get the stack in reversed order so when its printed its ordered.
std::stack<double> RPN::get_stack() const
{
	if (st.empty())
	{
		throw std::runtime_error("Stack is Empty, Enter an Expression to Evaluate first.");
	}
	std::stack<double>cpy, save = st;
	while (!save.empty())
	{
		cpy.push(save.top());
		save.pop();
	}
	return cpy;
}