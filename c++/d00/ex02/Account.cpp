/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:10:23 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 17:17:02 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	_accountIndex = -1;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
		";amount:" << _amount << ";created" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << \
	";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << \
	";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
	";amount:" << _amount << ";deposits:" << _nbDeposits << \
	";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
		";p_amount:" << _amount - deposit << ";deposit:" << deposit << \
		";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout <<  "index:" << _accountIndex << \
		";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
	";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << \
	";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout << "[" << timeinfo->tm_year + 1900 << std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1 << std::setw(2) << std::setfill('0') << \
		timeinfo->tm_mday << "_" << std::setw(2) << std::setfill('0') << timeinfo->tm_hour << std::setw(2) << std::setfill('0') \
												<< timeinfo->tm_min << std::setw(2) << std::setfill('0') << timeinfo->tm_sec << "] ";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}