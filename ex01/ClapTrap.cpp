/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:19:59 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/09 19:24:14 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// -----------------------------------------------------
// *** CONSTRUCTOR & DESTRUCTOR ***
// -----------------------------------------------------


ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}
// Constructor: sets the given name and default combat stats
ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}
// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}
// assignment operator: Assign state to an ALREADY existing object
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return (*this);
}
// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << _name << std::endl;
}

// -----------------------------------------------------
// *** MEMBER FUNCTION ***
// -----------------------------------------------------
	// Core actions use HP/EP:
	// - HP (hit points) is health; if it reaches 0, the ClapTrap is "out".
	// - EP (energy points) is spent on attack/repair; if it reaches 0, actions fail.
	// attack(): spends 1 EP and deals attack damage if HP/EP > 0.
	// takeDamage(): reduces HP (not below 0).
	// beRepaired(): spends 1 EP and increases HP if HP/EP > 0.
		
void ClapTrap::attack(const std::string& target)
{
	// attack: check for sufficient hit amd energy points (more than 0)
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because hit points are insufficient!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because energy points are insufficient!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed! (no hit points left)" << std::endl;
		return;
	}
	// HP min: clamps to 0 to avoid negative values
	if ((unsigned int)_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	// if hitpoints or energy is insufficient
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair because it has no hit points left!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired because it has no energy points left!" << std::endl;
		return;
	}
	// repair consumes 1 energy point, then increases HP
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
		<< " hit points! Current HP: " << _hitPoints << std::endl;
}
