#include "functions.h"
#include <iostream>

using namespace std;

// ==========================================
// PART ONE: Default Arguments Implementations
// ==========================================

void displaySpellBanner(string spellName, string tier, int chargeLevel) {
    cout << "\n[SPELL CAST] " << spellName 
         << " | Tier: " << tier 
         << " | Charge Level: " << chargeLevel << "\n";
}

double castSpell(string spellName, int basePower, double multiplier) {
    double totalDamage = basePower * multiplier;
    cout << "Attack Summary: " << spellName 
         << " deals " << totalDamage << " damage! "
         << "(Base: " << basePower << ", Multiplier: " << multiplier << ")\n";
    return totalDamage;
}

double calculateShield(double baseShield, double absorptionRate) {
    double totalWard = baseShield * (1.0 + absorptionRate);
    return totalWard;
}

// ==========================================
// PART TWO: Static Variables Implementations
// ==========================================

int registerCombo(bool hitSuccessful) {
    static int comboCount = 0;
    if (hitSuccessful) {
        comboCount++;
    } else {
        cout << "[WARNING] Combo interrupted! ";
        comboCount = 0;
    }
    return comboCount;
}

void consumeMana(int cost) {
    static int totalManaUsed = 0;
    totalManaUsed += cost;
    cout << "Mana Expended: " << cost << " | Total Mana Used in Duel: " << totalManaUsed << "\n";
}

bool processBossRage(double damageDealt) {
    static double totalDamageDealt = 0.0;
    totalDamageDealt += damageDealt;
    cout << "Accumulated Boss Damage: " << totalDamageDealt << " / 100.0 HP\n";
    
    if (totalDamageDealt >= 100.0) {
        return true;
    }
    return false;
}

int gainWizardXP(int expGained) {
    static int totalXP = 0;
    static int wizardLevel = 1;

    totalXP += expGained;
    cout << "XP Gained: " << expGained << " | Total XP: " << totalXP << " (Level " << wizardLevel << ")\n";

    if (totalXP >= wizardLevel * 100) {
        wizardLevel++;
        cout << "*** LEVEL UP! You have advanced to Level " << wizardLevel << "! ***\n";
    }

    return wizardLevel;
}
