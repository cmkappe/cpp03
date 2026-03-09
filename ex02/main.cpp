/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:19:34 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/09 18:16:14 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n========== Construction and Destruction Chain ==========\n" << std::endl;
	std::cout << "Creating ClapTrap:" << std::endl;
	ClapTrap clap("BasicCT");
	std::cout << "\nCreating ScavTrap:" << std::endl;
	ScavTrap scav("BasicST");
	std::cout << "\nCreating FragTrap:" << std::endl;
	FragTrap frag("BasicFT");

	std::cout << "\n========== Comparing All Three Classes ==========\n" << std::endl;
	std::cout << "ClapTrap (10 HP, 10 Energy, 0 Attack):" << std::endl;
	clap.attack("target");
	std::cout << "\nScavTrap (100 HP, 50 Energy, 20 Attack):" << std::endl;
	scav.attack("target");
	std::cout << "\nFragTrap (100 HP, 100 Energy, 30 Attack):" << std::endl;
	frag.attack("target");

	std::cout << "\n========== Special Abilities ==========\n" << std::endl;
	ScavTrap guardian("Guardian");
	guardian.guardGate();
	guardian.attack("intruder");
	
	FragTrap friendly("Friendly");
	friendly.highFivesGuys();
	friendly.attack("target");
	friendly.highFivesGuys();

	std::cout << "\n========== FragTrap Energy Management ==========\n" << std::endl;
	FragTrap energetic("Energetic");
	std::cout << "Performing 50 mixed turns (2 energy each = 100 total)...\n" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		energetic.attack("dummy");
		energetic.beRepaired(5);
	}
	
	// At this point energy should be 0; attack will fail, but high five still prints
	// because it does not consume energy or check HP in FragTrap::highFivesGuys().
	std::cout << "\nNo energy left - attempting actions:" << std::endl;
	energetic.attack("target");
	energetic.highFivesGuys();

	std::cout << "\n========== FragTrap Health Management ==========\n" << std::endl;
	FragTrap tank("Tank");
	tank.takeDamage(60);
	tank.beRepaired(30);
	std::cout << "\nTaking lethal damage:" << std::endl;
	tank.takeDamage(100);
	std::cout << "\nAt 0 HP - attempting actions:" << std::endl;
	tank.attack("target");
	tank.highFivesGuys();

	std::cout << "\n========== Copy Constructor ==========\n" << std::endl;
	FragTrap original("Original");
	original.attack("target");
	original.takeDamage(40);
	FragTrap copy(original);
	std::cout << "\nCopy attacking:" << std::endl;
	copy.attack("target");
	copy.highFivesGuys();

	std::cout << "\n========== Assignment Operator ==========\n" << std::endl;
	FragTrap alpha("Alpha");
	alpha.attack("target");
	alpha.takeDamage(30);
	FragTrap beta("Beta");
	beta = alpha;
	std::cout << "\nAfter assignment:" << std::endl;
	beta.attack("target");
	beta.highFivesGuys();

	std::cout << "\n========== Dynamic Allocation and Destructor Chains ==========\n" << std::endl;
	std::cout << "ClapTrap pointer to ClapTrap:" << std::endl;
	ClapTrap* ptr1 = new ClapTrap("PtrClap");
	ptr1->attack("target");
	delete ptr1;
	
	std::cout << "\nDerived pointer to ScavTrap:" << std::endl;
	// Create a ScavTrap, call its attack, then delete it using the same type.
	// use the derived type directly for calls and deletion to ensure correct destructor sequence
	ScavTrap* ptr2 = new ScavTrap("PtrScav");
	ptr2->attack("target");
	delete ptr2;
	
	std::cout << "\nDerived pointer to FragTrap:" << std::endl;
	FragTrap* ptr3 = new FragTrap("PtrFrag");
	ptr3->attack("target");
	delete ptr3;

	std::cout << "\n========== Edge Cases ==========\n" << std::endl;
	FragTrap edge("Edge");
	std::cout << "Taking excessive damage:" << std::endl;
	edge.takeDamage(9999);
	
	FragTrap healer("Healer");
	std::cout << "\nRepairing beyond max HP:" << std::endl;
	// ClapTrap::beRepaired() does not cap HP, so HP can exceed 100 here.
	healer.takeDamage(80);
	healer.beRepaired(200);

	std::cout << "\n========== Destructor Sequence ==========\n" << std::endl;
	std::cout << "All objects will be destroyed now:\n" << std::endl;
	return (0);
}
