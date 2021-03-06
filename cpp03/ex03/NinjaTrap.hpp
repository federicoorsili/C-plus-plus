/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:02:42 by forsili           #+#    #+#             */
/*   Updated: 2021/04/28 22:45:34 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{

	public:

		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap &copy);
		~NinjaTrap(void);
		NinjaTrap& operator = (NinjaTrap &copy); //aggiungi
		
		void	ninjaShoebox(ClapTrap &target);
		void	ninjaShoebox(FragTrap &target);
		void	ninjaShoebox(NinjaTrap &target);
		void	ninjaShoebox(ScavTrap &target);

};

