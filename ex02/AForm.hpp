/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:26:02 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 21:06:59 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class AForm{
    protected:
        const std::string name;
        bool              is_signed;
        const int         grade_sign;
        const int         grade_exec;
        
    public:
        AForm();
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        ~AForm();
    
        AForm(std::string name, int grade_sign, int grade_exec);
    
        virtual void be_signed(Bureaucrat person) = 0;

        //Getters
        std::string   get_name() const;
        bool          get_is_signed();
        int           get_grade_sign() const;
        int           get_grade_exec() const;
        
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

std::ostream &operator<<(std::ostream &file, const AForm &form);