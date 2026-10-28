/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:25:13 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/27 16:23:53 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm{
    private:
        std::string target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
    
        PresidentialPardonForm(std::string name);
    
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

std::ostream &operator<<(std::ostream &file, const PresidentialPardonForm &form);