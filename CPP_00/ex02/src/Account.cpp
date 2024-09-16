/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:32:38 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/13 16:33:16 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Account.hpp"
#include <iostream>
#include <string>

static int i = 0;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
    std::cout << "[19920104_091532] ";
}

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
    return _totalAmount;
}
int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}
void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
}

Account::Account( int initial_deposit ) {
    
    this->_amount = initial_deposit;
    this->_accountIndex = i++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "created" << std::endl;

    _totalAmount += initial_deposit;
    _nbAccounts++;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "closed" << std::endl;
    _nbAccounts--;
}

void	Account::makeDeposit( int deposit ) {

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << checkAmount() + deposit << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits + 1 << std::endl;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();

    if (withdrawal < this->_amount)
    {
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "p_amount:" << checkAmount() << ";";
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << checkAmount() - withdrawal << ";";
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
        
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return true;
    }
    else {
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "p_amount:" << checkAmount() << ";";
        std::cout << "withdrawal:" << "refused" << std::endl;
        return false;
    }
}

int		Account::checkAmount( void ) const {
    return this->_amount;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
