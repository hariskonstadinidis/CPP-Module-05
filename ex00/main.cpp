/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:55:28 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/14 14:54:07 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("haris", 145);
        Bureaucrat a(b);
        Bureaucrat d = a;
        Bureaucrat c("nikos", 150);
        std::cout << a << "\n";
        std::cout << a << "\n";
        std::cout << b << "\n";
        std::cout << c++ << "\n";
        std::cout << c << "\n";
        std::cout << d << "\n";
    }
    
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "grade too high\n";
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "grade too low\n";
    }
}