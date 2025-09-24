/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:28:24 by root              #+#    #+#             */
/*   Updated: 2025/09/24 11:00:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        std::string const	_name;
        int					_grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &src);

        ~Bureaucrat();
        
		Bureaucrat &operator=(Bureaucrat const &src);
        
        std::string getName() const;
        int getGrade() const;

        void executeForm(AForm const &form) const;
        void signForm(AForm &form);

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw();
        };
    };
std::ostream&	operator<<(std::ostream& os, Bureaucrat const &bureaucrat);

#endif