/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:14:11 by root              #+#    #+#             */
/*   Updated: 2025/09/24 11:04:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		/* Basic Operators */
		Intern const	&operator=(Intern const &copy);

		/* Main Member Functions */
		AForm	*makeForm(std::string const &formName, std::string const &target);
};
std::ostream	&operator<<(std::ostream &str, Intern const &intern);