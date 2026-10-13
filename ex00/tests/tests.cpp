/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:55:23 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/13 17:10:05 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Bureaucrat.hpp"

TEST_CASE("Copy constructor")
{
    Bureaucrat a("haris", 10);
    Bureaucrat b(a);
    CHECK(a.get_grade() == b.get_grade());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Copy assingment")
{
    Bureaucrat a("haris", 10);
    Bureaucrat b = a;
    CHECK(a.get_grade() == b.get_grade());
    CHECK(a.get_name() == b.get_name());
    CHECK(&a != &b);
}

TEST_CASE("Low GRADE")
{
    CHECK_THROWS_AS(
        Bureaucrat a("haris", 151),
        Bureaucrat::GradeTooLowException
    );
}

TEST_CASE("High GRADE")
{
    CHECK_THROWS_AS(
        Bureaucrat a("haris", 0),
        Bureaucrat::GradeTooHighException
    );
    Bureaucrat a("haris" ,1);
    CHECK_THROWS_AS(
        a++,
        Bureaucrat::GradeTooHighException
    ); 
}