/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:37:22 by root              #+#    #+#             */
/*   Updated: 2025/05/07 21:55:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " cannot sign " << form.getName() << " because of: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " cannot execute " << form.getName() << " because of: " << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high to increment grade";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low to decrement grade";
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this != &src)
    {
        _grade = src._grade;
    }
    return *this;
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}