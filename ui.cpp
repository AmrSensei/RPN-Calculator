#include <iostream>
#include "ui.h"
#include<iomanip>
#include<limits>
#include<cassert>
#include<sstream>
#include<cmath>
namespace
{
	void ignoreline()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	void custom_print(double num)
	{

		if (std::isfinite(num) && num >= -OO && num <= OO && num == std::trunc(num))
		{
			// if number is whole, or somehting like 1.23457e+06 convert it to ll.
			std::cout << static_cast<long long>(num);
		}
		else
		{
			std::cout << std::setprecision(8) << num;
		}
	}
	// helper functions.
	void evaluate(RPN& rpn)
	{
		std::cout << "Available Operators : " << '\n';
		for (auto& op : rpn.operators)
		{
			std::cout << op << ", ";
		}
		std::cout << '\n';
		std::cout << "Please enter a valid expression : ";
		std::string expression;
		std::getline(std::cin, expression);
		std::stringstream ss;
		ss << expression;
		std::string curr;

		rpn.reset_calculator();
		if (!(ss >> curr))
		{
			throw std::runtime_error("Empty input, nothing to evaluate!");
		}
		rpn.work(curr);
		while (ss >> curr)
		{
			rpn.work(curr);
		}
		if (!rpn.valid_res())
		{
			throw std::runtime_error("leftover operands!");
		}
		std::cout << "The result is = ";
		custom_print(rpn.get_ans());
		std::cout << '\n';
		rpn.success();
		std::cout << "Operation count is : " << rpn.get_cnt() << '\n' << '\n';
	}
	void clear(RPN& rpn)
	{
		std::string confirm;
		std::cout << "To confirm Clearing Type \"clear\" " << '\n';
		std::cin >> confirm;
		if (confirm == "clear")
		{
			rpn.reset_calculator();
			rpn.reset_counter();
			std::cout << "Calculator log cleared successfully!" << '\n' << '\n';
		}
	}
	bool quit()
	{
		std::string confirm;
		std::cout << "To confirm Quitting the program Type \"quit\" " << '\n';
		std::cin >> confirm;
		return confirm == "quit";
	}
	void print_stack(std::stack<double> st)
	{
		std::cout << "Stack contents : ";
		while (!st.empty())
		{
			custom_print(st.top());
			std::cout << " ";
			st.pop();
		}
		std::cout << '\n' << '\n';
	}
}

void rpn_loop()
{
	std::cout << "           RPN calculator" << '\n';
	std::cout << "---------------------------------------" << '\n';
	RPN rpn;
	while (true)
	{
		// prompting the user for what he wants to do.
		std::cout << "Please choose an option : " << '\n';
		std::cout << "1. Enter an Expression to evaluate." << '\n';
		std::cout << "2. Clear the Calculator." << '\n';
		std::cout << "3. Print the Stack " << '\n';
		std::cout << "4. Quit The Program" << '\n';
		int choice = -1;
		std::cin >> choice;
		if (!std::cin || (choice != 1 && choice != 2 && choice != 3 && choice != 4))
		{
			std::cout << "Please Enter a valid option!" << '\n' << '\n';
		}
		std::cin.clear();
		ignoreline();
		// to clear the buffer after choice.
		try
		{
			if (choice == 1)
			{
				evaluate(rpn);
			}
			else if (choice == 2)
			{
				clear(rpn);
			}
			else if (choice == 3)
			{
				std::stack<double>st = rpn.get_stack();
				print_stack(st);
			}
			else if (choice == 4)
			{
				if (quit())
				{
					std::cout << "Program terminating!" << '\n';
					return;
				}
			}
			
		}
		catch (std::runtime_error& e)
		{
			std::cout << "Error : " << e.what() << '\n' << '\n';
		}
		catch (std::out_of_range&)
		{
			std::cout << "Error : Number too big or small to handle!" << '\n' << '\n';
		}
		catch (std::invalid_argument&)
		{
			std::cout << "Error : " << "Invalid Operator or Invalid number(s)!" << '\n' << '\n';
		}
	}
}