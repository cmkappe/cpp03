#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- Basic behavior ---" << std::endl;
	ClapTrap basic("Basic");
	ScavTrap serena("Serena");

	basic.attack("target_dummy");
	serena.attack("target_dummy");
	serena.takeDamage(30);
	serena.beRepaired(10);
	serena.guardGate();

	std::cout << "\n--- Chaining demo (scope) ---" << std::endl;
	{
		ScavTrap scoped("Scoped");
		scoped.attack("intruder");
	}

	std::cout << "\n--- Copy/assignment demo ---" << std::endl;
	ScavTrap copy(serena);
	ScavTrap assigned;
	assigned = serena;
	copy.guardGate();
	assigned.attack("another_target");

	std::cout << "\n--- Energy depletion demo ---" << std::endl;
	for (int i = 0; i < 51; i++)
		serena.attack("wall");

	return (0);
}
