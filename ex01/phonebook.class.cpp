/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:34:36 by jadithya          #+#    #+#             */
/*   Updated: 2023/10/16 16:45:05 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void) {
	this->NumContacts = 0;
	std::cout<<"Starting Phonebook"<<std::endl<<std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout<<"Closing Phonebook"<<std::endl<<std::endl;
}

void	PhoneBook::AddContact() {
	std::cout << "\033c";
	std::cout << "First Name: ";
	while (this->List[NumContacts].FirstName.length() == 0)
		std::getline(std::cin, this->List[NumContacts].FirstName, '\n');
	std::cout << "Last Name: ";
	while (this->List[NumContacts].LastName.length() == 0)
		std::getline(std::cin, this->List[NumContacts].LastName, '\n');
	std::cout << "Nickname: ";
	while (this->List[NumContacts].Nickname.length() == 0)
		std::getline(std::cin, this->List[NumContacts].Nickname, '\n');
	std::cout << "Phone Number: ";
	while (this->List[NumContacts].PhoneNumber.length() == 0)
		std::getline(std::cin, this->List[NumContacts].PhoneNumber, '\n');
	std::cout << "Dark Secret: ";
	while (this->List[NumContacts].DarkSecret.length() == 0)
		std::getline(std::cin, this->List[NumContacts].DarkSecret, '\n');
	NumContacts++;
	std::cout << "\033c";
}

void	PhoneBook::PrintContacts() {
	std::cout << "\033c";
	std::cout << std::setw(10) << "INDEX"
		<< "|" << std::setw(10) << "FIRST NAME"
		<< "|" << std::setw(10) << "LAST NAME"
		<< "|" << std::setw(10) << "NICKNAME"
		<< std::endl;
	for (int i = 0; i < this->NumContacts; i++) {
		std::cout << std::setw(10) << (i + 1)
			<< "|" << std::setw(10) << this->List[i].FirstName.substr(0, 10)
			<< "|" << std::setw(10) << this->List[i].LastName.substr(0, 10)
			<< "|" << std::setw(10) << this->List[i].Nickname.substr(0, 10)
			<< std::endl;
	}
}

void	PhoneBook::SearchContact() {
	std::string	StrIndex;
	int			SearchIndex;

	this->PrintContacts();
	std::cout << "Enter index of the contact you would like to see (0 to go back): ";
	std::cin >> StrIndex;
	SearchIndex = StrIndex[0] - '0';
	while (StrIndex.length() != 1 || !isdigit(StrIndex[0])
		|| SearchIndex < 0 || SearchIndex > this->NumContacts) {
		std::cout << "Incorrect input. Try again: ";
		std::cin >> StrIndex;
		SearchIndex = StrIndex[0] - '0';
	}
	if (SearchIndex == 0)
		return ;
	std::cout << std::endl;
	std::cout << "First Name: " << this->List[SearchIndex - 1].FirstName
		<< std::endl << "Last Name: " << this->List[SearchIndex - 1].LastName
		<< std::endl << "Nickname: " << this->List[SearchIndex - 1].Nickname
		<< std::endl << "Phone Number: " << this->List[SearchIndex - 1].PhoneNumber
		<< std::endl << "Dark Secret: " << this->List[SearchIndex - 1].DarkSecret
		<< std::endl << std::endl;
}

int	main(void) {
	PhoneBook	pb;
	std::string	option;
	bool		run;

	run = true;
	std::cout << "\033c";
	option = "1";
	while (run) {
		if (option != "1" && option != "2" && option != "3")
			std::cout << "\033cIncorrect input. Try again." << std::endl;
		std::cout << "--------PHONEBOOK--------" << std::endl << std::endl;
		std::cout << "Menu: " << std::endl
			<< "1. Add a contact" << std::endl
			<< "2. Search for a contact" << std::endl
			<< "3. Exit the program" << std::endl << std::endl
			<< "Enter option: ";
		std::cin >> option;
		std::cout << std::endl;
		if (option == "1")
			pb.AddContact();
		else if (option == "2")
			pb.SearchContact();
		else if (option == "3")
			run = false;
	}
}