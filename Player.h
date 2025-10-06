#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;
    int maxHealth;
    int x;
    int y;
    int score;

public:
    // Constructor
    Player(const std::string& playerName, int startHealth = 100);
    
    // Destructor
    ~Player();
    
    // Getters
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getX() const;
    int getY() const;
    int getScore() const;
    bool isAlive() const;
    
    // Setters
    void setName(const std::string& playerName);
    void setPosition(int newX, int newY);
    
    // Game actions
    void move(int deltaX, int deltaY);
    void takeDamage(int damage);
    void heal(int amount);
    void addScore(int points);
    void reset();
};

#endif // PLAYER_H
