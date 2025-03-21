/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:39:44 by root              #+#    #+#             */
/*   Updated: 2025/03/21 13:09:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("John", 150);
    Form       *form = new Form("Some Form", 50, 100);

    std::cout << "START: " << *bureaucrat << std::endl;

    try
    {
        form->beSigned(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "AFTER SIGNING: " <<
        " Bureaucrat: " << *bureaucrat << std::endl <<
        " Form: " << *form << std::endl;
    try
    {
        bureaucrat->incrementGrade();
        form->beSigned(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "AFTER SIGNING: " <<
        " Bureaucrat: " << *bureaucrat << std::endl <<
        " Form: " << *form << std::endl;
    
    delete bureaucrat;
    Bureaucrat  *bureaucrat2 = new Bureaucrat("John Wick", 4);
    try 
    {
        bureaucrat2->incrementGrade();
        form->beSigned(*bureaucrat2);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "AFTER SIGNING: " <<
        " Bureaucrat: " << *bureaucrat2 << std::endl <<
        " Form: " << *form << std::endl;

    delete bureaucrat2;
    delete form;

    return 0;
}