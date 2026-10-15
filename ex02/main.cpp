/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:55:28 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 21:22:13 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat b("haris", 145);
        Bureaucrat a(Bureaucrat("john", 1));
        Bureaucrat d = a;
        Bureaucrat c("nikos", 150);
        
        ShrubberyCreationForm s_fa("home");
        ShrubberyCreationForm r_fb("home");
        
        std::cout << s_fa.get_is_signed() << "\n";
        std::cout << r_fb.get_is_signed() << "\n";
        
        a.sign_form(s_fa);
        a.sign_form(r_fb);
        c.sign_form(s_fa);
        
        std::cout << s_fa.get_is_signed() << "\n";
        std::cout << r_fb.get_is_signed() << "\n";
    }
    
    catch(AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << "\n";
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << "\n";
    }
    catch(int &e)
    {
        std::cout << "open failed\n";
    }
}