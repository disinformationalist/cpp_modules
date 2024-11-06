#include "Account.hpp"
#include <ctime>//time
#include <iomanip>
#include <iostream>

//init all statics
int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_accountIndex =  getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	_nbAccounts++;

	//ex:	[19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
	_nbAccounts--;
}

//displays time, format: [19920104_091532] yyyymmdd_hhmmss

void	Account::_displayTimestamp( void )
{
	std::time_t now;

	now = std::time(0);

	std::tm *local_time = std::localtime(&now);


	std::cout << "["
			  << local_time->tm_year + 1900
			  << std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << local_time->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << local_time->tm_hour
			  << std::setw(2) << std::setfill('0') << local_time->tm_min
			  << std::setw(2) << std::setfill('0') << local_time->tm_sec
			  << "]";
}

//dispay the accounts info
//ex: [19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

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

//getters for values

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

//make deposit
//ex: [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";p_amount:" 
			  << checkAmount()
			  << ";deposit:"
			  << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << ";amount:" 
			  << Account::checkAmount()
			  << ";nb_deposits:"
			  << this->_nbDeposits
			  << std::endl;
}

// ex(if accepted): [19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1 
// ex(if refused): [19920104_091532] index:5;p_amount:23;withdrawal:refused

bool	Account::makeWithdrawal( int withdrawal )
{
	int amount;

	amount = checkAmount();
	
	_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";p_amount:" 
			  <<  amount
			  << ";withdrawal:";
	if (withdrawal <= amount)
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout << withdrawal
				  << ";amount:"
				  << _amount
				  << ";nb_withdrawals:"
				  << _nbWithdrawals
				  << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused"
				  << std::endl;
		return (false);
	}
}

//ex: [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";amount:" 
			  << _amount
			  << ";deposits:"
			  << _nbDeposits
			  << ";withdrawals:" 
			  << _nbWithdrawals
			  << std::endl;
}