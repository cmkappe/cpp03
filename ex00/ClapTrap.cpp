/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:16:45 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/08 15:06:08 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
		// assignment operator: 
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
		