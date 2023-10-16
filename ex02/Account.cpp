/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:37:36 by jadithya          #+#    #+#             */
/*   Updated: 2023/10/16 19:25:51 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <bits/types/struct_tm.h>
#include <bits/types/time_t.h>
#include <ctime>
#include <iostream>
#include <string>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
			<< ";amount:" << this->_amount
			<< ";closed"
			<< std::endl;
}

Account::~Account(void) {
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
			<< ";amount:" << this->_amount
			<< ";created"
			<< std::endl;
}


int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void) {
	struct tm	*timeinfo;
	time_t		rawtime;
	char		datetime[20];
	std::string	timestamp;

	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(datetime, 20, "%F_%X", timeinfo);
	timestamp = datetime;
	timestamp = timestamp.erase(4, 1);
	timestamp = timestamp.erase(6, 1);
	timestamp = timestamp.erase(11, 1);
	timestamp = timestamp.erase(13, 1);
	std::cout << "["
		<< timestamp
		<< "]";
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:"
		<< getNbAccounts()
		<< ";total:"
		<< getTotalAmount()
		<< ";deposits:"
		<< getNbDeposits()
		<< ";withdrawals:"
		<< getNbWithdrawals()
		<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal <= this->_amount) {
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	return (false);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}
