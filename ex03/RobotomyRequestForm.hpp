/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:14:22 by aperez-b          #+#    #+#             */
/*   Updated: 2025/09/23 12:18:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		/* Constructors & Destructors */
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);

		/* Basic Operators */
		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &copy);

		/* Main Member Functions */
		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);
