/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:26:05 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/14 17:06:50 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

Form::Form():name("No_Name"), is_signed(false), grade_sign(150), grade_exec(150){}

Form::Form(const Form &other): name(other.name), is_signed(other.is_signed),\
    grade_sign(other.grade_sign), grade_exec(other.grade_exec)
{
    *this = other;
}

Form &Form::operator=(const Form &other){
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::Form(std::string name, int grade_sign, int grade_exec): name(name), is_signed(false),\
    grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_exec < 1 || grade_sign < 1)
        throw Form::GradeTooHighException();
    else if (grade_exec > 150 || grade_sign >150)
        throw Form::GradeTooLowException();
}

void Form::be_signed(Bureaucrat person){
    if (person.get_grade() <= this->grade_sign)
        is_signed = true;
    else
        throw Form::GradeTooLowException();
}

Form::~Form(){}

std::string   Form::get_name() const{
    return this->name;
}

bool    Form::get_is_signed(){
    return this->is_signed;
}

int   Form::get_grade_sign() const{
    return this->grade_sign;
}

int   Form::get_grade_exec() const{
    return this->grade_exec;
}

const char *Form::GradeTooHighException::what() const noexcept{
    return ("Grade too high\n");
}

const char *Form::GradeTooLowException::what() const noexcept{
    return ("Grade too low\n");
}

std::ostream &operator<<(std::ostream &file, const Form &form){
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}