#include <iostream>
#include <string>
#include "Player.h"


void print_name(std::string& name)
{
    name = "Changed";
    std::cout << name << std::endl;
}

// means "Give me access to the original string without copying it, but don't allow me to modify it."
void print_name_safe(const std::string& name)
{
    std::cout << name << std::endl;
}

class Enemy
{
public:
    std::string name;
    int health;

    void print_status() const
    {
        std::cout << name << std::endl;
        std::cout << "Health: " << health << "\n\n";
    }

    void take_damage(int damage)
    {
        health -= damage;
    }
};

int main()
{
    // Exercise 1
    // const int max_health = 100;
    // const int player_attack = 30;
    // const std::string game_name = "Dark Forest";

    
    // max_health = 200;
    // variable 'max_health' declared const here


    // Part 3 -- const function parameters
    // const
    // ↓
    // I promise not to modify it

    // std::string
    // ↓
    // The type

    // &
    // ↓
    // Pass by reference

    // Exercise 2 -- reference vs const reference
    // std::string name = "Alice";
    // print_name(name);
    // print_name_safe(name);
    // The first function allows modification since it has a non-const reference.
    // The second function prevents modification because of its const reference.
    // It's preferable when you only want to read a string since you remove the risks of changing the string.

    // Exercise 3 -- Const memeber functions
    // Enemy goblin;
    // goblin.name = "Goblin";
    // goblin.health = 50;

    // goblin.print_status();
    // goblin.take_damage(20);
    // goblin.print_status();
    // print_status() should be constant since HOW we write the status shouldn't change.
    // take_damage() shouldn't be constant since you can take different amounts of damage.

    Player player("Ville", 100, 30);

    std::cout << player.get_name() << std::endl;
    std::cout << player.get_health() << std::endl;
    // It works!
    
    // Exercise 6 -- Add a controlled health system
    player.take_damage(20);
    std::cout << player.get_health() << std::endl;
    // Works!
    player.heal(30);
    std::cout << player.get_health() << std::endl;

    // Challenge
    // See the new codes for Player.cpp and Player.h
    return 0;
}