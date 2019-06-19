#pragma once
#include <vector>
#include "BattleMove.hpp"
#include "Stack.hpp"
#include "Enums.hpp"
class BattleMove;
class MoveManager{
private:
	Stack<BattleMove*> stack;
public:
    MoveManager() : stack(Stack<BattleMove*>()) {}
    void ExecuteCommand(MoveType MoveType);
    void UndoLastCommand();
    ~MoveManager();
};