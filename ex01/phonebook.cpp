/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <forsili@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:04:55 by forsili           #+#    #+#             */
/*   Updated: 2021/04/22 14:49:46 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phone_Book.cpp"
#include <vector>

void	add_contact(Phone_Book user[8], int i)
{
	std::string input;

	std::cout << "Insert First Name" << std::endl;
	std::getline(std::cin, input);
	user[i].first_name = input;
	std::cout << "Insert Last Name" << std::endl;
	std::getline(std::cin, input);
	user[i].last_name = input;
	std::cout << "Insert Nickname" << std::endl;
	std::getline(std::cin, input);
	user[i].nickname = input;
	std::cout << "Insert Login" << std::endl;
	std::getline(std::cin, input);
	user[i].login = input;
	std::cout << "Insert Postal address" << std::endl;
	std::getline(std::cin, input);
	user[i].postal_address = input;
	std::cout << "Insert Email address" << std::endl;
	std::getline(std::cin, input);
	user[i].email_address = input;
	std::cout << "Insert Phone number" << std::endl;
	std::getline(std::cin, input);
	user[i].phone_number = input;
	std::cout << "Insert Birthdate" << std::endl;
	std::getline(std::cin, input);
	user[i].birthday_date = input;
	std::cout << "Insert Favorite meal" << std::endl;
	std::getline(std::cin, input);
	user[i].favorite_meal = input;
	std::cout << "Insert Underwear color" << std::endl;
	std::getline(std::cin, input);
	user[i].underwear_color = input;
	std::cout << "Insert Darkest secret" << std::endl;
	std::getline(std::cin, input);
	user[i].darkest_secret = input;

	std::cout << "**********************************" << std::endl;
	std::cout << "*****CONTACT ADDED CORRECTLY******" << std::endl;
	std::cout << "**********************************" << std::endl;

}

void	display_index(int k)
{
	std::string str;
	int i;

	i = 0;
	str = std::to_string(k);
	while (i < 10)
	{
		if (i < int(str.length()))
			std::cout << str[i];
		else
			std::cout << " ";
		i++;
	}
	
}

void	display_data(std::string str)
{
	int i;

	i = 0;
	while(i < 10)
	{
		if (i < int(str.length()) && i < 9)
			std::cout << str[i];
		else if (i == 9 && str.length() > 10)
			std::cout << ".";
		else if (i == 9 && str.length() == 10)
			std::cout << str[i];
		else if (i > int(str.length() - 1))
			std::cout << " ";
		i++;
	}
}

void	display_id(Phone_Book user[8], int id)
{
	std::cout << "NAME:           |" << user[id].first_name << std::endl;
	std::cout << "LAST NAME:      |" << user[id].last_name << std::endl;
	std::cout << "NICKNAME:       |" << user[id].nickname << std::endl;
	std::cout << "LOGIN:          |" << user[id].login << std::endl;
	std::cout << "POSTAL ADDRESS: |" << user[id].postal_address << std::endl;
	std::cout << "EMAIL ADDRESS:  |" << user[id].email_address << std::endl;
	std::cout << "PHONE:          |" << user[id].phone_number << std::endl;
	std::cout << "BIRTHDAY:       |" << user[id].birthday_date << std::endl;
	std::cout << "FAVOURITE MEAL: |" << user[id].favorite_meal << std::endl;
	std::cout << "UNDERWEAR COLOR:|" << user[id].underwear_color << std::endl;
	std::cout << "DARKEST SECRET: |" << user[id].darkest_secret << std::endl;
}

void	search_contact(Phone_Book user[8], int i)
{
	int k;
	std::string input;
	int			id;

	k = 0;
	std::cout << "ID        |NAME      |LAST NAME |NICKNAME  |" << std::endl;
	while (k < i)
	{
		display_index(k);
		std::cout << "|";
		display_data(user[k].first_name);
		std::cout << "|";
		display_data(user[k].last_name);
		std::cout << "|";
		display_data(user[k].nickname);
		std::cout << "|";
		std::cout << std::endl;
		k++;
	}
	std::cout << "Select an id to browse contact information:" << std::endl;
	getline(std::cin, input);
	id = stoi(input);
	if (id >= 0 && id < i)
		display_id(user, id);
	else
	{
		std::cout << "**********************************" << std::endl;
		std::cout << "***** CONTACT DOES NOT EXIST *****" << std::endl;
		std::cout << "**********************************" << std::endl;
	}
}

void    wait_signal()
{
	std::string  input;
	int		  i;
	Phone_Book user[8];

	i = 0;
	while (1)
	{
		std::cout << "Waiting for ADD, SEARCH or EXIT comand:" << std::endl;
		getline(std::cin, input);
		if (!input.compare("ADD"))
		{
			if (i == 8)
			{
				std::cout << "**********************************" << std::endl;
				std::cout << "* Max number of contact reached *" << std::endl;
				std::cout << "**********************************" << std::endl;
				continue;
			}
			add_contact(user, i);
			i++;
		}
		else if (!input.compare("SEARCH"))
			search_contact(user, i);
		else if (!input.compare("EXIT"))
			exit(0);
	}
		
}

int	 main(void)
{
	wait_signal();
		
}