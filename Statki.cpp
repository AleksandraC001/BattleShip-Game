//Aleksandra Czuprynska, 115694, Gra w statki

#include "Klasy.h"


template<class A, class B>
void Shooting(A* player1_or_computer, B* player2_or_computer)//funkcja realizuje na zmiane strzelanie w statki przeciwnika obu u¿ytkowników/u¿ytkownika i komputera
{
	while (player1_or_computer->get_points() != WIN && player2_or_computer->get_points() != WIN)
	{
		player2_or_computer->shot(player1_or_computer->Board);
		//Sleep(3000);/////dodane bo tryb z komputerem
		/*system("cls");*/

		if (player2_or_computer->get_points() == WIN)
		{
			break;
		}
		player1_or_computer->shot(player2_or_computer->Board);
		/*Sleep(3000);
		system("cls");*/
	}
}

int main()
{
	srand(time(NULL));
	printf("XXXXXXXXXXXXXXXXXXXXXXXXX BATTLESHIP GAME XXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXX RULES OF THE GAME XXXXXXXXXXXXXXXXXXXXXXXX\n\nShips cannot touch each other\n\nBoard dimensions: 10x10\n\nEach player has got:\none 5-spaces long ship,\ntwo 4-spaces long ships,\ntwo 3-spaces long ships,\nthree 2-spaces long ships,\n");
	Player* G1 = NULL;
	Player* G2 = NULL;
	int choice=choose_game_mode();
	if (choice == 2)//two players mode
	{
		Player* G1 = new Player();
		G2 = new Player();//both players are humans
		G1->load_nick(1);
		printf("Hello Player %s", G1->getnick());
		G2->setnumber(2);
		G1->load_ships();
		clean_the_screen();
		G2->load_nick(2);
		if (strcmp(G1->getnick(), G2->getnick())==0)////if the same nick is given the computer mode starts
		{
			delete(G2);
			int w;
			choice == 1;
			printf("You have entered the same nicks, the computer mode starts.\n");
			w = choose_strategy();
			G2 = new Computer(w,1);//G2 change into computer with random shooting strategy
			printf("\n\nComputer loads the ships...\n");
			G2->load_ships();
			printf("\n");
			Shooting(G1, G2);
			choice = 0;
		}
		if(choice==2)//2 human players
		{
			printf("Hello Player %s", G2->getnick());
			G2->load_ships();
			Shooting(G1, G2);
		}
	}
	if (choice == 1)//computer mode
	{
		G1 = new Player();
		int p;
		p = choose_strategy();
		G2 = new Computer(p,1);
		G1->load_nick(1);
		printf("Hello player %s", G1->getnick());
		G1->load_ships();
		printf("\n\nComputer loads the ships...\n");
		G2->load_ships();
		Shooting(G1, G2);
	}
	if (choice == 3)
	{
		printf("You have chosen computers battle.\n");
		int z;
		printf("Computer 1:\n");
		z = choose_strategy();
		G1 = new Computer(z,1);
		printf("\n\nComputer 2:\n");
		z = choose_strategy();
		G2 = new Computer(z,2);
		printf("\n\nComputers loads the ships...\n");
		G1->load_ships();
		G2->load_ships();
		Sleep(1000);
		system("cls");
		Shooting(G1, G2);
	}
	delete(G1);
	delete(G2);
	return 0;
}