/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:55:23 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/26 13:24:53 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "../Bureaucrat.hpp"
#include "../Form.hpp"

TEST_CASE("Copy constructor")
{
    Form a("haris", 10, 10);
    Form b(a);
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy assingment")
{
    Form a("haris", 10, 10);
    Form b = a;
    CHECK(a.get_grade_exec() == b.get_grade_exec());
    CHECK(a.get_grade_sign() == b.get_grade_sign());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Low GRADE")
{
    for(int i = 151; i < 2000; i+= 100)
    {
        CHECK_THROWS_AS(
            Form("haris", i, i),
            Form::GradeTooLowException
        );
    }
    
    
    CHECK_THROWS_AS(
        Form("haris", 150, 151),
        Form::GradeTooLowException
    );
    
    CHECK_THROWS_AS(
        Form("haris", 151, 150),
        Form::GradeTooLowException
    );
    
    CHECK_THROWS_AS(
        Form("haris", 151, 151),
        Form::GradeTooLowException
    );
    
}

TEST_CASE("High GRADE")
{
    for (int i = 0; i > -2000; i-=100)
    {
        CHECK_THROWS_AS(
        Form("haris", i, i),
        Form::GradeTooHighException
        );
    }
    
    CHECK_THROWS_AS(
        Form("haris", 0, 10),
        Form::GradeTooHighException
    );

    CHECK_THROWS_AS(
        Form("haris", 10, 0),
        Form::GradeTooHighException
    );

    CHECK_THROWS_AS(
        Form("haris", 0, 0),
        Form::GradeTooHighException
    );
}

TEST_CASE("Default constructor input")
{
    Form a;
    CHECK(a.get_name() == "NoName");
    CHECK(a.get_grade_sign() == 150);
    CHECK(a.get_grade_exec() == 150);
    CHECK(a.get_is_signed() == false);
}

TEST_CASE("Signatures1")
{ 
    Bureaucrat  a;
    Form        form_a;
    
    std::ostringstream capture;
    std::streambuf *old_b;
    
    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_a);
    std::cout.rdbuf(old_b);
    
    CHECK (capture.str() == "bureaucrat NoName signed form NoName\n");
}

TEST_CASE("Signatures2")
{ 
    Bureaucrat  a("haris", 150);
    Form        form_a("form_a", 150, 150);
    Form        form_b("form_b", 149, 150);
    Form        form_c("form_c", 150, 149);
    Form        form_d("form_d", 149, 149);
    
    std::ostringstream capture;
    std::ostringstream correct;
    std::streambuf *old_b;
    
    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_a);
    std::cout.rdbuf(old_b);
    correct << "bureaucrat " << a.get_name() << " signed form " << form_a.get_name() << "\n";
    CHECK (capture.str() == correct.str());
    CHECK (form_a.get_is_signed() == true);
    capture.str("");
    correct.str("");
    

    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_c);
    std::cout.rdbuf(old_b);
    correct << "bureaucrat " << a.get_name() << " signed form " << form_c.get_name() << "\n";;
    CHECK (capture.str() == correct.str());
    CHECK (form_c.get_is_signed() == true);
    capture.str("");
    correct.str("");
    
    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_b);
    std::cout.rdbuf(old_b);
    correct << "bureaucrat " << a.get_name() << " couldn't sign the form "\
    << form_b.get_name() << " because of Grade too Low\n";
    CHECK (capture.str() == correct.str());
    CHECK (form_b.get_is_signed() == false);
    capture.str("");
    correct.str("");
    
    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_d);
    std::cout.rdbuf(old_b);
    correct << "bureaucrat " << a.get_name() << " couldn't sign the form "\
    << form_d.get_name() << " because of Grade too Low\n";
    CHECK (capture.str() == correct.str());
    CHECK (form_d.get_is_signed() == false);
    capture.str("");
    correct.str("");

    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_a);
    std::cout.rdbuf(old_b);
    correct << "bureaucrat " << a.get_name() << " signed form " << form_a.get_name() << "\n";
    CHECK (capture.str() == correct.str());
    CHECK (form_a.get_is_signed() == true);
    capture.str("");
    correct.str("");

    old_b = std::cout.rdbuf(capture.rdbuf());
    a.sign_form(form_c);
    std::cout.rdbuf(old_b);
    correct << "bureaucrat " << a.get_name() << " signed form " << form_c.get_name() << "\n";
    CHECK (capture.str() == correct.str());
    CHECK (form_c.get_is_signed() == true);
    capture.str("");
    correct.str("");
}