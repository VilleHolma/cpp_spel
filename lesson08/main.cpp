#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <ctime>
#include <cstdlib>


bool enemy_killed(Player& player, Enemy& enemy)
{   
    if (!enemy.is_alive())
    {   
        std::cout << "You defeated the " << enemy.name << " and earned " << enemy.gold << " gold.\n";
        player.earn_gold(enemy.gold);
        std::cout << "\n\nplayer gold" << player.gold;
        return true;
    }
    return false;
}

int main()
{   
    // Beginning examples
    // Enemy goblin("Goblin", 50, 15);

    // goblin.print_status();

    // goblin.take_damage(20);

    // if (goblin.is_alive())
    // {
    //     std::cout << "The " << goblin.name << "is still alive!\n";
    // }

    // Exercise 1 + 2
    // Player player("Ville", 100, 25);
    
    // player.print_status();

    // player.take_damage(20);

    // player.print_status();

    // player.heal(30);
    
    // player.print_status();

    // if (player.is_alive())
    // {
    //     std::cout << "Player " << player.name << " is still alive!\n";
    // }

    // Exercise 3 -- Multiple classes
    // Player player("Hero", 100, 25);

    // Enemy goblin("Goblin", 50, 15);

    // std::cout << "A " << goblin.name << " appears!\n\n";

    // std::cout << "Player attacks!\n";
    // goblin.take_damage(player.attack);

    // std::cout << "\n" << goblin.name << " attacks!\n";
    // player.take_damage(goblin.attack);

    // std::cout << "Player attacks!\n";
    // goblin.take_damage(player.attack);

    // if (!goblin.is_alive())
    // {
    //     std::cout << goblin.name << " is defeated!\n";
    // }

    // Exercise 4 -- Add a second enemy | Exercise 7 -- Mini-project | Bonus Challenge

    Player player("Hero", 100, 25);

    Enemy goblin("Goblin", 50, 15, 100);
    Enemy orc("Orc", 100, 25, 200);
    Enemy troll("Troll", 200, 30, 250);
    Enemy skeleton("Skeleton", 25, 20, 75);
    Enemy bandit("Bandit", 50, 10, 125);

    std::vector<Enemy> enemies = {goblin, orc, troll, skeleton, bandit};
    int action;
    int enemy_nr;
    srand(time(0));

    while (player.is_alive())
    {
        std::cout << "Choose your action:\n";
        std::cout << "1. Fight\n";
        std::cout << "2. Visit healer\n\n";
        std::cin >> action;
        // Limit between the two available options
        if (action >= 1 && action <= 2)
        {
            if (action == 1)
            {
                // FIGHT
                // Need a new loop for choosing which of the enemies to fight against in the vector
                while (player.is_alive())
                {
                    // Print out the enemies you can choose from
                    std::cout << "Choose an enemy to attack:\n";
                    for (int i = 0; i < enemies.size(); i++)
                    {
                        std::cout << i + 1 << ". ";
                        enemies[i].print_status();
                    }
                    std::cout << enemies.size() + 1 << ". Leave\n";
                    std::cin >> enemy_nr;
                    // Limit between the available enemies to fight against
                    if (enemy_nr >= 1 && enemy_nr <= enemies.size() + 1)
                    {   
                        if (enemy_nr == enemies.size() + 1)
                        {
                            break;
                        }
                        else
                        {
                            // A final loop to handle the actual fighting mechanics
                            while (player.is_alive())
                            {
                                std::cout << "You are fighting the " << enemies[enemy_nr - 1].name << ".\n";
                                std::cout << "Player health: " << player.health << "\n\n";
                                std::cout << enemies[enemy_nr - 1].name << " health: " << enemies[enemy_nr - 1].health << "\n\n";
                                // Choose between different actions against the enemy:
                                std::cout << "\nChoose your action:\n";
                                std::cout << "1. Attack\n";
                                std::cout << "2. Block\n";
                                std::cout << "3. Heal\n";
                                std::cout << "4. Run\n\n";
                                std::cin >> action;
                            
                                // Limit betweent the available actions in the fight:
                                if (action >= 1 && action <= 4)
                                {
                                    // ATTACK
                                    if (action == 1)
                                    {
                                        int crit_chance = rand() % 101;
                                        bool killed;
                                        // CRITICAL ATTACK
                                        if (crit_chance >= 75)
                                        {
                                            std::cout << "Critical attack!\n\n";
                                            std::cout << "You deal " << player.attack * 2 << " damage.\n\n";
                                            enemies[enemy_nr - 1].take_damage(player.attack * 2);
                                        
                                            if (enemy_killed(player, enemies[enemy_nr - 1]))
                                            {
                                                enemies.erase(enemies.begin() + enemy_nr - 1);
                                                break;
                                            }
                                            
                                        }
                                        // REGULAR ATTACK
                                        else
                                        {
                                            std::cout << "You attack!\n\n";
                                            std::cout << "You deal " << player.attack << " damage.\n\n";
                                            enemies[enemy_nr - 1].take_damage(player.attack);

                                            if (enemy_killed(player, enemies[enemy_nr - 1]))
                                            {
                                                enemies.erase(enemies.begin() + enemy_nr - 1);
                                                break;
                                            }
                                            
                                        }
                                        // THE ENEMY FIGHTS BACK
                                        std::cout << "The " << enemies[enemy_nr - 1].name << " attacks.\n\n";
                                        player.take_damage(enemies[enemy_nr - 1].attack);
                                        // CHECK IF PLAYER IS DEAD
                                        if (!player.is_alive())
                                        {
                                            std::cout << "You are dead.\n";
                                        }
                                    }
                                    // BLOCK
                                    else if (action == 2)
                                    {
                                        std::cout << "You blocked the enemy attack.\n";
                                    }
                                    // HEAL
                                    else if (action == 3)
                                    {
                                        player.heal(50);
                                        std::cout << "The " << enemies[enemy_nr - 1].name << " attacks.\n\n";
                                        player.take_damage(enemies[enemy_nr - 1].attack);
                                        // CHECK IF PLAYER IS DEAD
                                        if (!player.is_alive())
                                        {
                                            std::cout << "You are dead.\n";
                                        }
                                    }
                                    // RUN
                                    else if (action == 4)
                                    {
                                        int flee_chance = rand() % 101;
                                        if (flee_chance >= 50)
                                        {
                                            std::cout << "You run away!\n";
                                            break;
                                        }
                                        else
                                        {
                                            std::cout << "You failed to escape!\n";
                                            std::cout << "The " << enemies[enemy_nr - 1].name << " attacks.\n\n";
                                            player.take_damage(enemies[enemy_nr - 1].attack);
                                            // CHECK IF PLAYER IS DEAD
                                            if (!player.is_alive())
                                            {
                                                std::cout << "You are dead.\n";
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    std::cout << "Please enter a valid number.\n";
                                } 
                            }
                        }
                    }
                    else
                    {
                        std::cout << "Please enter a valid number.\n";
                    }
                }
            }
            
            else
            {
                std::cout << "Player gold: " << player.gold << "\n";
                std::cout << "It costs 100 gold to be fully healed.\n";
                std::cout << "Do you want to be healed?\n";
                std::cout << "1. Yes\n";
                std::cout << "2. No\n\n";
                std::cin >> action;
                if (action >= 1 && action <= 2)
                {   
                    if (action == 1 && player.gold < 100)
                    {
                        std::cout << "\nYou don't have enough gold.\n";
                    }
                    else if (action == 1 && player.health == 100)
                    {
                        std::cout << "\nYou are already at full health.\n";
                    }
                    else if (action == 1 && player.gold >= 100)
                    {
                        player.health = 100;
                        player.gold -= 100;
                    }
                }
            }

        }
        else
        {
            std::cout << "Please enter a valid number.\n";
        }
        
        // if (action >= 1 && action <= enemies.size())
        // {
        //     enemies[action - 1].take_damage(30);
        //     for (int i = enemies.size() -1; i >= 0; i--)
        //     {
        //         if(!enemies[i].is_alive())
        //         {
        //             std::cout << "\nYou defeated the " << enemies[i].name << "!\n";
        //             enemies.erase(enemies.begin() + i);
        //         }
        //     }
        // }
        // else
        // {
        //     std::cout << "Please enter a valid number.\n";   
        // }
        // if (enemies.empty())
        // {
        //     std::cout << "You defeated all enemies!\n";
        //     break;
        // }
             
    }

    // Exercise 5 -- The important experiment
    // clang++: error: linker command failed with exit code 1 (use -v to see invocation)

    // Exercise 6 -- Break it deliberately
    // a)
    // error: unknown type name 'Enemy'
    // error: use of undeclared identifier 'Enemy'
    // b)
    // error: linker command failed with exit code 1 (use -v to see invocation)
    // c)
    // error: out-of-line definition of 'take_damage' does not match any declaration in 'Player'




    return 0;
}