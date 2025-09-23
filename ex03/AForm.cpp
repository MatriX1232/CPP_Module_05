/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:38:05 by aperez-b          #+#    #+#             */
/*   Updated: 2022/09/30 12:54:43 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

/* Constructors & Destructors */
AForm::AForm(void): _name("default"), _isSigned(0), _signGrade(30), _execGrade(60) {}

AForm::AForm(std::string const &name, int const &signGrade, int const &execGrade): _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_signGrade > 150)
		throw (AForm::GradeTooLowException());
	if (this->_execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
}

AForm::~AForm(void) {}

/* Basic Operators */
AForm const	&AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

/* Getters & Setters */
std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

int const	&AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int const	&AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool const	&AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

/* Main Member Functions */
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_isSigned = 1;
		std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
	}
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_execGrade)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}

/* Exceptions */
char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

char const	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm not signed");
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
