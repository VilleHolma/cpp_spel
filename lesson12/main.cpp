#include <iostream>
#include <string>
#include <vector>

class Enemy
{
protected: // instead of private so that subclasses also can access the data
    std::string name;
    int health;

public:
    Enemy(std::string enemy_name, int enemy_health) : name(enemy_name), health(enemy_health)
    {
    }

    void print_status() const
    {
        std::cout << name << " - "
                  << health << " HP\n";
    }
    virtual void attack()
    {
        std::cout << "Enemy attacks!\n";
    }
    
    bool is_alive() const
    {
        return health > 0;
    }

    int get_health() const
    {
        return health;
    }

    std::string get_name() const
    {
        return name;
    }
};

class Goblin : public Enemy
{
public:
    Goblin(std::string name, int health) : Enemy(name, health)
    {}

    void dodge() const
    {
        std::cout << name << " dodges the attack.\n";
    }

    void attack() override
    {
        std::cout << name << " stabs!\n";
    }
};

class Orc : public Enemy
{
public:
    Orc(std::string name, int health) : Enemy(name, health)
    {}
    void rage() const
    {
        std::cout << name << " enters a rage!\n";
    }
    void attack() override
    {
        std::cout << name << " swings its axe!\n";
    }

};

class Troll : public Enemy
{
public:
    Troll(std::string name, int health) : Enemy(name, health)
    {}
    void attack() override
    {
        std::cout << name << " smashes the ground!\n";
    }
};

int main()
{
    // Goblin goblin("Goblin", 50);
    
    // goblin.print_status();
    // goblin.dodge();

    // Exercise 1 -- Create an Orc
    // Orc orc("Orc", 100);
    // orc.print_status();

    // Exercise 2 -- Orc ability
    // orc.rage();

    // Exercise 3 -- Enemy pointer
    // Enemy* enemy = &goblin;

    // enemy->print_status(); // we use -> instaed . since enemy is a pointer

    // Exercise 4 -- Different attacks
    // goblin.attack();
    // orc.attack();

    // Enemy* enemy1 = &goblin;
    // Enemy* enemy2 = &orc;

    // enemy1->attack();
    // enemy2->attack();

    // Exercise 5 -- Your first polymorphic collection
    // std::vector<Enemy*> enemies;

    // enemies.push_back(&goblin);
    // enemies.push_back(&orc);

    // for (Enemy* enemy : enemies)
    // {
    //     enemy->attack();
    // }

    // Challenge - Build an enemy hierarchy
    Goblin goblin("Goblin", 50);
    Orc orc("Orc", 100);
    Troll troll("Troll", 200);

    std::vector<Enemy*> enemies;

    enemies.push_back(&goblin);
    enemies.push_back(&orc);
    enemies.push_back(&troll);

    for (Enemy* enemy : enemies)
    {
        enemy->print_status();
        enemy->attack();
    }



    return 0;
}