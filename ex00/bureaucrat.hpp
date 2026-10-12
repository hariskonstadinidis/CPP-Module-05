/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskonstadinidis@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:22:35 by hariskon          #+#    #+#             */
/*   Updated: 2026/10/12 16:54:28 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
};