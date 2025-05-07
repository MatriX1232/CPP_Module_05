/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:14:52 by aperez-b          #+#    #+#             */
/*   Updated: 2025/05/07 21:58:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructors & Destructors */
RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45), _target("null") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm::AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

/* Basic Operators */
RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

/* Main Member Functions */
void	RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	int	success;

	/* Set Seed */
	srand((unsigned) time(NULL));
	success = rand() % 2;
	(void)bureaucrat;
	if (success)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
