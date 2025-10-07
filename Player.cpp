#include "Player.h"

// Constructor
Player::Player(const std::string& playerName, int startHealth)
    : name(playerName), health(startHealth), maxHealth(startHealth), 
      x(0), y(0), score(0) {
}

// Destructor
Player::~Player() {
}

// Getters
std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

int Player::getScore() const {
    return score;
}

bool Player::isAlive() const {
    return health > 0;
}

// Setters
void Player::setName(const std::string& playerName) {
    name = playerName;
}

void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

// Game actions
void Player::move(int deltaX, int deltaY) {
    x += deltaX;
    y += deltaY;
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

void Player::addScore(int points) {
    score += points;
}

void Player::reset() {
    health = maxHealth;
    x = 0;
    y = 0;
    score = 0;
}
