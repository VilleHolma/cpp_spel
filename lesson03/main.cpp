#include <iostream>
#include <string>

int main()
{   
    // Exercise 1
    // std::string name;
    // int age;
    // int fav_number;

    // std::cout << "What is your name? " << std::endl;
    // std::cin >> name;
    // std::cout << "What is your age? " << std::endl;
    // std::cin >> age;
    // std::cout << "What is your favorite number? " << std::endl;
    // std::cin >> fav_number;

    // std::cout << "Hello " << name << "!\n";
    // std::cout << "You are " << age << " years old.\n";
    // std::cout << "Your favorite number is " << fav_number << ".\n";

    // Exercise 2
    // std::string full_name;
    // std::cout << "What is your full name? ";
    // std::getline(std::cin, full_name);
    // std::cout << "Hello " << full_name << ".\n";

    // Exercise 3
    // int health;
    // int damage1;
    // int damage2;

    // std::cout << "What is your health? ";
    // std::cin >> health;
    // std::cout << "Attack 1: How much damage did you take? ";
    // std::cin >> damage1;
    // std::cout << "Attack 2: How much damage did you take? ";
    // std::cin >> damage2;

    // std::cout << "Health: " << health << std::endl;
    // std::cout << "Attack 1 damage: " << damage1 << std::endl;
    // health -= damage1;
    // std::cout << "Attack 2 damage: " << damage2 << std::endl;
    // health -= damage2;
    // std::cout << "\nRemaining health: " << health << std::endl;
    
    // Exercise 4
    // int health;
    // std::cout << "What is your health? " << std::endl;
    // std::cin >> health;

    // if (health > 0)
    // {
    //     std::cout << "You are alive!" << std::endl;
    //     if (health > 75)
    //     {
    //         std::cout << "You are in great shape!" << std::endl;
    //     }
    //     else if (health > 25)
    //     {
    //         std::cout << "You are injured." << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "You are critically wounded!" << std::endl;
    //     }
    // }
    // else
    // {
    //     std::cout << "Your are dead!" << std::endl;
    // }

    // Exercise 5 -- Character creation
    // std::string name;
    // int age;
    // int health;
    // int attack;
    
    // std::cout << "Are you strong enough to enter the dungeon?\n"; 
    // std::cout << "What is your name? " << std::endl;
    // std::cin >> name;
    // std::cout << "What is your age? " << std::endl;
    // std::cin >> age;
    // std::cout << "What is your health? " << std::endl;
    // std::cin >> health;
    // std::cout << "What is your attack? " << std::endl;
    // std::cin >> attack;

    // if (health >= 50 && attack >= 20)
    // {
    //     std::cout << "Welcome to the dungeon, " << name << "!\n";
    //     std::cout << "You are strong enough to enter." << std::endl;
    // }
    // else
    // {
    //     std::cout << "Sorry " << name << ", you are not strong enough.\n";
    // }

    // Exercise 6 -- First combat encounter
    // int player_health;
    // int player_attack;
    // int enemy_health;
    // int action;
    
    // std::cout << "What is your health? " << std::endl;
    // std::cin >> player_health;
    // std::cout << "What is your attack? " << std::endl;
    // std::cin >> player_attack;
    // std::cout << "What is the goblins health? " << std::endl;
    // std::cin >> enemy_health;

    // std::cout << "\n\nA goblin appears!\n\n";
    // std::cout << "What do you do?\n\n";
    // std::cout << "1. Attack\n";
    // std::cout << "2. Run\n";
    // std::cout << "3. Inspect\n";
    // std::cin >> action;

    // if (action == 1)
    // {
    //     std::cout << "You attack the goblin!\n";
    //     enemy_health -= player_attack;
    //     std::cout << "Goblin health: " << enemy_health << std::endl;
    //     if (enemy_health <= 0)
    //     {
    //         std::cout << "You defeated the goblin!" << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "The goblin is still standing!" << std::endl;
    //     }
    // }
    // else if (action == 2)
    // {
    //     std::cout << "You ran away!" << std::endl;
    // }
    // else if (action == 3)
    // {
    //     std::cout << "The goblin looks angry." << std::endl;
    // }

    // Exercise 7 -- Customize the encounter

    // int player_health = 200;
    // int player_attack = 40;
    // std::string enemy_name = "Troll";
    // int enemy_health = 50;
    // int enemy_attack = 1000;
    // int action;

    // std::cout << "\n\nA " << enemy_name << " appears!\n\n";
    // std::cout << "What do you do?\n\n";
    // std::cout << "1. Attack\n";
    // std::cout << "2. Run\n";
    // std::cout << "3. Inspect\n";
    // std::cout << "4. Taunt\n";
    // std::cin >> action;

    // if (action == 1)
    // {
    //     std::cout << "You attack the "<< enemy_name <<"!\n";
    //     enemy_health -= player_attack;
    //     std::cout << enemy_name << " health: " << enemy_health << std::endl;
    //     if (enemy_health <= 0)
    //     {
    //         std::cout << "You defeated the " << enemy_name << "!\n";
    //     }
    //     else
    //     {
    //         std::cout << "The " << enemy_name << " is still standing!\n";
    //     }
    // }
    // else if (action == 2)
    // {
    //     std::cout << "You ran away!" << std::endl;
    // }
    // else if (action == 3)
    // {
    //     std::cout << "The " << enemy_name << " looks angry.\n";
    // }
    // else if (action == 4)
    // {
    //     std::cout << "The " << enemy_name << " attacks!\n";
    //     player_health -= enemy_attack;
    //     if (player_health <= 0)
    //     {
    //         std::cout << "Your are dead!" << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "Your health: " << player_health << std::endl;
    //     }
    // }

    // Challenge -- Branching paths

    int action;

    std::cout << "You wake up in a dark forest.\n\n";
    std::cout << "There are two paths.\n\n";
    std::cout << "1. Take the left path\n";
    std::cout << "2. Take the right path\n";
    std::cin >> action;
    
    if (action == 1)
    {
        std::cout << "Your reach a cabin.\n\n";
        std::cout << "Do you: \n";
        std::cout << "1. Enter\n";
        std::cout << "2. Leave\n";
        std::cin >> action;
        if (action == 1)
        {
            std::cout << "You enter the cabin.\n";
        }
        else if (action == 2)
        {
            std::cout << "You leave the cabin\n";
        }
    }
    else if (action == 2)
    {
        std::cout << "Your reach a river.\n\n";
        std::cout << "Do you: \n";
        std::cout << "1. Swim\n";
        std::cout << "2. Follow\n";
        std::cin >> action;

        if (action == 1)
        {
            std::cout << "You are dragged away fighting against stream.\n";
        }
        else if (action == 2)
        {
            std::cout << "You follow the river saftely\n";
        }
    }
}