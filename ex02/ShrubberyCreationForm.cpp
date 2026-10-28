/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:53:35 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/27 16:38:37 by hariskon         ###   ########.fr       */
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

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):\
AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

void ShrubberyCreationForm::be_signed(Bureaucrat person){
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

void ShrubberyCreationForm::execute(Bureaucrat person) const{
     if (person.get_grade() <= this->grade_sign)
    {
        AForm::execute(person);
        std::string filename = target + "_shrubbery";
	    std::ofstream file(filename);
	    if (!file.is_open())
		    throw std::out_of_range("file failed to open\n");
        file << "  /\\\n /  \\\n  ||\n";
    }
    else
        throw std::out_of_range("Not signed\n");
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::ostream &operator<<(std::ostream &file, const ShrubberyCreationForm &form){
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}