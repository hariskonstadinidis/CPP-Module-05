/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:25:16 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/28 12:30:36 by hariskon         ###   ########.fr       */
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
        this->target = other.name;
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):\
AForm("PresidentialPardonForm", 25, 5){
    this->target = target;
}

void PresidentialPardonForm::be_signed(Bureaucrat person)
{
    if (person.get_grade() <= this->grade_sign)
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

void PresidentialPardonForm::execute(Bureaucrat person) const{
    if (person.get_grade() <= this->grade_sign)
    {
        AForm::execute(person);
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
    }
    else
        throw std::out_of_range("Not signed\n");
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::ostream &operator<<(std::ostream &file, const PresidentialPardonForm &form)
{
    file << form.get_name() << ", Form sign grade: " << form.get_grade_sign()\
    << ", form execution grade: " << form.get_grade_exec() << "\n";
    return file;
}