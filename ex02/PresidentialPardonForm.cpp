/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:25:16 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/15 21:09:20 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
	throw std::out_of_range("no target input\n");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):\
AForm(other.name, other.grade_sign, other.grade_exec)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=\
(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name):\
AForm("PresidentialPardonForm", 25, 5)
{
	std::string filename = name + "_shrubbery";
	std::cout << filename;
}

void PresidentialPardonForm::be_signed(Bureaucrat person)
{
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::ostream &operator<<(std::ostream &file, const PresidentialPardonForm &form)
{
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}