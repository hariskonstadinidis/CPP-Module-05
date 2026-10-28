/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:21:57 by hkonstan          #+#    #+#             */
/*   Updated: 2026/10/27 16:26:31 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
    
        RobotomyRequestForm(std::string target);
    
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

std::ostream &operator<<(std::ostream &file, const RobotomyRequestForm &form);