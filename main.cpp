#include <iostream>
#include "Player.h"

int main() {
    // Create a player instance
    Player walter("Walter", 100);
    
    std::cout << "Player created: " << walter.getName() << std::endl;
    std::cout << "Health: " << walter.getHealth() << "/" << walter.getMaxHealth() << std::endl;
    std::cout << "Position: (" << walter.getX() << ", " << walter.getY() << ")" << std::endl;
    std::cout << "Score: " << walter.getScore() << std::endl;
    std::cout << "Is alive: " << (walter.isAlive() ? "Yes" : "No") << std::endl;
    
    std::cout << "\n--- Testing player actions ---" << std::endl;
    
    // Test movement
    walter.move(5, 3);
    std::cout << "After moving (5, 3): (" << walter.getX() << ", " << walter.getY() << ")" << std::endl;
    
    // Test taking damage
    walter.takeDamage(30);
    std::cout << "After taking 30 damage: Health = " << walter.getHealth() << std::endl;
    
    // Test healing
    walter.heal(20);
    std::cout << "After healing 20: Health = " << walter.getHealth() << std::endl;
    
    // Test adding score
    walter.addScore(100);
    std::cout << "After adding 100 points: Score = " << walter.getScore() << std::endl;
    
    // Test severe damage
    walter.takeDamage(150);
    std::cout << "After taking 150 damage: Health = " << walter.getHealth() << std::endl;
    std::cout << "Is alive: " << (walter.isAlive() ? "Yes" : "No") << std::endl;
    
    // Test reset
    walter.reset();
    std::cout << "\nAfter reset:" << std::endl;
    std::cout << "Health: " << walter.getHealth() << "/" << walter.getMaxHealth() << std::endl;
    std::cout << "Position: (" << walter.getX() << ", " << walter.getY() << ")" << std::endl;
    std::cout << "Score: " << walter.getScore() << std::endl;
    
    return 0;
}
