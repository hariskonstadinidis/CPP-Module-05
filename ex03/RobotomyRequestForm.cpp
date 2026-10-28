/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:20:36 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/27 17:44:33 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45){
    throw std::out_of_range("no target input\n");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):\
AForm(other.name, other.grade_sign, other.grade_exec)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other)
    {
        this->is_signed = other.is_signed;
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::be_signed(Bureaucrat person){
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat person) const{
     if (person.get_grade() <= this->grade_sign)
    {
        AForm::execute(person);
        std::cout << "Drrrrrrrrrrrrrr\n";
        std::random_device rd;
        std::uniform_int_distribution<int> range(0, 1);
        int number = range(rd);
        if (number)
            std::cout << this->target << " has been robotomized\n";
        else
            std::cout << "Robotomy failed\n";
    }
    else
        throw std::out_of_range("Not signed\n");
}

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