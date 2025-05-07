/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:06:23 by root              #+#    #+#             */
/*   Updated: 2025/05/07 21:05:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}

void RobotomyRequestForm::beExecuted(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    srand(time(NULL));
    int success = rand() % 2;
    if (success)
        std::cout << "Drrrrrrr... " << _target << " has been robotomized successfully 50% of the time!" << std::endl;
    else
        std::cout << "Drrrrrrr... " << _target << " robotomy failed!" << std::endl;    
}
