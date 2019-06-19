#pragma once
#include <iostream>
#include "MoveManager.hpp"
#include "Enums.hpp"

using namespace std;

class MoveManager;
class Actor{
protected:
	vector<MoveType> moves;
	int health;
	string type;
public:
	Actor(string type) : health(100) {}
	void DoMove(MoveManager mgr, MoveType moveType, Actor* other);
	void Hit(int damage);
	void Heal(int amount);
	bool IsDead(){return health == 0;};
};

//------------------------------------------------------------------------------
class Ghost : public Actor{
public:
	Ghost(string type) : Actor(type) {}
};

//------------------------------------------------------------------------------
class Knight : public Actor{
public:
	Knight(string type) : Actor(type) {}
};

//------------------------------------------------------------------------------
class Warrior : public Actor{
public:
	Warrior(string type) : Actor(type) {}
};
