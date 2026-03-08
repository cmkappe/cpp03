#include "FragTrap.hpp"
#include <iostream>

// Default Constructor
// Calls ClapTrap constructor first, then sets FragTrap-specific stats.
FragTrap::FragTrap() : ClapTrap("default_frag")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// Constructor
// Name is passed to the base (ClapTrap) part, then FragTrap overrides stats.
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

// Copy constructor
// First copies the ClapTrap part, then copies the whole object with operator=.
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// assignment operator:
// Reuse ClapTrap assignment so inherited attributes are copied correctly.
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called" << std::endl;
	return (*this);
}

// Destructor
// Runs first for FragTrap, then ClapTrap destructor runs automatically.
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

// Special ability
// FragTrap-only method (not in ClapTrap).
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}

