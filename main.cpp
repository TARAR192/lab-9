#include <iostream>
#include "functions.h"

int main() {
    std::cout << "=== WIZARD ACADEMY BATTLE SIMULATOR ===\n\n";

    char continueBattle = 'y';
    int turn = 1;

    while (continueBattle == 'y' || continueBattle == 'Y') {
        std::cout << "\n----------------------------------------\n";
        std::cout << " TURN " << turn << "\n";
        std::cout << "----------------------------------------\n";

        int choice = 0;
        std::cout << "Select Action:\n";
        std::cout << "1) Quick Magic Missile (Default attack)\n";
        std::cout << "2) Heavy Lightning Storm (Custom attack)\n";
        std::cout << "3) Cast Defensive Barrier\n";
        std::cout << "4) Miss Attack Intentionally\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        double damageDealt = 0.0;
        bool successfulHit = false;

        if (choice == 1) {
            displaySpellBanner("Magic Missile");
            damageDealt = castSpell(); // Uses default arguments
            consumeMana();             // Uses default mana cost (5)
            successfulHit = true;
        } 
        else if (choice == 2) {
            displaySpellBanner("Lightning Storm", "Adept", 2);
            damageDealt = castSpell("Lightning Storm", 30, 1.4);
            consumeMana(15);           // Custom mana cost
            successfulHit = true;
        } 
        else if (choice == 3) {
            displaySpellBanner("Arcane Shield", "Novice", 1);
            double shieldVal = calculateShield(20.0, 0.25);
            std::cout << "Shield generated! Absorbs " << shieldVal << " incoming damage.\n";
            consumeMana(8);
            successfulHit = true;
        } 
        else {
            std::cout << "Your attack missed completely!\n";
            successfulHit = false;
        }

        // --- UPDATE PERSISTENT GAME STATE VIA STATIC FUNCTIONS ---
        int currentCombo = registerCombo(successfulHit);
        if (successfulHit) {
            std::cout << "Current Combo Streak: " << currentCombo << "x\n";
            gainWizardXP(30); // Award XP for hitting
        }

        // Check if boss enters enrage mode
        bool isBossEnraged = processBossRage(damageDealt);
        if (isBossEnraged) {
            std::cout << "!!! WARNING: BOSS HAS ENTERED ENRAGE MODE !!!\n";
        }

        turn++;
        std::cout << "\nEnd turn? Continue fighting? (y/n): ";
        std::cin >> continueBattle;
    }

    std::cout << "\n=== BATTLE SIMULATION ENDED ===\n";
    return 0;
}
