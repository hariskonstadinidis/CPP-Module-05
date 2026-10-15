/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:20:36 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/15 21:12:02 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(), name("NoName"), is_signed(false), grade_sign(72), grade_exec(45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): name(other.name), is_signed(other.is_signed),\
    grade_sign(other.grade_sign), grade_exec(other.grade_exec)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name): name(name), is_signed(false)\
    ,grade_sign(72), grade_exec(45)
{
    if (grade_exec < 1 || grade_sign < 1)
        throw AForm::GradeTooHighException();
    else if (grade_exec > 150 || grade_sign >150)
        throw AForm::GradeTooLowException();
}

void RobotomyRequestForm::be_signed(Bureaucrat person){
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

RobotomyRequestForm::~RobotomyRequestForm(){}

const char *RobotomyRequestForm::GradeTooHighException::what() const noexcept{
    return ("Grade too High\n");
}

const char *RobotomyRequestForm::GradeTooLowException::what() const noexcept{
    return ("Grade too Low\n");
}

std::ostream &operator<<(std::ostream &file, const RobotomyRequestForm &form){
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}