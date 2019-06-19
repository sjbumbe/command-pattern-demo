#include "BattleMove.hpp"

//---------------------------------------------------------------
void AttackOne::Execute() {
   int damage = rand()%(15-10 + 1) + 10;
   other->Hit(damage);
}

void AttackOne::Undo() {
   
}

//---------------------------------------------------------------
void AttackTwo::Execute() {
    int damage = rand()%(26);
    other->Hit(damage);
}

void AttackTwo::Undo() {
    
}

//---------------------------------------------------------------
void Heal::Execute() {
   int amount = rand()%(15-10 + 1) + 10;
   self->Heal(amount);
}

void Heal::Undo() {
    
}
