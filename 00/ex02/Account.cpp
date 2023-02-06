/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:29:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/06 18:28:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

//Static class members / variables
int	Account::_nbAccounts;
int	Account::_totalAmount;
int Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

//Default constructor for class object.
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	std::cout << "created";
	std::cout << std::endl;
}

//Default destructor for class object.
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
}

//Function gets the number of accounts made from the account class.
int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

//Function gets the total amount in the account class.
int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

//Function gets the number of deposits in the account class.
int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

//Function gets the number of withdrawals in the account class.
int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

//Function displays the information in the account class.
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}

//Function makes a deposit into an account object.
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

//Function makes a withdrawal from an account object. If possible.
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused";
		std::cout << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return (true);
}

//Function checks the amount stored in an account object.
int	Account::checkAmount() const
{
	return (this->_amount);
}

//Function displays the status of an account object.
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

//Function creates a timestamp.
void	Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	std::tm *	time_struct = localtime(&now);
	
	std::cout << "[" << 1900 + time_struct->tm_year;
	if (time_struct->tm_mon < 10)
		std::cout << 0;
	std::cout << 1 + time_struct->tm_mon;
	if (time_struct->tm_mday < 10)
		std::cout << 0;
	std::cout << time_struct->tm_mday << "_";
	if (time_struct->tm_hour < 10)
		std::cout << 0;
	std::cout << time_struct->tm_hour;
	if (time_struct->tm_min < 10)
		std::cout << 0;
	std::cout << time_struct->tm_min;
	if (time_struct->tm_sec < 10)
		std::cout << 0;
	std::cout << time_struct->tm_sec;
	std::cout << "] ";
}
