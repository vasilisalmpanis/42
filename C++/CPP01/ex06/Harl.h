//
// Created by Vasileios Almpanis on 10/17/23.
//

#ifndef harl_HPP
#define harl_HPP
#include <iostream>


class Harl {
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
};


#endif
