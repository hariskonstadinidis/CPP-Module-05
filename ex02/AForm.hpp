/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:26:02 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/27 16:26:12 by hariskon         ###   ########.fr       */
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
    
        virtual void    be_signed(Bureaucrat person) = 0;
        virtual void    execute(Bureaucrat person) const;
        
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