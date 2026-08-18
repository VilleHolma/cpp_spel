#include <iostream>
#include <string>
#include <vector>

class Enemy
{
public:
    std::string name;
    int health;
    int attack;

    Enemy(std::string enemy_name, int enemy_health, int enemy_attack)
    {
        name = enemy_name;
        health = enemy_health;
        attack = enemy_attack;
    }

    void take_damage(int damage)
    {
        health -= damage;
        std::cout << name << " takes " << damage << " damage.\n\n";
    }
    bool is_alive()
    {
        return health > 0;
    }
    void print_status()
    {
        std::cout << ". "<< name << std::endl;
        std::cout << "   Health:" << health << std::endl;
        std::cout << "   Attack:" << attack << "\n\n";
    }
};

int main()
{
    // Exercise 1 -- Your first class
    // Enemy goblin;
    // goblin.name = "Goblin";
    // goblin.health = 50;
    // goblin.attack = 15;
    // std::cout << goblin.name << std::endl;
    // std::cout << "Health: " << goblin.health << std::endl;
    // std::cout << "Attack: " << goblin.attack << std::endl;

    // Exercise 2 -- Multiple objects
    // Enemy orc;
    // orc.name = "Orc";
    // orc.health = 100;
    // orc.attack = 25;
    // std::cout << orc.name << std::endl;
    // std::cout << "Health: " << orc.health << std::endl;
    // std::cout << "Attack: " << orc.attack << std::endl;

    // Enemy troll;
    // troll.name = "Troll";
    // troll.health = 200;
    // troll.attack = 25;
    // std::cout << troll.name << std::endl;
    // std::cout << "Health: " << troll.health << std::endl;
    // std::cout << "Attack: " << troll.attack << std::endl;
    
    // Exercise 3 -- take damage
    // std::cout << "Before taking damage: " << std::endl;
    // std::cout << "Health: " << goblin.health << std::endl;
    // goblin.take_damage(20);
    // std::cout << "After taking damage: " << std::endl;
    // std::cout << "Health: " << goblin.health << std::endl;

    // Exercise 4 -- is alive
    // if (goblin.is_alive())
    // {
    //     std::cout << "The goblin is still alive!\n" << std::endl;
    // }
    // goblin.take_damage(50);
    // std::cout << "You attack the goblin with 50 damage\n" << std::endl;

    // if (!goblin.is_alive())
    // {
    //     std::cout << "The goblin has been defeated!" << std::endl;
    // }

    // Exercise 5 -- Your first constructor
    // Enemy goblin("Goblin", 50, 15);

    // Exercise 6 -- Constructor + combat

    // std::cout << "A " << goblin.name << " appears!\n\n";

    // while (true)
    // {
    //     goblin.show_status();

    //     std::cout << "You attack!\n\n";

    //     goblin.take_damage(30);

    //     if (!goblin.is_alive())
    //     {
    //         std::cout << goblin.name << " is defeated.\n";
    //         break;
    //     }
    // }

    // return 0;

    // Exercise 7 -- Enemy vector
    // std::vector<Enemy> enemies;

    // enemies.push_back(Enemy("Goblin", 50, 15));
    // enemies.push_back(Enemy("Orc", 100, 25));
    // enemies.push_back(Enemy("Troll", 200, 30));
    // enemies.push_back(Enemy("Skeleton", 25, 20));
    // enemies.push_back(Enemy("Bandit", 50, 10));
    
    // for (int i = 0; i < enemies.size(); i++)
    // {
    //     std::cout << i + 1 << ". "<< enemies[i].name << std::endl;
    //     std::cout << "   Health:" << enemies[i].health << std::endl;
    //     std::cout << "   Attack:" << enemies[i].attack << "\n\n";
    // }

    // Challenge
    std::vector<Enemy> enemies;

    enemies.push_back(Enemy("Goblin", 50, 15));
    enemies.push_back(Enemy("Orc", 100, 25));
    enemies.push_back(Enemy("Troll", 200, 30));
    enemies.push_back(Enemy("Skeleton", 25, 20));
    enemies.push_back(Enemy("Bandit", 50, 10));
    
    int action;
    
    while (true)
    {
        std::cout << "Choose an enemy to attack:\n";
        for (int i = 0; i < enemies.size(); i++)
        {
            std::cout << i + 1;
            enemies[i].print_status();
        }
        std::cin >> action;
        if (action >= 1 && action <= enemies.size())
        {
            enemies[action - 1].take_damage(30);
            for (int i = enemies.size() -1; i >= 0; i--)
            {
                if(!enemies[i].is_alive())
                {
                    std::cout << "\nYou defeated the " << enemies[i].name << "!\n";
                    enemies.erase(enemies.begin() + i);
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