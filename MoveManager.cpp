#include "MoveManager.hpp"

void MoveManager::ExecuteCommand(MoveType MoveType) {
    BattleMove* cmd;
    switch(MoveType){
        case MoveType::AttackOneType:
            cmd = new AttackOne();
            break;
        case MoveType::AttackTwoType:
            cmd = new AttackTwo();
        case MoveType::HealType:
            cmd = new Heal();
            break;
    }
    cmd->Execute();
    stack.Push(cmd);
}

void MoveManager::UndoLastCommand() {
    if(stack.IsEmpty()){
        cout << "Nothing to undo." << endl;
        return;
    }
    auto cmd = stack.Top();
    cmd->Undo();
    delete stack.Top();
    stack.Pop();
}

MoveManager::~MoveManager() {
    while(!stack.IsEmpty()){
        delete stack.Top();
        stack.Pop();
    }
}