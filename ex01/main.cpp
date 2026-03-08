#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- Basic behavior ---" << std::endl;
	ClapTrap basic("Basic");
	ScavTrap guard("Serena");

	basic.attack("target_dummy");
	guard.attack("target_dummy");
	guard.takeDamage(30);
	guard.beRepaired(10);
	guard.guardGate();

	std::cout << "\n--- Chaining demo (scope) ---" << std::endl;
	{
		ScavTrap scoped("Scoped");
		scoped.attack("intruder");
	}

	std::cout << "\n--- Copy/assignment demo ---" << std::endl;
	ScavTrap copy(guard);
	ScavTrap assigned;
	assigned = guard;
	copy.guardGate();
	assigned.attack("another_target");

	std::cout << "\n--- Energy depletion demo ---" << std::endl;
	for (int i = 0; i < 51; i++)
		guard.attack("wall");

	return (0);
}
