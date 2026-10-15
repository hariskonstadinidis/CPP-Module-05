/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:21:22 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 15:24:44 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("NoName"), grade(150){
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name){    
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat  &other){
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){};

//Name Constructor
Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat Bureaucrat::operator++(int){
    Bureaucrat temp = *this;
    this->grade--;
    if (this->grade < 1)
        throw GradeTooHighException();
    return temp;
}

Bureaucrat Bureaucrat::operator--(int){
    Bureaucrat temp = *this;
    this->grade++;
    if (this->grade > 150)
        throw GradeTooLowException();
    return temp;
}

int Bureaucrat::get_grade() const{
    return this->grade;
}

std::string Bureaucrat::get_name() const{
    return this->name;
}
const char *Bureaucrat::GradeTooHighException::what() const noexcept{
    return ("Grade too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept{
    return ("Grade too high\n");
}

std::ostream &operator <<(std::ostream &file, const Bureaucrat &bureaucrat){
    file << bureaucrat.get_name() << ", Bureaucrat grade " << bureaucrat.get_grade();
    return file;
}