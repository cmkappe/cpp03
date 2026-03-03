# pragma once

#include <string>

class ClapTrap{
	private:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		// Default constructor: uses baseline member values.
		ClapTrap();
		// Constructor: sets name and default combat stats.
		ClapTrap(const std::string& name);
		// Copy constructor: duplicates another object's state.
		ClapTrap(const ClapTrap& other);
		// Assignment operator: replaces current state.
		ClapTrap& operator=(const ClapTrap& other);
		// Destructor: no manual cleanup required.
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

/* First, you have to implement a class! How original!
It will be called ClapTrap and will have the following private attributes initialized
to the values specified in brackets:
• Name, which is passed as a parameter to the constructor
• Hit points (10), representing the health of the ClapTrap
• Energy points (10)
• Attack damage (0)
Add the following public member functions so that the ClapTrap behaves more real-
istically:
• void attack(const std::string& target);
• void takeDamage(unsigned int amount);
• void beRepaired(unsigned int amount); */