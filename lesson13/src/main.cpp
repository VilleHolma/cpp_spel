#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <string>

int main()
{
    // Exercises
    // I reused the code we built previously since otherwise it would be a waste of time if
    // just rewrite the same code again and again... 
    // The main goal of this lesson is to structure the code and start working with Cmake which I've done!
    Player player("Ville", 100, 100);

    std::vector<Enemy> enemies = {
        Enemy("Goblin", 50, 15),
        Enemy("Orc", 100, 20),
        Enemy("Troll", 200, 30),
        Enemy("Skeleton", 40, 10),
        Enemy("Bandit", 75, 10)
    };

    int enemy_nr;
    int action;

    while (player.is_alive() && enemies.size() != 0)
    {   
        std::cout << "\n";
        player.print_status();

        std::cout << "Choose an enemy to fight against:\n";
        for (int i = 0; i < enemies.size(); i++)
        {
            std::cout << i + 1 << ". ";
            enemies[i].print_status();
        }
        std::cin >> enemy_nr;
        if (enemy_nr >= 1 && enemy_nr <= enemies.size())
        {
            while (player.is_alive() && enemies[enemy_nr - 1].is_alive())
            {
                std::cout << "\nDo you want to:\n"; 
                std::cout << "1. Attack\n";
                std::cout << "2. Heal\n";
                std::cout << "Choose: ";
                std::cin >> action;
                std::cout << "\n";
                if (action >= 1 && action <= 2)
                {
                    if (action == 1)
                    {
                        player.attack_enemy(enemies[enemy_nr - 1]);
                        
                        if (enemies[enemy_nr - 1].is_alive())
                        {
                            enemies[enemy_nr - 1].attack_player(player);
                        }
                    }
                    else if (action == 2)
                    {
                        player.heal(30);
                    }
                }
                else
                {
                    std::cout << "Please choose an available action.\n";
                }
            } 
        }
        else
        {
            std::cout << "Please choose an available action.\n";
        }
        for (int i = enemies.size() - 1; i >= 0; i--)
        {
            if (!enemies[i].is_alive())
            {
                std::cout << "You killed the " << enemies[i].get_name() << "\n";
                enemies.erase(enemies.begin() + i);
            }
        }
    }
    if (!player.is_alive())
    {
        std::cout << "\nYou are dead.\n";
        return 0;
    }
    std::cout << "\nYou defeated all enemies!\n";

    return 0;

    // Challenge -- Think like a programmer
    // 1. It's better since the code becomes easier to read. The object/class handles the action instead of you doing it manually.
    // Because otherwise there's a risk of you making an error etc. Everything becomes more structured and professional.

    // 2. If we make health public, you would be able to change it's value outside of the function which can lead to unforseen errors
    // and issues with the code that you might miss.

    // 3. We separate the definition and declartaion with the purpose of creating a good strucutre and for the class to know how it looks like.

    // 4. CMake is a build system that allows for easier compilation and management of c++ versions along with project files.
}