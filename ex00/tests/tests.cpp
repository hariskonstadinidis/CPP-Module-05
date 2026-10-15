/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:55:23 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 14:21:00 by hkonstan         ###   ########.fr       */
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
    for(int i = 151; i < 2000; i+= 100)
    {
        CHECK_THROWS_AS(
            Bureaucrat("haris", i),
            Bureaucrat::GradeTooLowException
        );
    }
    
    Bureaucrat a("haris", 1);
    for(int i = 1; i < 150 ; i++)
    {
        CHECK(a.get_grade() == i);
        a--;
    }
    
    CHECK_THROWS_AS(
        a--,
        Bureaucrat::GradeTooLowException
    );
}

TEST_CASE("High GRADE")
{
    for (int i = 0; i > -2000; i-=100)
    {
        CHECK_THROWS_AS(
        Bureaucrat("haris", i),
        Bureaucrat::GradeTooHighException
        );
    }
    
    Bureaucrat a("haris", 150);
    for(int i = 150; i > 1; i--)
    {
        CHECK(a.get_grade() == i);
        a++;
    }
    
    CHECK_THROWS_AS(
        a++,
        Bureaucrat::GradeTooHighException
    ); 
}

TEST_CASE("Default constructor input")
{
    Bureaucrat a;
    CHECK(a.get_name() == "NoName");
    CHECK(a.get_grade() == 150);
}
