/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:39:44 by root              #+#    #+#             */
/*   Updated: 2025/03/15 19:46:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("John", 150);

    std::cout << "START: " << *bureaucrat << std::endl;

    try
    {
        bureaucrat->decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *bureaucrat << std::endl;

    try
    {
        bureaucrat->incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *bureaucrat << std::endl;

    delete bureaucrat;

    return 0;
}