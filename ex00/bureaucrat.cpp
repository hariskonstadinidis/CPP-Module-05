/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:21:22 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/12 17:10:37 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Noname"){}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name){    
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat  &other){
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

//Name Constructor
Bureaucrat::Bureaucrat(std::string name, int grade): name(name){
    try
    {
        this->grade = grade;
        if (grade < 1)
            throw 505;
        else if (grade > 150)
            throw 506;
    }
    catch (int e)
    {
        if (e == 505)
            std::cout << "Bureaucrat::GradeTooHighException";
        else if(e == 506)
            std::cout << "Bureaucrat::GradeTooLowException";
    }
}