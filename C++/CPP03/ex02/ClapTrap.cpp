//
// Created by Vasileios Almpanis on 10/20/23.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor initialized" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap constructor initialized" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor initialized" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	if (this != &obj)
	{
		*this = obj;
	}
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_ad = obj._ad;
		this->_ep = obj._ep;
		this->_hp = obj._hp;
		this->_name = obj._name;
	}
	return (*this);
}

int ClapTrap::getHp(void){
	return (_hp);
}
int ClapTrap::getEp(void){
	return (_ep);
}
int ClapTrap::getAd(void){
	return (_ad);
}

void ClapTrap::setHp(int hp) {
	_hp = hp;
}

void ClapTrap::setEp(int ep) {
	_ep = ep;
}
void ClapTrap::setAd(int ad){
	_ad = ad;
}
std::string ClapTrap::getName(void){
	return (_name);
}

void ClapTrap::attack(const std::string& target) {
	if (_ep <= 0)
	{
		std::cout << "ClapTrap object " << _name << " has no more EP to attack" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ClapTrap object " << _name << " attacks " << target << " and causing " << _ad << " points of damage." << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
	for (unsigned int i = 0; i < amount; ++i) {
		if (_hp <= 0)
		{
			std::cout << "ClapTrap object " << _name << " has no more HP." << std::endl;
			return ;
		}
		_hp--;
	}
	std::cout << "ClapTrap object " << _name << " took " << amount << " points of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){ 
	if (!_ep || !_hp)
	{
		std::cout << "ClapTrap object " + _name << " cannot be repaired" << std::endl;
	}
	else {
	--_ep;
	_hp+= amount;
	std::cout << "ClapTrap object " + _name << " repaired itself gaining " << amount << " of Hit points" << std::endl;
	}
}
