#ifndef _GAME_H_
#define _GAME_H_

/*! Headers */
#include <ostream>
#include <memory>
#include "IGame.h"
#include "Pgn.h"
#include "Ngine.h"
#include "Display.h"
#include "DataTypes.h"
#include "DisplayMessages.h"
/**
* @brief
* Creates the game instance based on the user's input
*
* A Game builder class based on the popular "Builder Pattern"
* which creates and builds the complex game object based on the 
* type of the game the user wants to play
*
*/
class Game : public IGame
    Game
	~Game() {}
	void Input(){ Pgn pgn; }		 // Command Line
	void Process() { Ngine ngx; }	// Engine
	void Output() { Display dsp; } // Display
private:
};

/**
* @brief: Abstract Game Builder 
*/
class IGameBuilder
{
public:
	virtual ~IGameBuilder() {}

	Game *GetGame()
	{
		return m_Game.release();
	}
	void CreateNewGame()
	{
		m_Game = std::make_unique<Game>();
	}
	virtual void BuildInput() = 0;
	virtual void BuildEngine() = 0;
	virtual void BuildDisplay() = 0;

protected:
	std::unique_ptr<Game> m_Game;
};

/**
* @brief: Game Builder 
*/

template <class T>
class GameBuilder : public IGameBuilder
{
public:
	virtual ~T(){};

	virtual void BuildInput()
	{
		m_Game->Input();
	}
	virtual void BuildEngine()
	{
		m_Game->Process();
	}
	virtual void BuildDisplay()
	{
		m_Game->Output();
	}
};

/**
* @brief: Game Creator/Director  
*/

class GameCreator
{
public:
	DATATYPES::OPTIONS choice;
	GameCreator(const DATATYPES::OPTIONS &opt) : choice(opt)
	{
		if (choice == DATATYPES::LOCAL)
		{
			GameBuilder rLocalGame;
			CreateGame(&rLocalGame);
		}
		if (choice == DATATYPES::OVER_THE_NW)
		{
			NetworkGameBuilder rNetworkGame;
			CreateGame(&rNetworkGame);
		}
	}

protected:
	void CreateGame(IGameBuilder *pGameBuilder)
	{
		m_GameBuilder = pGameBuilder;
		m_GameBuilder->CreateNewGame();
		m_GameBuilder->BuildInput();
		m_GameBuilder->BuildEngine();
		m_GameBuilder->BuildDisplay();
	}

private:
	IGameBuilder *m_GameBuilder;
};

#endif // _GAME_H_