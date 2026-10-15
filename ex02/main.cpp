/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:55:28 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 19:46:57 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat b("haris", 145);
        Bureaucrat a(Bureaucrat("john", 1));
        Bureaucrat d = a;
        Bureaucrat c("nikos", 150);
        
        AForm fa("form_10", 10 , 10);
        AForm fb("form_150", 150 , 150);
        
        std::cout << fa.get_is_signed() << "\n";
        std::cout << fa.get_is_signed() << "\n";
        
        a.sign_form(fa);
        a.sign_form(fb);
        
        std::cout << fa.get_is_signed() << "\n";
        std::cout << fb.get_is_signed() << "\n";
        
        AForm f_wrong("form_wrong", 151, 1);
    }
    
    catch(AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << "\n";
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << "\n";
    }
}