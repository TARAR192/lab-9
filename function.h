#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

// --- PART ONE: Default Arguments ---
void displaySpellBanner(std::string spellName, std::string tier = "Novice", int chargeLevel = 1);
double castSpell(std::string spellName = "Magic Missile", int basePower = 10, double multiplier = 1.0);
double calculateShield(double baseShield = 15.0, double absorptionRate = 0.2);

// --- PART TWO: Static Local Variables ---
int registerCombo(bool hitSuccessful);
void consumeMana(int cost = 5);
bool processBossRage(double damageDealt);
int gainWizardXP(int expGained = 25);

#endif
