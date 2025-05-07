/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:59:12 by root              #+#    #+#             */
/*   Updated: 2025/05/07 21:03:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return *this;
}

void ShrubberyCreationForm::beExecuted(Bureaucrat const &executor) const
{
    (void)executor;
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
        throw std::ios_base::failure("Failed to open file");
    
    file << "       _-_" << std::endl;
    file << "    /\\   /\\" << std::endl;
    file << "   ( o )( o )" << std::endl;
    file << "  /  ==   ==  \\" << std::endl;
    file << " /____________\\ " << std::endl;
    file << " ~~~~~~~~~~~~~~~" << std::endl;
    file.close();
}

