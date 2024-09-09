/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:32:38 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 21:09:38 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
using namespace std;

static int i = 0;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
    cout << "[19920104_091532] ";
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
    cout << "accounts:" << Account::getNbAccounts() << ";";
    cout << "total:" << Account::getTotalAmount() << ";";
    cout << "deposits:" << Account::getNbDeposits() << ";";
    cout << "withdrawals:" << Account::getNbWithdrawals();
    cout << endl;
}

Account::Account( int initial_deposit ) {
    
    this->_amount = initial_deposit;
    this->_accountIndex = i++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "amount:" << checkAmount() << ";";
    cout << "created" << endl;

    _totalAmount += initial_deposit;
    _nbAccounts++;
}

Account::~Account( void ) {
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "amount:" << checkAmount() << ";";
    cout << "closed" << endl;
    _nbAccounts--;
}

void	Account::makeDeposit( int deposit ) {

    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "p_amount:" << checkAmount() << ";";
    cout << "deposit:" << deposit << ";";
    cout << "amount:" << checkAmount() + deposit << ";";
    cout << "nb_deposits:" << this->_nbDeposits + 1 << endl;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();

    if (withdrawal < this->_amount)
    {
        cout << "index:" << this->_accountIndex << ";";
        cout << "p_amount:" << checkAmount() << ";";
        cout << "withdrawal:" << withdrawal << ";";
        cout << "amount:" << checkAmount() - withdrawal << ";";
        cout << "nb_withdrawals:" << this->_nbWithdrawals + 1 << endl;
        
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return true;
    }
    else {
        cout << "index:" << this->_accountIndex << ";";
        cout << "p_amount:" << checkAmount() << ";";
        cout << "withdrawal:" << "refused" << endl;
        return false;
    }
}

int		Account::checkAmount( void ) const {
    return this->_amount;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "amount:" << checkAmount() << ";";
    cout << "deposits:" << this->_nbDeposits << ";";
    cout << "withdrawals:" << this->_nbWithdrawals << endl;
}
