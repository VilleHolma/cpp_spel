#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
    // Exercise 1 -- Counting

    // int i = 10;
    // while (i > 0)
    // {
    //     std::cout << i << std::endl;
    //     i--;
    // }

    // Exercise 2 -- Find the bug
    // int health = 100;

    // while (health > 0)
    // {
    //     std::cout << "Health: " << health << std::endl;
    //     health -= 10; // Added this line of code
    // }

    // Exercise 3 -- Password
    // std::string password = "secret";
    // std::string input;

    // while (input != password)
    // {
    //     std::cout << "Enter password: " << std::endl;
    //     std::cin >> input;
    // }
    // std::cout << "Access granted!" << std::endl;

    // Exercise 4 -- Menu
    // int action;
    // while (true)
    // {   
    //     std::cout << "===== MENU =====\n\n"
    //               << "1. Start game\n"
    //               << "2. Settings\n"
    //               << "3. Quit\n\n"
    //               << "Choose: ";

    //     std::cin >> action;
    //     if (action == 1)
    //     {
    //         std::cout << "Starting game..." << std::endl;
    //     }
    //     else if (action == 2)
    //     {
    //         std::cout << "Opening settings..." << std::endl;
    //     }
    //     else if (action == 3)
    //     {
    //         std::cout << "Goodbye!" << std::endl;
    //         break;
    //     }
    //     else
    //     {
    //         std::cout << "Choose one of the three options." << std::endl;
    //     }

    // }

    // Exercise 5 -- for-loop practicee
    // int i;
    // for (i = 2; i <=10; i+=2)
    // {
    //     std::cout << i << std::endl;
    // }
    // // Challenge
    // for (i = 10; i>=1; i--)
    // {
    //     std::cout << i << std::endl;
    // }

    // Exercise 6/7/8/Challenge
    int player_health = 100;
    int player_attack = 30;
    int potions = 3;
    int gold = 20;
    int action;
    // use rand, srand, and time to get critical hits
    srand(time(0)); // Get a different random number each time the program runs

    std::string enemy_name = "Goblin";
    int enemy_health = 50;
    int enemy_attack = 15;
    int enemy_gold = 100;

    while (player_health > 0 && enemy_health > 0)
    {
        std::cout << "Player health: " << player_health << std::endl;
        std::cout << enemy_name << " health: " << enemy_health << std::endl;
        std::cout << "\nChoose your action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Block\n";
        std::cout << "3. Run\n";
        std::cout << "4. Heal\n\n";
        std::cin >> action;
        if (action == 1)
        {   
            int crit_chance = rand() % 101;
            if (crit_chance >= 75)
            {
                std::cout << "\n\nCritical attack!" << std::endl;
                std::cout << "You deal " << player_attack*2 << " damage." << std::endl;
                enemy_health -= 2*player_attack;
                if (enemy_health <= 0 && enemy_name == "Goblin")
                {
                    std::cout << enemy_name << " defeated!" << std::endl;
                    gold += enemy_gold;
                    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
                    enemy_name = "Orc";
                    enemy_health = 100;
                    enemy_attack = 25;
                }
                else if (enemy_health <= 0 && enemy_name == "Orc")
                {
                    std::cout << enemy_name << " defeated!" << std::endl;
                    gold += enemy_gold;
                    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
                    enemy_name = "Troll";
                    enemy_health = 200;
                    enemy_attack = 30;
                }
                else if (enemy_health <= 0 && enemy_name == "Troll")
                {
                    std::cout << enemy_name << " defeated!" << std::endl;
                    gold += enemy_gold;
                    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "\n\nYou attack!" << std::endl;
                std::cout << "You deal " << player_attack << " damage." << std::endl;
                enemy_health -= player_attack;
                if (enemy_health <= 0 && enemy_name == "Goblin")
                {
                    std::cout << enemy_name << " defeated!" << std::endl;
                    gold += enemy_gold;
                    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
                    enemy_name = "Orc";
                    enemy_health = 100;
                    enemy_attack = 25;
                }
                else if (enemy_health <= 0 && enemy_name == "Orc")
                {
                    std::cout << enemy_name << " defeated!" << std::endl;
                    gold += enemy_gold;
                    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
                    enemy_name = "Troll";
                    enemy_health = 200;
                    enemy_attack = 30;
                }
                else if (enemy_health <= 0 && enemy_name == "Troll")
                {
                    std::cout << enemy_name << " defeated!" << std::endl;
                    gold += enemy_gold;
                    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
                    break;
                }
            }
            std::cout << "\nThe " << enemy_name << " attacks!" << std::endl;
            player_health -= enemy_attack;
            std::cout << "You take " << enemy_attack << " damage.\n\n";
            if (player_health <= 0)
            {
                std::cout << "You are dead." << std::endl;
            }
        }
        else if (action == 2)
        {
            std::cout << "You blocked the enemy attack." << std::endl;
        }
        else if (action == 3)
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
                std::cout << "\nThe " << enemy_name << " attacks!" << std::endl;
                player_health -= enemy_attack;
                std::cout << "You take " << enemy_attack << " damage.\n\n";
                if (player_health <= 0)
                {
                    std::cout << "You are dead." << std::endl;
                }
            }
            
        }
        else if (action == 4)
        {
            if (potions == 0)
            {
                std::cout << "You are out of potions!" << std::endl;
            }
            else
            {
                potions--;
                player_health += 30;
                int healed = 30;
                if (player_health > 100)
                {
                    healed = 30 - (player_health - 100);
                    player_health = 100;   
                }
                
                std::cout << "You drink a potion and recover " << healed << " health!" << std::endl;
            }
            std::cout << "\nThe " << enemy_name << " attacks!" << std::endl;
            player_health -= enemy_attack;
            std::cout << "You take " << enemy_attack << " damage.\n\n";
            if (player_health <= 0)
                {
                    std::cout << "You are dead." << std::endl;
                }
        }
        
    }

    return 0;
}