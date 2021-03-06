/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <forsili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:31:52 by forsili           #+#    #+#             */
/*   Updated: 2021/05/10 16:44:45 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    try
    {
        ScalarConversion s(argv[1]);

        s.check();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}