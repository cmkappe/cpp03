#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	// Basic object creation for each class.
	std::cout << "--- Basic behavior ---" << std::endl;
	ClapTrap basic("Basic");
	ScavTrap serena("Serena");
	FragTrap buddy("Buddy");

	// Reused behavior (attack/takeDamage/beRepaired) + class-specific abilities.
	basic.attack("target_dummy");
	serena.attack("target_dummy");
	buddy.attack("target_dummy");
	serena.takeDamage(30);
	serena.beRepaired(10);
	serena.guardGate();
	buddy.highFivesGuys();

	// Scope test: shows constructor/destructor chaining clearly.
	std::cout << "\n--- Chaining demo (scope) ---" << std::endl;
	{
		ScavTrap scoped("Scoped");
		scoped.attack("intruder");
		FragTrap scopedFrag("ScopedFrag");
		scopedFrag.highFivesGuys();
	}

	// Orthodox Canonical Form checks: copy constructor + assignment operator.
	std::cout << "\n--- Copy/assignment demo ---" << std::endl;
	ScavTrap copy(serena);
	ScavTrap assigned;
	assigned = serena;
	FragTrap fragCopy(buddy);
	FragTrap fragAssigned;
	fragAssigned = buddy;
	copy.guardGate();
	assigned.attack("another_target");
	fragCopy.highFivesGuys();
	fragAssigned.attack("another_target");

	// One short energy depletion demo (kept concise to avoid huge output spam).
	std::cout << "\n--- ScavTrap energy depletion demo ---" << std::endl;
	for (int i = 0; i < 51; i++)
		serena.attack("wall");

	return (0);
}
