/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:08:46 by forsili           #+#    #+#             */
/*   Updated: 2021/05/04 19:32:53 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	Bureaucrat mimmo("Mimmo", 1);
	Bureaucrat giggi("Giggi", 150);
	Form		form1("AX34BL_Bis", 3, 1);
	Form		form2("Default", 150, 75);

	try
	{
		giggi.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << RED << form1 << OFF;
	try
	{
		mimmo.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << RED << form1 << OFF;
	try
	{
		giggi.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << RED << form2 << OFF;
	
	return (0);
}