/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <forsili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:26:55 by forsili           #+#    #+#             */
/*   Updated: 2021/05/07 15:02:34 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(copy.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	this->setTarget(copy.getTarget());
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	output;
	
	executor.executeForm(*this);
	if (executor.getGrade() > this->getRequiredExec())
		throw Form::GradeToLowException();

	output.open(this->getTarget() + "_shruberry", std::ofstream::out | std::ofstream::trunc);
	if (!output.is_open())
	{
		std::cout << "Can't open the file" << std::endl;
		return ;
	}
	output << "          1          " << std::endl;
    output << "         / \\         " << std::endl;
    output << "        /   \\        " << std::endl;
    output << "       /     \\       " << std::endl;
    output << "      2       3      " << std::endl;
    output << "     / \\     / \\     " << std::endl;
    output << "    4   5   6   7    " << std::endl;
    output << "   /   / \\     / \\   " << std::endl;
    output << "  8   9   1   2   3  " << std::endl;
    output << "     /               " << std::endl;
    output << "    4                " << std::endl;
    output.close();
}