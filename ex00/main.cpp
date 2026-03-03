/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:16:53 by ckappe            #+#    #+#             */
/*   Updated: 2026/03/04 00:41:47 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// Two independent objects.
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");

	// Basic actions: attack, take damage, repair
	alpha.attack("Beta");
	beta.takeDamage(3);
	beta.beRepaired(2);

	// Spend Alpha's energy with repeated attacks
	for (int i = 0; i < 10; i++)
		alpha.attack("training_dummy");

	// This repair should fail because Alpha has no energy left
	alpha.beRepaired(1);

	// At 0 HP, actions are blocked.
	beta.takeDamage(50);
	beta.attack("Alpha");
	beta.beRepaired(10);

	return (0);
}

