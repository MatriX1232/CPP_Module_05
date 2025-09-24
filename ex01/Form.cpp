/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:03:10 by root              #+#    #+#             */
/*   Updated: 2025/09/24 13:36:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const & src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return *this;
}

std::ostream&	operator<<(std::ostream& os, AForm const &form)
{
    os << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute();
    return os;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw AForm::GradeTooLowException();
        // std::cout << bureaucrat.getName() <<
        //     " cannot sign " << _name << " because their grade is too low." << std::endl;
        return ;
    }
    // std::cout << bureaucrat.getName() <<
        // " signed " << _name << std::endl;
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low!";
}
