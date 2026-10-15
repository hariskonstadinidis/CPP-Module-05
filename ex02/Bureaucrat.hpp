/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:22:35 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/15 19:41:38 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class AForm;

class Bureaucrat{
    private:
        const std::string name;
        int               grade;
    
    public:
        Bureaucrat();
        Bureaucrat (const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        Bureaucrat(std::string name, int grade);
        
        Bureaucrat operator++(int);
        Bureaucrat operator--(int);
        
        //Getters
        int         get_grade() const;
        std::string get_name() const;
        
        void sign_form(AForm &form);
        
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

std::ostream &operator<<(std::ostream &file, const Bureaucrat &bureaucrat);