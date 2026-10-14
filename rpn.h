#pragma once
#include<stack>
#include <string>
class RPN
{
private:
	std::stack<double>st;
	int total_counter;
	int curr_counter;
	
	double calc(double x, double y, const std::string& op) const;
	bool is_op(const std::string& op) const;

public:

	inline static const std::string operators[5] = { "+","-","*","/","^" };

	RPN();

	bool valid_res() const;
	double get_ans() const;
	void success();
	void reset_counter();
	void reset_calculator();
	int get_cnt() const;
	void work(const std::string& curr);
	std::stack<double> get_stack() const;
};