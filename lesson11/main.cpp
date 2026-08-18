#include <iostream>
#include "enemy.h"
#include "player.h"
#include <vector>

int main()
{
    // Exercise 1 -- Create an enemy
    // Player player("Ville", 100, 30);
    // Enemy goblin("Goblin", 100, 20);

    // std::cout << goblin.get_name() << std::endl;
    // std::cout << goblin.get_health() << std::endl;

    // Exercise 2 -- Make them interact
    // goblin.attack_player(player);
    // std::cout << "Player health: "
    //       << player.get_health()
    //       << "\n";

    // Exercise 3 -- Player attacks Enemy
    // player.attack_enemy(goblin);
    // std::cout << "Enemy health: "
    //           << goblin.get_health()
    //           << "\n";

    // Exercise 4 -- Build a combat loop
    // Player player("Ville", 100, 30);
    // Enemy goblin("Goblin", 50, 15);

    // int action;

    // while (player.is_alive() && goblin.is_alive())
    // {
    //     player.print_status();

    //     std::cout << "Enemy: "
    //               << goblin.get_name()
    //               << " (" << goblin.get_health()
    //               << " HP)\n\n";

    //     std::cout << "1. Attack\n";
    //     std::cout << "2. Heal\n";
    //     std::cout << "Choose: ";

    //     std::cin >> action;

    //     if (action >= 1 && action <= 2)
    //     {
    //         if (action == 1)
    //         {
    //             player.attack_enemy(goblin);
                
    //             if (goblin.is_alive())
    //             {
    //                 goblin.attack_player(player);
    //             }
    //         }
    //         else if (action == 2)
    //         {
    //             player.heal(30);

    //             if (goblin.is_alive())
    //             {
    //                 goblin.attack_player(player);
    //             }
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "Please choose an available action.\n";
    //     }
    // }
    // if (!player.is_alive())
    // {
    //     std::cout << "You were defeated!\n";
    // }
    // else
    // {
    //     std::cout << "You defeated the goblin!\n";
    // }

    // Challenge -- Multiple enemies
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
}