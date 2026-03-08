# pragma once

#include <string>
#include <iostream>

class ClapTrap{
	public:

		// Default Constructor
		ClapTrap();
		// Constructor
		ClapTrap(const std::string& name);
		// Copy constructor
		ClapTrap(const ClapTrap& other);
		// assignment operator: 
		ClapTrap& operator=(const ClapTrap& other);
		// Destructor
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};
