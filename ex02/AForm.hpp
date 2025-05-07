/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:38:00 by aperez-b          #+#    #+#             */
/*   Updated: 2025/05/07 21:56:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	public:
		/* Constructors & Destructors */
		AForm(void);
		AForm(std::string const &name, int const &signGrade, int const &execGrade);
		AForm(AForm const &copy);
		virtual ~AForm(void);

		/* Basic Operators */
		AForm const	&operator=(AForm const &copy);

		/* Getters & Setters */
		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getSignGrade(void) const;
		int const			&getExecGrade(void) const;

		/* Main Member Functions */
		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;

		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);
