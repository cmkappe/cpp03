/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:19:26 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/09 19:21:42 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// -----------------------------------------------------
// *** CONSTRUCTOR & DESTRUCTOR ***
// -----------------------------------------------------

// Default Constructor
// Calls ClapTrap constructor first, then sets FragTrap-specific stats
FragTrap::FragTrap() : ClapTrap("default_frag")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// Constructor
// Name is passed to the base (ClapTrap) part, then FragTrap overrides stats
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

// -----------------------------------------------------
// *** MEMBER FUNCTION ***
// -----------------------------------------------------

// Special ability: FragTrap-only method (not in ClapTrap)
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

// Damage handling with FragTrap-specific message
void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " is already destroyed! (no hit points left)" << std::endl;
		return;
	}
	if ((unsigned int)_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "FragTrap " << _name << " takes " << amount
			  << " damage! Remaining HP: " << _hitPoints << std::endl;
}

// Repair handling with FragTrap-specific message
void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't repair because it has no hit points left!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " can't be repaired because it has no energy points left!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "FragTrap " << _name << " repairs itself for " << amount
			  << " hit points! Current HP: " << _hitPoints << std::endl;
}

