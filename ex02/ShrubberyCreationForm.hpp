/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 19:53:32 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/27 16:27:18 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
    
        ShrubberyCreationForm(std::string target);
    
        void be_signed(Bureaucrat person) override;
        void execute(Bureaucrat person) const override;
        
        //Exception classes
        class GradeTooHighException: std::exception{
            public:
                const char *what() const noexcept override;
        };
        
         class GradeTooLowException: std::exception{
            public:
                const char *what() const noexcept override;
        };
};

std::ostream &operator<<(std::ostream &file, const ShrubberyCreationForm &form);