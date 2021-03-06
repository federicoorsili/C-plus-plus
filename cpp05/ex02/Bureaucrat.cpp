/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <forsili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:41:38 by forsili           #+#    #+#             */
/*   Updated: 2021/05/07 15:07:50 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : name(name)
{
	this->grade = grade;
	if (this->grade > 150)
		throw Bureaucrat::GradeToLowException();
	else if (this->grade < 1)
		throw Bureaucrat::GradeToHightException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& copy)
{
	this->grade = copy.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int			Bureaucrat::getGrade() const
{
	return grade;
}

void		Bureaucrat::upGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeToHightException();
	else
		grade -= 1;
}

void		Bureaucrat::downGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeToLowException();
	else
		grade += 1;
}

void		Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	if (this->grade <= form.getRequiredGrade())
		std::cout << this->name << " signs " << form.getName() << std::endl;
	else
		std::cout << this->name << " cannot sign " << form.getName() << std::endl;

}

void		Bureaucrat::executeForm(Form const& form) const
{
	if (this->grade <= form.getRequiredExec())
		std::cout << this->name << " executes " << form.getName() << std::endl;
	else
		std::cout << this->name << " cannot execute " << form.getName() << std::endl;
}

const char*	Bureaucrat::GradeToLowException::what() const throw()
{
	return ("Exception: To low grade");
}

const char*	Bureaucrat::GradeToHightException::what() const throw()
{
	return ("Exception: To Hight grade");
}

std::ostream&	operator<<(std::ostream& out, Bureaucrat const &b)
{
	out << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">" << std::endl;
	return out; 
}