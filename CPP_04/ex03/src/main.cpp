/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:09:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/24 19:46:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// int main( void )
// {
// 	// 1. Crear MateriaSource
// 	std::cout << BOLD << BLUE << "1. Creating MateriaSource" << RESET << std::endl; 
// 	IMateriaSource* src = new MateriaSource();
// 	src->printMaterias();

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << GREEN << "2. \"src\" learning 5 materias" << RESET << std::endl;
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	Ice	*mat = new Ice();
// 	src->learnMateria(mat);
// 	delete mat;
// 	src->printMaterias();

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << MAGENTA << "3. Creating Character \"vilma\" and \"oktorok\"" << RESET << std::endl;
// 	Character* vilma = new Character("vilma");
// 	vilma->printMaterias();

// 	Character* oktorok = new Character("oktorok");
// 	oktorok->printMaterias();

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << YELLOW << "4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia" << RESET << std::endl;
// 	vilma->equip(NULL);
	
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	vilma->equip(tmp);
// 	delete tmp;

// 	tmp = src->createMateria("Ice");
// 	vilma->equip(tmp);
// 	delete tmp;

// 	tmp = src->createMateria("Cure");
// 	vilma->equip(tmp);
// 	delete tmp;

// 	tmp = src->createMateria("Ice");
// 	vilma->equip(tmp);
// 	delete tmp;

// 	vilma->printMaterias();
// 	tmp = src->createMateria("Ice");
// 	oktorok->equip(tmp);
// 	delete tmp;

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << CYAN << "5. Testing Character Assignation overload \"vilma = oktorok\"" << RESET << std::endl;	
// 	*oktorok = *vilma;

// 	vilma->unequip(0);
// 	std::cout << RED << "VILMA" << RESET << std::endl;
// 	vilma->printMaterias();
// 	std::cout << RED << "OKTOROK" << RESET << std::endl;
// 	oktorok->printMaterias();

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << RED << "6. Testing character copy constructor for deep copy" << RESET << std::endl; 
// 	Character* stardust = new Character(*vilma);
// 	stardust->printMaterias();

// 	tmp = src->createMateria("Ice");
// 	vilma->equip(tmp);
// 	delete tmp;

// 	std::cout << RED << "VILMA" << RESET << std::endl;
// 	vilma->printMaterias();
// 	std::cout << RED << "STARDUST" << RESET << std::endl;
// 	stardust->printMaterias();

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << BLUE << "7. \"vilma\" using all equipped materias on \"oktorok\"" << RESET << std::endl;
// 	vilma->use(0, *oktorok);
// 	vilma->use(1, *oktorok);
// 	vilma->use(2, *oktorok);
// 	vilma->use(3, *oktorok);
// 	vilma->use(10, *oktorok);
// 	vilma->use(-1, *oktorok);

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << GREEN << "8. \"vilma\" trying to use unequipped materias on \"oktorok\"" << RESET << std::endl;
// 	vilma->unequip(0);
// 	vilma->use(0, *oktorok);

// 	// ------------------------------------------------------------------------------------ //

// 	std::cout << BOLD << MAGENTA << "9. New character \"lucifer\" equipping and unequipping materias" << RESET << std::endl;
// 		std::cout << std::endl;
// 		ICharacter* lucifer = new Character("lucifer");
// 		AMateria *cure = new Cure;
// 		AMateria *ice = new Ice;

// 		lucifer->equip(cure);
// 		lucifer->equip(ice);
// 		lucifer->equip(cure);
// 		lucifer->equip(ice);
// 		lucifer->unequip(0);
// 		lucifer->unequip(1);
// 		lucifer->unequip(2);
// 		lucifer->unequip(3);
// 		lucifer->equip(cure);
// 		lucifer->equip(ice);

// 		lucifer->printMaterias();

// 		delete cure;
// 		delete ice;
// 	std::cout << std::endl;

// // ------------------------------------------------------------------------------------ //

// 	std::cout << RED << "10. Testing if unequiped materia is freed" << RESET << std::endl;
// 		std::cout << std::endl;

// 		ICharacter* test = new Character("test");
		
// 		tmp = src->createMateria("ice");
// 		test->equip(tmp);
// 		delete tmp;
// 		test->unequip(0);

// 	std::cout << std::endl;

// // ------------------------------------------------------------------------------------ //
// 	std::cout << RED << "11. Deleting \"vilma\", \"oktorok\", \"stardust\" and \"lucifer\"" << RESET << std::endl;
// 		std::cout << std::endl;
	
// 	delete test;
// 	delete lucifer;
// 	delete stardust;
// 	delete oktorok;
// 	delete vilma;
// 	delete src;

// 	return (0);
// }

int main() 
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl;
		std::cout << RED << "1. Create new MateriaSource and learn materias (check maximum too):" << RESET << std::endl;
		std::cout << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *mat = new Cure();
		src->learnMateria(mat);
		std::cout << std::endl;
		
		std::cout << GREEN << "2. Create 2 new characters and test deep copy:" << RESET << std::endl;
		std::cout << std::endl;
		Character *dur0 = new Character("Alice");
		ICharacter *dur1 = new Character(*dur0);
		delete dur0;
		delete dur1;
		std::cout << std::endl;

		std::cout << YELLOW << "3. Create materias and equip them (also check unknown materias):" << RESET << std::endl;
		std::cout << std::endl;
		AMateria* tmp;
		ICharacter *dur2 = new Character("Alice");
		tmp = src->createMateria("ice");
		dur2->equip(tmp);
		tmp = src->createMateria("cure");
		dur2->equip(tmp);
		tmp = src->createMateria("hi");
		dur2->equip(tmp);
		delete src;
		std::cout << std::endl;

		std::cout << BLUE << "4. Check maximum equipped too:" << RESET << std::endl;
		std::cout << std::endl;
		AMateria *cure = new Cure();
		AMateria *ice = new Ice();
		dur2->equip(cure);
		dur2->equip(cure);
		dur2->equip(ice);
		dur2->unequip(2);
		delete cure; // Cure must be deleted manually when unequipped
		dur2->unequip(2);
		dur2->unequip(6);
		std::cout << std::endl;

		std::cout << MAGENTA << "5. Use materias on new chacarter:" << RESET << std::endl;
		std::cout << std::endl;
		ICharacter* bob = new Character("Bob");
		dur2->use(0, *bob);
		dur2->use(1, *bob);
		dur2->use(2, *bob);
		dur2->use(6, *bob);
		dur2->use(-4, *bob);
		dur2->use(3, *bob);
		delete bob;
		std::cout << std::endl;

		delete dur2;

		// Cure must be deleted manually when unequipped ????????
		delete mat;

		return (0); 
	}
}
