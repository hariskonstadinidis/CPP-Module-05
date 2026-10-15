/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:55:28 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 18:54:50 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("haris", 145);
        Bureaucrat a(Bureaucrat("john", 1));
        Bureaucrat d = a;
        Bureaucrat c("nikos", 150);
        
        Form fa("form_10", 10 , 10);
        Form fb("form_150", 150 , 150);
        
        std::cout << fa.get_is_signed() << "\n";
        std::cout << fa.get_is_signed() << "\n";
        
        a.sign_form(fa);
        a.sign_form(fb);
        
        std::cout << fa.get_is_signed() << "\n";
        std::cout << fb.get_is_signed() << "\n";
        
        Form f_wrong("form_wrong", 151, 1);
    }
    
    catch(Form::GradeTooHighException &e)
    {
        std::cout << e.what() << "\n";
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << "\n";
    }
}