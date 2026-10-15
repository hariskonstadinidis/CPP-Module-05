/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:26:05 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 21:06:48 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

AForm::AForm():name("NoName"), is_signed(false), grade_sign(150), grade_exec(150){}

AForm::AForm(const AForm &other): name(other.name), is_signed(other.is_signed),\
    grade_sign(other.grade_sign), grade_exec(other.grade_exec)
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other){
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec): name(name), is_signed(false),\
    grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_exec < 1 || grade_sign < 1)
        throw GradeTooHighException();
    else if (grade_exec > 150 || grade_sign >150)
        throw GradeTooLowException();
}

void AForm::be_signed(Bureaucrat person){
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

AForm::~AForm(){}

std::string   AForm::get_name() const{
    return this->name;
}

bool    AForm::get_is_signed(){
    return this->is_signed;
}

int   AForm::get_grade_sign() const{
    return this->grade_sign;
}

int   AForm::get_grade_exec() const{
    return this->grade_exec;
}

const char *AForm::GradeTooHighException::what() const noexcept{
    return ("Grade too High\n");
}

const char *AForm::GradeTooLowException::what() const noexcept{
    return ("Grade too Low\n");
}

std::ostream &operator<<(std::ostream &file, const AForm &form){
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}