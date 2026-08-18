#include <iostream>
#include "Player.h"

void damage_by_value(int health)
{
    health -= 20;
}

void damage_by_reference(int& health)
{
    health -= 20;
}

void give_gold(Player& player, int amount)
{
    player.earn_gold(amount);
}

void damage(int* health, int amount)
{
    // takes in pointer to "player_health"
    if (health == nullptr)
    {
        std::cout << "Health is empty." << std::endl;
        return;
    }
    // Change the actual value of the variable
    *health -= amount;
}

void damage_by_reference2(int& health, int amount)
{
    health -= amount;
}

void damage_by_pointer(int* health, int amount)
{
    if (health == nullptr)
    {
        std::cout << "Health is empty." << std::endl;
        return;
    }
    // Change the actual value of the variable
    *health -= amount;
}

int main()
{
    // Exercise 1 -- Addresses
    // int health = 100;
    // int gold = 500;
    // int attack = 30;

    // std::cout << "Health: " << health << std::endl;
    // std::cout << "Health address: " << &health << std::endl;

    // std::cout << "Gold: " << gold << std::endl;
    // std::cout << "Golg address: " << &gold << std::endl;

    // std::cout << "Attack: " << attack << std::endl;
    // std::cout << "Attack address: " << &attack << std::endl;

    // The addresses are slightly similar, but ultimately different in the end. 
    // It's logical that they have different addresses, otherwise they would overwrite each other if they were the same.
    // I guess that them being similar is due to them all sharing the same type. 

    // Exercise 2 -- Reference experiment
    // int gold = 100;
    // int& gold_reference = gold;

    // std::cout << gold << std::endl;
    // std::cout << gold_reference << std::endl;

    // gold_reference = 500;

    // std::cout << gold << std::endl;
    // std::cout << gold_reference << std::endl;

    // gold = 1000;

    // std::cout << gold << std::endl;
    // std::cout << gold_reference << std::endl;

    // gold_reference is another name for gold as they reference the same variable.
    // It isn't a separate variable containing a copy of gold, which is shown when changing its value gold also changes.

    // Exercise 3 -- Pass by value vs reference
    // int player_health = 100;
    // damage_by_value(player_health);
    // std::cout << player_health << std::endl;
    // damage_by_reference(player_health);
    // std::cout << player_health << std::endl;

    // What happened with pass-by-value?
    // Answer: It remained 100

    // What happened with pass-by-reference?
    // Answer: It changed to 80

    // Why?
    // Answer: Because if they are not referenced to the same variable the function will only change it's own local copy and not both.
    
    // Exercise 4 -- Apply it to your game
    // Player player("Ville", 100, 30);
    // give_gold(player, 100);
    // std::cout << "Player gold: " << player.gold << std::endl;

    // int health = 100;

    // int* pointer = &health;

    // std::cout << health << std::endl;
    // std::cout << &health << std::endl;
    // std::cout << pointer << std::endl;
    // std::cout << *pointer << std::endl;
    // *pointer = 50;
    // std::cout << health << std::endl;

    // Exercise 5 -- Pointer experiment
    // int health = 100;
    // int* pointer = &health;

    // std::cout << health << std::endl;
    // std::cout << &health << std::endl;
    // std::cout << pointer << std::endl;
    // std::cout << *pointer << std::endl;

    // *pointer = 25;

    // std::cout << health << std::endl;

    // What does &health mean?
    // Answer: It's the address to the variable health

    // What does pointer contain?
    // Answer: It stores the address of a variable

    // What does *pointer mean?
    // Answer: What value is at the address of the pointer

    // Why did changing *pointer change health?
    // Answer: Since *pointer is the value of the address of pointer you also change the value of the variable connected to that value.
    // They share address and therefore health also changes.

    // Reference is another name for the variable
    // Pointer contains the address of the variable

    // &variable
    //     ↓
    // address of variable

    // type& variable
    //     ↓
    // reference to variable

    // type* variable
    //     ↓
    // pointer to variable

    // *pointer
    //     ↓
    // value at the pointer's address

    // Exercise 6 -- The four symbols
    // int health = 100;
    // int& reference = health;
    // int* pointer = &health;

    // std::cout << health << std::endl;       // Value of health
    // std::cout << &health << std::endl;      // Address of health
    // std::cout << reference << std::endl;    // Value of reference
    // std::cout << &reference << std::endl;   // Address of reference
    // std::cout << pointer << std::endl;      // Address of health
    // std::cout << *pointer << std::endl;     // Value of health

    // reference = 75;
    // std::cout << "Changing reference to 75" << std::endl;
    // std::cout << health << std::endl;
    // std::cout << &health << std::endl;
    // std::cout << reference << std::endl;
    // std::cout << &reference << std::endl;
    // std::cout << pointer << std::endl;
    // std::cout << *pointer << std::endl;

    // *pointer = 50;
    // std::cout << "Changing *pointer to 50" << std::endl;
    // std::cout << health << std::endl;
    // std::cout << &health << std::endl;
    // std::cout << reference << std::endl;
    // std::cout << &reference << std::endl;
    // std::cout << pointer << std::endl;
    // std::cout << *pointer << std::endl;

    // Exercise 7 -- Safe pointer
    // int* pointer = nullptr;
    // if (pointer == nullptr)
    // {
    //     std::cout << "Pointer is empty." << std::endl;
    // }

    // int health = 100;
    // pointer = &health;
    // if (pointer != nullptr)
    // {
    //     std::cout << "Pointer is not empty." << std::endl;
    // }

    // Challenge -- Build a tiny damage system

    // int player_health = 100;
    // damage(&player_health, 30);
    // std::cout << "Player health: " << player_health << std::endl;
    // damage(nullptr, 30);

    // Final challenge -- Reference AND pointer
    int player_health = 100;
    damage_by_reference2(player_health, 30);
    std::cout << player_health << std::endl;
    damage_by_pointer(&player_health, 30);
    std::cout << player_health << std::endl;

    // Why might you prefer a reference over a pointer when you know the object must exist?
    // Answer: Since you don't have to check if the object exists.
    // Also the code might be a bit easier to read.
    // A pointer could be null, which is not a guarantee.
    // A reference always refers to the same object.
    // A reference naturally works with operators.

    return 0;
}