/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:58:23 by root              #+#    #+#             */
/*   Updated: 2025/05/07 21:03:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();
    
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    
        // Renamed method to override AForm::beExecuted
        void beExecuted(Bureaucrat const &executor) const;
    
    private:
        std::string _target;
};