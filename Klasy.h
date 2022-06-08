#pragma once

#include "Funkcje.h"

class Target
{
	int a;
	int b;
public:
	int get_a();
	int get_b();
	void set_a(int);
	void set_b(int);
};

class SingleField
{
protected:
	int row;
	int column;
	int value;//czy puste pole, pole zajete, trafione lub zatopione
	int hit;//czy pole bylo juz trafione przez strzalami uzytkownika
	char graphically;//pozwala na wypisanie zaszyfrowanej wartosci
public:
	void setvalue(int m);
	int getvalue();
	void setrow(int m);
	void setcolumn(int m);
	void sethit(int m);
	int getrow();
	int getcolumn();
	void setgraphically(char m);
	char getgraphically();
	int gethit();
	SingleField();
	void show_the_value();
	void show_graphically();
};

class Base
{
protected:
	int points;//wynik graczy, za poprawne trafienie statku ilosc punktow zwieksza sie o 1
public:
	SingleField Board[10][10];
	int get_points();
	Base();
	void Show_the_board();
	virtual ~Base() {};
};

class Player : public Base
{
	char nick[10];
	int number;
public:
	Player();
	void setnumber(int m);
	int getnumber();
	char* getnick();
	virtual void load_ship(int n);
	virtual void load_ships();
	void load_nick(int m);
	virtual void shot(SingleField Board[10][10]);
	virtual ~Player()override;
};

class Computer :public Player
{
	int shooting_strategy;
	int target_a=15;
	int target_b=15;
	int nr;
public:
	Computer(int strategy_number, int numberofthecomputer) { shooting_strategy = strategy_number;	nr = numberofthecomputer; }
	int getshooting_strategy();
	void setshooting_strategy(int);
	int gettarget_a();
	int gettarget_b();
	void settarget_a(int);
	void settarget_b(int);
	void shot(SingleField Player_Board[10][10])override;
	void load_ship(int n)override;
	void load_ships()override;
	~Computer() override;
};