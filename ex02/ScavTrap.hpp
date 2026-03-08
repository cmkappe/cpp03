# pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		// Default Constructor
		ScavTrap();
		// Constructor
		ScavTrap(const std::string& name);
		// Copy constructor
		ScavTrap(const ScavTrap& other);
		// assignment operator:
		ScavTrap& operator=(const ScavTrap& other);
		// Destructor
		~ScavTrap();

		// Override attack
		void attack(const std::string& target);
		// Special ability
		void guardGate();
};
