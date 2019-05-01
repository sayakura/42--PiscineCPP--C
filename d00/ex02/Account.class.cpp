/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <qpeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:35:41 by qpeng             #+#    #+#             */
/*   Updated: 2019/04/30 22:21:53 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "Account.class.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(void) { };

Account::Account(int amnt)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += amnt;
	_amount = amnt;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
                ";amount:" << _amount << 
                ";created" <<
    std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
                ";amount:" << _amount << 
                ";closed" <<
    std::endl;
}

void	Account::_displayTimestamp( void )
{
	static time_t		t;
	static struct tm	*now;

	if (!now)
	{
		t = time(0);
		now = localtime(&t);
	}

	std::cout << 
            '[' <<
            now->tm_year + 1900 <<
            std::setw(2) <<  std::setfill('0') << now->tm_mon << 
            std::setw(2) <<  std::setfill('0') << now->tm_mday << 
            '_' << 
            std::setw(2) << std::setfill('0') << now->tm_hour << 
            std::setw(2) << std::setfill('0') << now->tm_min << 
            std::setw(2) << std::setfill('0') << now->tm_sec << 
            "] ";
    return ;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts <<
                ";total:" << _totalAmount <<
                ";deposits:" << _totalNbDeposits <<
                ";withdrawals:" << _totalNbWithdrawals <<
    std::endl;
}

void		Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
                ";amount:" << _amount << 
                ";deposits:" << _nbDeposits <<
                ";withdrawals:" << _nbWithdrawals << 
    std::endl;
}


void		Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
                ";p_amount:" << (_amount - deposit) << 
                ";deposit:" << deposit << 
                ";amount:" << _amount << 
                ";nb_deposits:" << _nbDeposits << 
    std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << 
                    ";p_amount:" << _amount << 
                    ";withdrawal:" << 
                    "refused" << 
        std::endl;
		return (false);
	}
	else
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
        
		std::cout << "index:" << _accountIndex << 
                    ";p_amount:" << (_amount + withdrawal) << 
                    ";withdrawal:" << withdrawal <<
                    ";amount:" << _amount << 
                    ";nb_withdrawals:" << _nbWithdrawals <<
        std::endl;
		return (true);
	}
}
