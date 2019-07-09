#include "pch.h"
#include <iostream>
#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
#include "Environment.h"
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;
int main()
{

	/*
	Point3D start_point(1, 2, 3);
	Player Player1("Player_1", &start_point, 20, 30);
	Environment world; 
	world.generateEntities(); 
	
	Point3D some_point1(1, 2, 4);
	Point2D some_point2(1, 3);
	Point2D some_point3(2, 2);
	Mob Mob1("Mob_1", &some_point1, 5, 5);
	Mob Mob2("Mob_2", &some_point2, 5, 10);
	Mob Mob3("Mob_3", &some_point3, 3, 3);
	NPC npc1("NPC_1", &some_point1);
	world.add(&Player1);
	world.add(&Mob1);
	world.add(&Mob2);
	world.add(&Mob3);
	world.add(&npc1);

	cout << "The World: " << endl;
	world.printEnvironment(); // print the entities
	cout << endl << endl;

	world.sortToClosest(&Player1); //sort by distance to Player1
	cout << "Sorted world:" << endl;
	world.printEnvironment(); // print sorted entities;
	for (int i = 0; i < world.getSize(); i++)
	{
		if (world.getAt(i)->getType() == Types::Type(2))
		{
			Player1.attack(world.getAt(i));
		}
	}
	//attack method 
	cout << endl << endl;
	cout << "Sorted world after the attack: " << endl;
	world.printEnvironment(); //final print, after the attack;
	*/
	/*
	Problems:
	1. inputing symbols when int/double needed;
	*/
	char input;
	Entity* character = nullptr;
	do
	{
		
		std::cout << "\t\t\t\t\t MMORPG Simple World" << std::endl << std::endl;
		std::cout << "\t\t\t\t\t 1.Create your character: " << std::endl;
		std::cout << "\t\t\t\t\t 2.Create new world: " << std::endl;
		std::cout << "\t\t\t\t\t 3.Quit." << std::endl<<std::endl;
		cout << "\t\t\t\t\t Your choice: ";
		cin >> input;
		cin.ignore(256, '\n');
		cin.clear();
		if (input == '1')
		{
			system("cls");
			cout << "Character:" << endl << endl;
			std::string new_name;
			std::cout << "Name: ";
			cin >> new_name;

			cout << "Choose type of location:" << endl;
			cout << "1.2D" << endl;
			cout << "2.3D" << endl;

			char random_input;
			cin >> random_input;
			cin.ignore(256, '\n');
			cin.clear();

			double x_toAdd;
			double y_toAdd;
			double z_toAdd;
			Point2D* location;
			if (random_input == '1')
			{
				double test_x, test_y;
				cout << "x = ";
				cin >> test_x;
				x_toAdd = test_x;

				cout << "y = ";
				cin >> test_y;
				y_toAdd = test_y;
				Point2D def_point(x_toAdd, y_toAdd);
				location = def_point.clone();
			}
			else
			{
				double test_x, test_y, test_z;
				cout << "x = ";
				cin >> test_x;
				x_toAdd = test_x;

				cout << "y = ";
				cin >> test_y;
				y_toAdd = test_y;

				cout << "z = ";
				cin >> test_z;
				z_toAdd = test_z;
				Point3D def_point(x_toAdd, y_toAdd, z_toAdd);
				location = def_point.clone();
			}
			std::cout << "Damage: ";
			int damage_toAdd;
			cin >> damage_toAdd;

			std::cout << "Health: ";
			int health_toAdd;
			cin >> health_toAdd;
			Player new_character(new_name, location, damage_toAdd, health_toAdd);
			character = new_character.clone();
			cout << "Character created!" << endl;
			system("pause");
		}
		else if (input == '2')
		{
			Environment world;
			bool if_4 = false;
			char new_input;
			do
			{
				
				Entity* to_add;
				
				system("cls");
				std::cout << "\t\t\t\t\t Main menu:" << std::endl << std::endl;
				std::cout << "\t\t\t\t\t1.Add Entity:" << std::endl;
				std::cout << "\t\t\t\t\t2.Get Entity:" << std::endl;
				std::cout << "\t\t\t\t\t3.Remove Entity:" << std::endl;
				std::cout << "\t\t\t\t\t4.Generate some entities(usable only once):" << std::endl;
				std::cout << "\t\t\t\t\t5.Destroy Entities:" << std::endl;
				std::cout << "\t\t\t\t\t6.Get closest to the character entity: " << std::endl;
				std::cout << "\t\t\t\t\t7.Print world:" << std::endl;
				std::cout << "\t\t\t\t\t8.Back:" << std::endl;
				cout << "\t\t\t\t\tYour choice: ";
				cin >> new_input;
				cin.ignore(256, '\n');
				cin.clear();
				switch (new_input)
				{
				case '1':
				{
					
					system("cls");
					std::cout << "\t\t\t\t\t What type of Entity would you like to add?" << std::endl << std::endl;
					std::cout << "\t\t\t\t\t1.Player" << std::endl;
					std::cout << "\t\t\t\t\t2.NPC" << std::endl;
					std::cout << "\t\t\t\t\t3.Mob" << std::endl;
					char new_input1;
					cin >> new_input1;
					system("cls");
					if (new_input1 == '1') // add player;
					{
						std::string new_name;
						std::cout << "Name: ";
						cin >> new_name;

						cout << "Choose type of location:" << endl;
						cout << "1.2D" << endl;
						cout << "2.3D" << endl;

						char random_input;
						cin >> random_input;
						cin.ignore(256, '\n');
						cin.clear();

						double x_toAdd;
						double y_toAdd;
						double z_toAdd;
						Point2D* location;
						if (random_input == '1')
						{
							double test_x, test_y;
							cout << "x = ";
							cin >> test_x;
							x_toAdd = test_x;

							cout << "y = ";
							cin >> test_y;
							y_toAdd = test_y;
							Point2D def_point(x_toAdd, y_toAdd);
							location = def_point.clone();
						}
						else
						{
							double test_x, test_y, test_z;
							cout << "x = ";
							cin >> test_x;
							x_toAdd = test_x;

							cout << "y = ";
							cin >> test_y;
							y_toAdd = test_y;

							cout << "z = ";
							cin >> test_z;
							z_toAdd = test_z;
							Point3D def_point(x_toAdd, y_toAdd, z_toAdd);
							location = def_point.clone();
						}
						std::cout << "Damage: ";
						int damage_toAdd;
						cin >> damage_toAdd;

						std::cout << "Health: ";
						int health_toAdd;
						cin >> health_toAdd;
						Player player_toAdd(new_name, location, damage_toAdd, health_toAdd);
						to_add = player_toAdd.clone();
						world.add(to_add);

					}
					else if (new_input1 == '2') // add NPC;
					{
						std::string new_name;
						std::cout << "Name: ";
						cin >> new_name;

						cout << "Choose type of location:" << endl;
						cout << "1.2D" << endl;
						cout << "2.3D" << endl;

						char random_input;
						cin >> random_input;
						cin.ignore(256, '\n');
						cin.clear();

						double x_toAdd;
						double y_toAdd;
						double z_toAdd;
						Point2D* location;
						if (random_input == '1')
						{
							double test_x, test_y;
							cout << "x = ";
							cin >> test_x;
							x_toAdd = test_x;

							cout << "y = ";
							cin >> test_y;
							y_toAdd = test_y;
							Point2D def_point(x_toAdd, y_toAdd);
							location = def_point.clone();
						}
						else
						{
							double test_x, test_y, test_z;
							cout << "x = ";
							cin >> test_x;
							x_toAdd = test_x;

							cout << "y = ";
							cin >> test_y;
							y_toAdd = test_y;

							cout << "z = ";
							cin >> test_z;
							z_toAdd = test_z;
							Point3D def_point(x_toAdd, y_toAdd, z_toAdd);
							location = def_point.clone();
						}
						NPC npc_toAdd(new_name, location);
						to_add = npc_toAdd.clone();
						world.add(to_add);
					}
					else
					{
					    std::string new_name;
						std::cout << "Name: ";
						cin >> new_name;

						cout << "Choose type of location:" << endl;
						cout << "1.2D" << endl;
						cout << "2.3D" << endl;

						char random_input;
						cin >> random_input;
						cin.ignore(256, '\n');
						cin.clear();

						double x_toAdd;
						double y_toAdd;
						double z_toAdd;
						Point2D* location;
						if (random_input == '1')
						{
							double test_x, test_y;
							cout << "x = ";
							cin >> test_x;
							x_toAdd = test_x;

							cout << " y = ";
							cin >> test_y;
							y_toAdd = test_y;
							Point2D def_point(x_toAdd, y_toAdd);
							location = def_point.clone();
						}
						else
						{
							double test_x, test_y, test_z;
							cout << "x = ";
							cin >> test_x;
							x_toAdd = test_x;

							cout << "y = ";
							cin >> test_y;
							y_toAdd = test_y;

							cout << "z = ";
							cin >> test_z;
							z_toAdd = test_z;
							Point3D def_point(x_toAdd, y_toAdd, z_toAdd);
							location = def_point.clone();
						}
						std::cout << "Damage: ";
						int damage_toAdd;
						cin >> damage_toAdd;

						std::cout << "Health: ";
						int health_toAdd;
						cin >> health_toAdd;
						Mob mob_toAdd(new_name, location, damage_toAdd, health_toAdd);
						to_add = mob_toAdd.clone();
						world.add(to_add);
					}
					system("pause");
					//system("cls");
					break;
				}
				case '2':
				{
					system("cls");
					int index;
					cout << "Index: ";
					cin >> index;
					if (world.getAt(index) == nullptr)
					{
						cout << "There is no entity with that index!" << endl;
					}
					else
					{
						world.getAt(index)->print();
					}
					system("pause");
					break;
				}
				case '3':
				{
					system("cls");
					int index;
					cout << "Index: ";
					cin >> index;
					world.removeAt(index);
					system("pause");
					break;
				}
				case '4':
				{
					if (if_4 == true)
					{
						cout << "You used that option already!" << endl;
					}
					else
					{
						world.generateEntities();
						cout << "Entities generated!" << endl;
						if_4 = true;
					}
					Sleep(1200);
					break;
				}
				case '5':
				{
					cout << "World cleared!" << endl;
					Sleep(1200);
					world.destroyEntities();
					break;
				}
				case '6':
				{
					
					if (character != nullptr)
					{
						system("cls");
						cout << "Choose Type of Entity:" << endl << endl;
						cout << "1.Player" << endl;
						cout << "2.NPC" << endl;
						cout << "3.Mob" << endl;
						int type_ofEntity;
						cin >> type_ofEntity;
						Types::Type entity;
						if (type_ofEntity == 1)
						{
							entity = Types::PLAYER;
						}
						else if (type_ofEntity == 2)
						{
							entity = Types::NPC;
						}
						else if (type_ofEntity == 3)
						{
							entity = Types::MOB;
						}
						if (world.getClosestAliveEntity(character, entity) == nullptr)
						{
							cout << "There are no alive entities" << endl;
						}
						else
						{
							world.getClosestAliveEntity(character, entity)->print();
						}
						system("pause");
						break;
					}
					else
					{
						cout << "\t\t\t\t\tYou haven't created a character. Press 8!" << endl;
						system("pause");
						break;
					}
				}
				case '7':
				{
					system("cls");
					world.printEnvironment();
					system("pause");
					break;
				}
				system("pause");
				system("cls");
				}
			} while (new_input != '8');
		}
		else if (input == '3')
		{
		cout << "\t\t\t\t\t Goodbye! " << endl;
		return 0;
        }
		//system("pause");
		system("cls");

	} while (input != '3');
}
