Program Two

-------------------------------------------------------------------------------------------
Goals:
-------------------------------------------------------------------------------------------

	Create a class hierarchy for game actors
	Use the Stack (template) along with the Command Pattern to create an undoable action
	Simulate a battle between two Actors with the ability to undo moves

-------------------------------------------------------------------------------------------
Program Overview:
-------------------------------------------------------------------------------------------

	This program will consist of several Actors (Knight, Ghost, and Warrior) that are capable of performing attacks and healing. 
	You will run a simulation of a battle between these actors with a running "history" of moves. 
	The simulation will first prompt you to select a player and an opponent. Once the two are set, and a battle has begun,
	There will be 3 options available: 

		1) Player attacks Opponent
		2) Opponent attacks Player
		3) Undo last move

	The first two will invoke an attack from one player to another. The third option will undo the last move that was done with a technique discussed below. 
	After each choice, the updated player information is printed (Player, type, health), (Opponent, type health)
	

	This will proceed until a character is dead. 

-------------------------------------------------------------------------------------------
Classes for Battle simulator:
-------------------------------------------------------------------------------------------
	We will incorporate the Undoable command pattern to help us preserve a history of BattleMoves done by our Actors. Our Project will be broken up into several classes The hierarchies will look as follows:

Actor - General game character with the following ADT spec:
	public:
		Actor(int health, string type); 
		DoMove(MoveManager mgr, MoveType, Actor* other)
		Hit(int damage);	//public method to hit THIS actor with damage
		Heal(int amount);	//public method to heal this actor with an amount
		GetMoves()	//vector of MoveTypes
		IsDead()

	protected:
		string type;
		int health;
		vector<MoveType> 

From Actor we will derive:
	Ghost
		Will have AttackOne and Heal in vector of MoveTypes, and 100 health
	Knight
		Will have AttackTwo and Heal in vector of MoveTypes, and 100 health
	Warrior
		Will have AttackOne and AttackTwo in vector of MoveTypes, and 100 health
		

BattleMove - A battle move which can either hurt the opponent, or heal the player. ADT spec:
	private:
		Actor* self
		Actor* other
	public:	
		void virtual Execute()=0;
		void virtual Undo()=0;

(Note: Each battle move will have an Execute method. That execute will either work on self (if heal) or other (if attack)) Therefore when we construct a move
we should pass in the self and other pointers to any kind of concrete BattleMove implementation.
	
From BattleMove we will derive:

	AttackOne
		Will generate a random damage between 10 and 15
		Execute will call the Hit method of other and save the actualDamage done in a 			
		local variable. 
		Undo will call the Heal method of other with the saved actualDamage variable (to 		
		undo the damage)

	AttackTwo
		Will generate a random damage between 0 and 25
		Same logic as attack one
	
	Heal
		Will generate a random heal amount between 10 and 15
		Execute will call Heal on self with the actual heal amount and save it in a 			
		member variable.
		Undo will call Hit on self to undo the Heal (with amount stored in the member 			
		variable)	

An enumeration or array of const char *'s to go with BattleMove (MoveType)
An enumeration or array of const char *'s to go with Actor types (ActorType)

MoveManager - Analogous to our CommandManager class. Will hold on to a stack (use the template implementation of stack from the lecture code on Templates) of BattleMove*'s and will be referenced by every actor. Whenever an actor performs a move, it will go through the MoveManager's method so that history is recorded on the stack. 
Move manager will have DoMove() and UndoLastMove() methods defined, a constructor to initialize a stack, as well as a destructor to delete all the BattleMove*'s still in the stack. A MoveManager's DoMove will switch based on the MoveType passed in, create an new BattleMove object of that type, execute the move, and push the move onto the stack. UndoLastMove will call undo on the Top() element of the stack, pop it off the stack, and delete the object.ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ï»¿ Use exception handling logic (try/catch) to check for an empty stack. In the case that the stack is empty, make sure you print an appropriate message to the user (e.g. "No moves to undo"). 

Runner
	This will be the class to run the battle. First it will prompt the user for a choice of player 1 and player 2. Then it will allow the user to select one of three choices mentioned in the first sectio. After each choice, If it is a move, select a random move from the actor's list of moves and DoMove with it (passing in the movemanager to take care of it). If the choice is an undo, invoke the MoveManager's UndoLastMove() method. Make sure to check for a stackEmpty exception. After a move print the state of each character. Some sample output: 