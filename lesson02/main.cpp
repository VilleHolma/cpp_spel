#include <iostream>
#include <string>

int main()
{
    // Exercise 4
    // player's health
    int health = 100;
    // player's score
    int score = 500;
    // player's speed
    float speed = 4.5f;
    // player's name
    std::string name = "Alex";
    // whether the player is alive
    bool alive = true;

    // print all five:
    std::cout << "Name: " << name << std::endl << "Health: " << health << std::endl << "Score: " << score << std::endl << "Speed: " << speed << std::endl << "Alive: " << alive << std::endl;

    // Exercise 5
    // health starts at 100
    // player takes 30 damage
    // player earns 50 points
    // player speed increases by 1

    health -= 30;
    score += 50;
    speed += 1;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Alive: " << alive << std::endl;

    // Exercise 6
    std::string player = "Player!";
    int player_health = 100;
    int player_attack = 30;

    std::string enemy = "Goblin!";
    int enemy_health = 100;
    int enemy_attack = 15;
    
    enemy_health -= player_attack;
    player_health -= enemy_attack;

    std::cout << "Player attacks " << enemy << "\n" << "Enemy health: " << enemy_health << "\n\n";
    std::cout << "Enemy attacks " << player << "\n" << "Player health: " << player_health << "\n";
    
    return 0;
}

