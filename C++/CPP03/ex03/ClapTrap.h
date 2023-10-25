//
// Created by Vasileios Almpanis on 10/20/23.
//

#ifndef ClapTrap_HPP
#define ClapTrap_HPP
#include <iostream>

class ClapTrap {
protected:
	std::string _name;
	int _hp;
	int _ep;
	int _ad;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	ClapTrap(ClapTrap const &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	int getHp(void);
	int getEp(void);
	int getAd(void);
	void setHp(int hp);
	void setEp(int ep);
	void setAd(int ad);
	std::string getName(void);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif
