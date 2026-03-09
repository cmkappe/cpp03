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

		
	private:
		std::string	_name;
		int			_hitPoints;		// representing health of ClapTrap
		int			_energyPoints;	// energy of ClapTrap
		int			_attackDamage;	// attack damage of ClapTrap	
};


/* the following private attributes initialized
to the values specified in brackets:
• Name, which is passed as a parameter to the constructor
• Hit points (10), representing the health of the ClapTrap
• Energy points (10)
• Attack damage (0) */