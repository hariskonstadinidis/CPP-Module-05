/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:26:02 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 14:19:55 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool              is_signed;
        const int         grade_sign;
        const int         grade_exec;
        
    public:
        Form();
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();
    
        Form(std::string name, int grade_sign, int grade_exec);
    
        void be_signed(Bureaucrat person);

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

std::ostream &operator<<(std::ostream &file, const Form &form);