/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:14:13 by root              #+#    #+#             */
/*   Updated: 2025/09/23 12:28:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* helper creators (C-style function pointers, safe for C++98) */
static AForm* createRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
static AForm* createShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
static AForm* createPresidential(const std::string &target) { return new PresidentialPardonForm(target); }

Intern::Intern(void) {}
Intern::Intern(Intern const &copy) { *this = copy; }
Intern::~Intern(void) {}

Intern const	&Intern::operator=(Intern const &copy)
{
    (void)copy;
    return (*this);
}

/* Make a form without using STL containers (module constraints) */
AForm* Intern::makeForm(std::string const& formName, std::string const& target) {
    const std::string names[3] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };
    AForm* (*creators[3])(std::string const&) = {
        &createRobotomy,
        &createShrubbery,
        &createPresidential
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            AForm* form = creators[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create form of type: " << formName << std::endl;
    return NULL;
}

std::ostream	&operator<<(std::ostream &str, Intern const &intern)
{
    (void)intern;
    return (str << "Intern");
}