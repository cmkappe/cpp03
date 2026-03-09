/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:20:06 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/09 18:07:26 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n========== Construction and Destruction Chain ==========\n" << std::endl;
	std::cout << "Creating ClapTrap:" << std::endl;
	ClapTrap clap("BasicCT");
	std::cout << "\nCreating ScavTrap:" << std::endl;
	ScavTrap scav("BasicST");

	std::cout << "\n========== Comparing ClapTrap vs ScavTrap ==========\n" << std::endl;
	std::cout << "ClapTrap attack (0 damage):" << std::endl;
	clap.attack("target");
	std::cout << "\nScavTrap attack (20 damage):" << std::endl;
	scav.attack("target");
	std::cout << "\nScavTrap takes damage and repairs:" << std::endl;
	scav.takeDamage(30);
	scav.beRepaired(15);

	std::cout << "\n========== ScavTrap Special Ability ==========\n" << std::endl;
	ScavTrap guardian("Guardian");
	guardian.guardGate();
	guardian.attack("intruder");
	guardian.guardGate();

	std::cout << "\n========== Energy Depletion (50 energy points) ==========\n" << std::endl;
	ScavTrap energetic("Energetic");
	std::cout << "Performing 50 attacks...\n" << std::endl;
	for (int i = 0; i < 50; i++)
		energetic.attack("dummy");
	
	std::cout << "\nNo energy left - attempting actions:" << std::endl;
	energetic.attack("target");
	energetic.beRepaired(10);

	std::cout << "\n========== Health Depletion (100 HP) ==========\n" << std::endl;
	ScavTrap tank("Tank");
	tank.takeDamage(100);
	std::cout << "\nAt 0 HP - attempting actions:" << std::endl;
	tank.attack("target");
	tank.guardGate();

	std::cout << "\n========== Copy Constructor ==========\n" << std::endl;
	ScavTrap original("Original");
	original.attack("target");
	ScavTrap copy(original);
	std::cout << "\nCopy attacking:" << std::endl;
	copy.attack("target");
	copy.guardGate();

	std::cout << "\n========== Assignment Operator ==========\n" << std::endl;
	ScavTrap alpha("Alpha");
	alpha.attack("target");
	ScavTrap beta("Beta");
	beta = alpha;
	std::cout << "\nAfter assignment:" << std::endl;
	beta.attack("target");

	std::cout << "\n========== Dynamic Allocation and Destructor Chains ==========\n" << std::endl;
	// use the derived type directly for calls and deletion to ensure correct destructor sequence
	ScavTrap* ptr = new ScavTrap("PointerScav");
	ptr->attack("target");
	std::cout << "\nDeleting through derived pointer:" << std::endl;
	delete ptr;

	std::cout << "\n========== Destructor Sequence ==========\n" << std::endl;
	std::cout << "All objects will be destroyed now:\n" << std::endl;
	return (0);
}
