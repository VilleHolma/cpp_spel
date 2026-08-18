#include <iostream>
#include <string>
#include <vector>

bool is_alive(int health)
{
    return health > 0;
}

int main()
{
    // Exercise 1 -- Your first array
    // int enemy_health[5] = {100, 75, 50, 120, 200};
    // std::cout << enemy_health[0] << std::endl;
    // std::cout << enemy_health[1] << std::endl;
    // std::cout << enemy_health[2] << std::endl;
    // std::cout << enemy_health[3] << std::endl;
    // std::cout << enemy_health[4] << std::endl;
    // Change the health of the third enemy from 50 -> 75
    // enemy_health[2] = 75;
    // std::cout << enemy_health[2] << std::endl;

    // Exercise 2 -- Enemy health system
    // for (int i = 0; i < sizeof(enemy_health) / sizeof(enemy_health[0]); i++)
    // {
    //     std::cout << "Enemy " << i + 1 << " health: "<< enemy_health[i] << std::endl;
    //     enemy_health[i] -= 20;
    //     std::cout << "Enemy " << i + 1 << " health: "<< enemy_health[i] << std::endl;
    // }

    // Exercise 3 -- Enemy roster
    // std::string enemy_names[3] = {"Goblin", "Orc", "Troll"};
    // int enemy_health[3] = {50, 100, 200};
    // int enemy_attack_power[3] = {15, 25, 30};
    // std::cout << "Before:\n";
    // for (int i = 0; i < sizeof(enemy_names) / sizeof(enemy_names[0]); i++)
    // {
    //     std::cout << enemy_names[i] << " - HP: " << enemy_health[i] << " - Attack: " << enemy_attack_power[i] << std::endl;
    //     // Deal 10 damage to every enemy
    //     enemy_health[i] -= 10;
    // }
    // std::cout << "After:\n";
    // for (int i = 0; i < sizeof(enemy_names) / sizeof(enemy_names[0]); i++)
    // {
    //     std::cout << enemy_names[i] << " - HP: " << enemy_health[i] << " - Attack: " << enemy_attack_power[i] << std::endl;
    // }

    // Exercise 4 -- Inventory
    // std::vector<std::string> inventory;
    // inventory.push_back("Sword");
    // inventory.push_back("Shield");
    // inventory.push_back("Potion");
    // inventory.push_back("Key");
    // std::cout << "Inventory:\n";
    // for (int i = 0; i < inventory.size(); i++)
    // {
    //     std::cout << " - " << inventory[i] << std::endl;
    // }
    
    // return 0;

    // Exercise 5 -- Dynamic inventory
    // int items;
    // std::string item;
    // std::vector<std::string> inventory;
    // std::cout << "How many items do you want to add? ";
    // std::cin >> items;
    // for (int i = 0; i < items; i++)
    // {
    //     std::cout << "\nEnter item: ";
    //     std::cin >> item;
    //     inventory.push_back(item);
    // }
    // std::cout << "Inventory:\n";
    // for (int i = 0; i < inventory.size(); i++)
    // {
    //     std::cout << " - " << inventory[i] << std::endl;
    // }
    
    // Exercise 6 -- Inventory management
    // std::vector<std::string> inventory = {"Sword", "Potion", "Shield", "Key"};
    
    // std::cout << "\nInitial:\n";
    // for (int i = 0; i < inventory.size(); i++)
    // {
    //     std::cout << " - " << inventory[i] << std::endl;
    // }
    // inventory.pop_back();
    // std::cout << "\nAfter removing:\n";
    // for (int i = 0; i < inventory.size(); i++)
    // {
    //     std::cout << " - " << inventory[i] << std::endl;
    // }
    // inventory.push_back("Map");
    // std::cout << "\nAfter adding:\n";
    // for (int i = 0; i < inventory.size(); i++)
    // {
    //     std::cout << " - " << inventory[i] << std::endl;
    // }

    // Exercise 7 -- Two kinds of loops
    // std::vector<std::string> inventory = {"Sword", "Potion", "Shield", "Key"};
    // std::cout << "\nIndex-based:\n";
    // for (int i = 0; i < inventory.size(); i++)
    // {
    //     std::cout << " - " << inventory[i] << std::endl;
    // }
    // std::cout << "\nRange-based:\n";
    // for (std::string item : inventory)
    // {
    //     std::cout << " - " << item << std::endl;
    // }

    // Challenge 1 & 2
    std::vector<std::string> enemies = {"Goblin", "Orc", "Troll", "Skeleton", "Bandit"};
    std::vector<int> health = {50, 100, 150, 25, 50};
    std::vector<int> attack = {15, 25, 30, 5, 10};
    int action;

    while (true)
    {
        std::cout << "Choose an enemy to attack:\n";
        for (int i = 0; i < enemies.size(); i++)
        {
            std::cout << i + 1 << ". " << enemies[i] << std::endl;
            std::cout << "    Health: " << health[i] << std::endl;
            std::cout << "    Attack: " << attack[i] << std::endl;
        }
        std::cin >> action;
        if (action >= 1 && action <= enemies.size())
        {
            health[action-1] -= attack[action-1];
            for (int i =  health.size() - 1; i >= 0; i--)
            {
                if (!is_alive(health[i]))
                {
                    std::cout << "\nYou defeated the " << enemies[i] << "!\n";
                    enemies.erase(enemies.begin() + i);
                    health.erase(health.begin() + i);
                    attack.erase(attack.begin() + i);
                }
            }
        }
        else
        {
            std::cout << "Please enter a valid number.\n";
        }
        if (enemies.empty())
        {
        std::cout << "You defeated all enemies!\n";
        break;
        }
    }
}