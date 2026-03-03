/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:16:45 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 00:38:02 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// Default constructor: initializes all members to baseline ClapTrap values
ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Constructor: sets the given name and default combat stats.
ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << this->name << std::endl;
}

// Copy constructor: copies all member values from another ClapTrap
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Assignment operator: overwrites current state with another object's state
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return (*this);
}

// Destructor: no manual cleanup needed (no dynamic memory ownership here)
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string& target)
{
	// Attack: blocked if hit points are 0 or energy points are 0
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't attack because it has no hit points left!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't attack because it has no energy points left!" << std::endl;
		return;
	}
	// Attack cost: consume 1 energy point on success
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	// Damage: if already at 0 HP, keep state unchanged
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		return;
	}
	// HP min: clamps to 0 to avoid negative values
	if ((unsigned int)hitPoints <= amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " damage! Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	// Repair: blocked if hit points are 0 or energy points are 0
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't repair because it has no hit points left!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't repair because it has no energy points left!" << std::endl;
		return;
	}
	// Repair cost: consume 1 energy point, then increase HP
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
			  << " hit points! Current HP: " << hitPoints << std::endl;
}
