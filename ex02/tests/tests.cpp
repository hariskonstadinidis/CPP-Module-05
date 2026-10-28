/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:55:23 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/28 12:20:30 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "../Bureaucrat.hpp"
#include "../AForm.hpp"
#include "../PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../ShrubberyCreationForm.hpp"

TEST_CASE("Copy constructor")
{
    PresidentialPardonForm a("haris");
    PresidentialPardonForm b(a);
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy assingment")
{
    PresidentialPardonForm a("haris");
    PresidentialPardonForm b = a;
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy constructor")
{
    RobotomyRequestForm a("haris");
    RobotomyRequestForm b(a);
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy assingment")
{
    RobotomyRequestForm a("haris");
    RobotomyRequestForm b = a;
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy constructor")
{
    ShrubberyCreationForm a("haris");
    ShrubberyCreationForm b(a);
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy assingment")
{
    ShrubberyCreationForm a("haris");
    ShrubberyCreationForm  b = a;
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Low GRADE")
{
    Bureaucrat a("haris", 150);
    ShrubberyCreationForm form("haris");
    for(a.get_grade(); a.get_grade() > form.get_grade_sign(); a++)
    {
        CHECK_THROWS_AS(
            form.be_signed(a),
            AForm::GradeTooLowException
        );
        CHECK(form.get_is_signed() == false);
    }
}

TEST_CASE("Low GRADE")
{
    Bureaucrat a("haris", 150);
    RobotomyRequestForm form("haris");
    for(a.get_grade(); a.get_grade() > form.get_grade_sign(); a++)
    {
        CHECK_THROWS_AS(
            form.be_signed(a),
            AForm::GradeTooLowException
        );
        CHECK(form.get_is_signed() == false);
    }
}

TEST_CASE("Low GRADE")
{
    Bureaucrat a("haris", 150);
    PresidentialPardonForm form("haris");
    for(a.get_grade(); a.get_grade() > form.get_grade_sign(); a++)
    {
        CHECK_THROWS_AS(
            form.be_signed(a),
            AForm::GradeTooLowException
        );
        CHECK(form.get_is_signed() == false);
    }
}

TEST_CASE("exec and sign")
{
    PresidentialPardonForm f1("haris");
    ShrubberyCreationForm f2("haris");
    RobotomyRequestForm f3("haris");

    CHECK_THROWS_AS(
        PresidentialPardonForm a,
        std::out_of_range
    );

    CHECK_THROWS_AS(
        RobotomyRequestForm a,
        std::out_of_range
    );

    CHECK_THROWS_AS(
        ShrubberyCreationForm a,
        std::out_of_range
    );

    CHECK_THROWS_AS(
        Bureaucrat a("haris", 1);
        f1.execute(a),
        std::out_of_range
    );
    
    CHECK_THROWS_AS(
        Bureaucrat a("haris", 1);
        f2.execute(a),
        std::out_of_range
    );
    
    CHECK_THROWS_AS(
        Bureaucrat a("haris", 1);
        f3.execute(a),
        std::out_of_range
    );
}

TEST_CASE("Constructor input")
{
    PresidentialPardonForm a("target");
    CHECK(a.get_name() == "PresidentialPardonForm");
    CHECK(a.get_grade_sign() == 25);
    CHECK(a.get_grade_exec() == 5);
    CHECK(a.get_is_signed() == false);

    RobotomyRequestForm b("target");
    CHECK(b.get_name() == "RobotomyRequestForm");
    CHECK(b.get_grade_sign() == 72);
    CHECK(b.get_grade_exec() == 45);
    CHECK(b.get_is_signed() == false);

    ShrubberyCreationForm c("target");
    CHECK(c.get_name() == "ShrubberyCreationForm");
    CHECK(c.get_grade_sign() == 145);
    CHECK(c.get_grade_exec() == 137);
    CHECK(c.get_is_signed() == false);
}

TEST_CASE("sign and execution success")
{
    Bureaucrat a("haris", 1);
    ShrubberyCreationForm f1("haris");
    PresidentialPardonForm f2("haris");
    RobotomyRequestForm f3("haris");

    CHECK(f1.get_is_signed() == false);
    a.sign_form(f1);
    CHECK(f1.get_is_signed() == true);

    CHECK(f2.get_is_signed() == false);
    a.sign_form(f2);
    CHECK(f2.get_is_signed() == true);

    CHECK(f3.get_is_signed() == false);
    a.sign_form(f3);
    CHECK(f3.get_is_signed() == true);
}