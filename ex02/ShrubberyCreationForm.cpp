/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:53:35 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/15 21:23:29 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	throw std::out_of_range("no target input\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):\
AForm(other.name, other.grade_sign, other.grade_exec)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if (this != &other)
        this->is_signed = other.is_signed;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name):\
AForm("ShrubberyCreationForm", 25, 5)
{
    std::string filename = name + "_shrubbery";
	std::ofstream file("ASCII");
	if (!file.is_open())
		throw 1;
}

void ShrubberyCreationForm::be_signed(Bureaucrat person){
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::ostream &operator<<(std::ostream &file, const ShrubberyCreationForm &form){
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}