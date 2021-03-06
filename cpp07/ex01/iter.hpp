/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:30:24 by forsili           #+#    #+#             */
/*   Updated: 2021/05/10 23:46:59 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>
void   sum(T &arg)
{
    arg += arg;
    std::cout << arg << "\n";
}

template <typename T, typename V>
void    iter(T *address, V lenght, void (*func)(T &))
{
    for (V i = 0; i < lenght; i++)
    {
        func(address[i]);
    }
}


