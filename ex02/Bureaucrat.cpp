/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:21:22 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 19:46:21 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
        throw Bureaucrat::GradeTooHighException();
    return temp;
}

Bureaucrat Bureaucrat::operator--(int){
    Bureaucrat temp = *this;
    this->grade++;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return temp;
}

int Bureaucrat::get_grade() const{
    return this->grade;
}

std::string Bureaucrat::get_name() const{
    return this->name;
}

void Bureaucrat::sign_form(AForm &form){
    try
    {
        form.be_signed(*this);
        std::cout << "bureaucrat " << this->name << " signed form " << form.get_name() << "\n";
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << "bureaucrat " << this->name << " couldn't sign the form " << form.get_name()\
        << " because of " << e.what();
    }
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept{
    return ("Grade too High\n");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept{
    return ("Grade too Low\n");
}

std::ostream &operator <<(std::ostream &file, const Bureaucrat &bureaucrat){
    file << bureaucrat.get_name() << ", Bureaucrat grade " << bureaucrat.get_grade();
    return file;
}