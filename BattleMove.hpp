#pragma once
#include "Actor.hpp"

class Actor;

class BattleMove{
public:
	virtual void Execute()=0;
	virtual void Undo()=0;
	virtual ~BattleMove(){};
protected:
	Actor* self;
	Actor* other;
};

//------------------------------------------------------------------------------
class AttackOne : public BattleMove{
public:
	void Execute();
	void Undo();
};

//------------------------------------------------------------------------------
class AttackTwo : public BattleMove{
public:
	void Execute();
	void Undo();
};

//------------------------------------------------------------------------------
class Heal : public BattleMove{
public:
	void Execute();
	void Undo();
};