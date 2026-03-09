# pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		// Default Constructor
		FragTrap();
		// Constructor
		FragTrap(const std::string& name);
		// Copy constructor
		FragTrap(const FragTrap& other);
		// assignment operator:
		FragTrap& operator=(const FragTrap& other);
		// Destructor
		~FragTrap();

		// FragTrap-specific messages for damage/repair
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Special ability: asks for a positive high five.
		void highFivesGuys(void);
};

