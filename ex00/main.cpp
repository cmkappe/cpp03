/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:16:53 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/09 19:21:17 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\n========== Basic Construction and Actions ==========\n" << std::endl;
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");

	alpha.attack("Beta");
	beta.takeDamage(0);
	beta.beRepaired(5);
	alpha.beRepaired(3);

	std::cout << "\n========== Energy Depletion Test ==========\n" << std::endl;
	ClapTrap charlie("Charlie");
	std::cout << "Performing 10 attacks to deplete energy...\n" << std::endl;
	for (int i = 0; i < 10; i++)
		charlie.attack("dummy");
	
	std::cout << "\nAttempting actions with no energy:" << std::endl;
	charlie.attack("target");
	charlie.beRepaired(5);

	std::cout << "\n========== Health Depletion Test ==========\n" << std::endl;
	ClapTrap delta("Delta");
	delta.takeDamage(10);
	
	std::cout << "\nAttempting actions at 0 HP:" << std::endl;
	delta.attack("target");
	delta.beRepaired(5);

	std::cout << "\n========== Copy Constructor Test ==========\n" << std::endl;
	ClapTrap original("Original");
	original.attack("target");
	ClapTrap copy(original);
	std::cout << "\nCopy attacking:" << std::endl;
	copy.attack("target");

	std::cout << "\n========== Assignment Operator Test ==========\n" << std::endl;
	ClapTrap echo("Echo");
	echo.attack("target");
	ClapTrap foxtrot("Foxtrot");
	foxtrot = echo;
	std::cout << "\nAfter assignment:" << std::endl;
	foxtrot.attack("target");

	std::cout << "\n========== Destructor Test ==========\n" << std::endl;
	std::cout << "Objects will be destroyed now:\n" << std::endl;
	return (0);
}

