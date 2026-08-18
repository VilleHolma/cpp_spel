#include <iostream>
#include <string>

void greet_player()
{
    std::cout << "Welcome to the game!" << std::endl;
}

void show_intro()
{
    std::cout << "You wake up in a dark forest..." << std::endl;
}

void show_goodbye()
{
    std::cout << "Good luck!" << std::endl;
}

void print_player(std::string name, int health, int gold)
{
    std::cout << "Player: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Gold: " << gold << std::endl;
}

void player_attack(int& enemy_health, int damage)
{   
    // Old: (std::string enemy, int damage)
    // std::cout << "Player attacks " << enemy << " for "
    //           << damage << " damage!"
    //           << std::endl;
    // New:
    std::cout << "You deal " << damage << " damage." << std::endl;
    enemy_health -= damage;
}

void enemy_attack(std::string enemy_name, int& player_health, int damage)
{
    // Old: (std::string enemy, int damage)
    // std::cout << enemy << " attacks Player for "
    //           << damage << " damage!"
    //           << std::endl;
    // New:
    std::cout << "\nThe " << enemy_name << " attacks!" << std::endl;
    std::cout << "You take " << damage << " damage.\n\n";
    player_health -= damage;
    
}

void heal_player(int heal)
{
    std::cout << "Player heals for "
              << heal << " health!"
              << std::endl;
}

int calculate_damage(int attack, int defense)
{
    if (attack > defense)
    {
        return attack - defense;
    }
    else
    {
        return 0;
    }
    
}

bool is_alive(int health)
{
    return health > 0;
}

bool is_dead(int health)
{
    return health <= 0;
}

bool can_heal(int potions)
{
    return potions > 0;
}

void take_damage(int& health, int damage)
{
    health -= damage;
}

void heal(int& health, int amount)
{   
    int old_health = health;
    health += amount;
    if (health >= 100)
    {
        health = 100;
    }
    std::cout << "You drink a potion and recover " << health - old_health << " health!" << std::endl;
}

void show_status(int player_health, int enemy_health, std::string enemy_name)
{
    std::cout << "Player health: " << player_health << std::endl;
    std::cout << enemy_name << " health: " << enemy_health << std::endl;
}

void enemy_defeated(std::string enemy_name, int& gold, int enemy_gold)
{
    std::cout << enemy_name << " defeated!" << std::endl;
    gold += enemy_gold;
    std::cout << "You pick up " << enemy_gold << " gold pieces." << std::endl;
}

void enemy_status(int& enemy_health, std::string& enemy_name, int& enemy_attack_power, int& gold, int enemy_gold)
{
    if (is_dead(enemy_health) && enemy_name == "Goblin")
    {
        enemy_defeated(enemy_name, gold, enemy_gold);
        enemy_name = "Orc";
        enemy_health = 100;
        enemy_attack_power = 25;
    }
    else if (is_dead(enemy_health) && enemy_name == "Orc")
    {
        enemy_defeated(enemy_name, gold, enemy_gold);
        enemy_name = "Troll";
        enemy_health = 200;
        enemy_attack_power = 30;
    }
}

int main()
{
    // Exercise 1 - Your first functions
    // greet_player();
    // show_intro();
    // show_goodbye();

    // Exercise 2 -- Player information
    // print_player("Alex", 100, 50);
    // print_player("Bob", 75, 120);
    // print_player("Sarah", 30, 5);

    // Exercise 3 -- Combat functions
    // player_attack("Goblin", 10);
    // enemy_attack("Goblin", 5);
    // heal_player(50);

    // Exercise 4 -- Damage calculation
    // int damage = calculate_damage(1, 20);
    // std::cout << "Damage: " << damage << std::endl;

    // Exercise 5 -- Game-state functions
    // int health = 50;

    // if (is_alive(health))
    // {
    //     std::cout << "Player is alive!" << std::endl;
    // }
    // health = 0;
    // if (is_dead(health))
    // {
    //     std::cout << "Player is dead!" << std::endl;
    // }
    // int potions = 5;
    // if (can_heal(potions))
    // {
    //     std::cout << "Player can heal!" << std::endl;
    // }
    // return 0;

    // Exercise 6 -- Modify game state
    // int health = 100;
    // take_damage(health, 30);
    // heal(health, 20);
    // std::cout << health << std::endl;

    // Exercise 7 -- Mini combat system
    // int player_health = 100;
    // int player_attack_power = 30;
    
    // int enemy_health = 100;
    // int enemy_attack_power = 15;
    
    // int action = 1;

    // while (is_alive(player_health) && is_alive(enemy_health))
    // {
    //     show_status(player_health, enemy_health);
    //     std::cout << "\nChoose your action:\n";
    //     std::cout << "1. Attack\n\n";
    //     std::cin >> action;
    //     if (action == 1)
    //     {
    //         player_attack(enemy_health, player_attack_power);
            
    //         if (is_alive(enemy_health))
    //         {
    //             enemy_attack(player_health, enemy_attack_power);
    //         }
    //     }
        

    // }
    // Challenge
    int player_health = 100;
    int player_attack_power = 30;
    int potions = 3;
    int gold = 20;
    int action;
    // use rand, srand, and time to get critical hits
    srand(time(0)); // Get a different random number each time the program runs

    std::string enemy_name = "Goblin";
    int enemy_health = 50;
    int enemy_attack_power = 15;
    int enemy_gold = 100;
    bool enemy_was_defeated = false;

    while (is_alive(player_health) && is_alive(enemy_health))
    {
        show_status(player_health, enemy_health, enemy_name);
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
                player_attack(enemy_health, player_attack_power*2);
                enemy_was_defeated = is_dead(enemy_health);
                enemy_status(enemy_health, enemy_name, enemy_attack_power, gold, enemy_gold);
                
                if (is_dead(enemy_health) && enemy_name == "Troll")
                {
                    enemy_defeated(enemy_name, gold, enemy_gold);
                    break;
                }
            }
            else
            {
                std::cout << "\n\nYou attack!" << std::endl;
                player_attack(enemy_health, player_attack_power);
                enemy_was_defeated = is_dead(enemy_health);
                enemy_status(enemy_health, enemy_name, enemy_attack_power, gold, enemy_gold);
                if (is_dead(enemy_health) && enemy_name == "Troll")
                {
                    enemy_defeated(enemy_name, gold, enemy_gold);
                    break;
                }
            }
            if (!enemy_was_defeated)
            {
            enemy_attack(enemy_name, player_health, enemy_attack_power);
            }
            if (is_dead(player_health))
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
                
                enemy_attack(enemy_name, player_health, enemy_attack_power);
                if (is_dead(player_health))
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
                heal(player_health, 30);
                
            }
            enemy_attack(enemy_name, player_health, enemy_attack_power);
            if (is_dead(player_health))
                {
                    std::cout << "You are dead." << std::endl;
                }
        }
    }

    return 0;
}