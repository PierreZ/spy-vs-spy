#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>



using namespace sf;
using namespace std; 

// Constantes
#define AGRANDISSEMENT 3
#define DIV_FREQ_ANIMATION 1

#define TUILE_W 16
#define TUILE_H 24

#define NB_WINDOW_TUILES_X 16
#define NB_WINDOW_TUILES_Y 8




//-----définitions des prototypes des fonctions--------------------------------------------------------------------------------------------------------

int** mappageBackground();
Sprite** createSpritesBackground(int **tab, Texture **texture);
void drawBackground(RenderWindow *window, Sprite **sprite);

int **createTable(int nbLin, int nbCol); 
void freeTable(int **tableau);

Texture** loadTexture(string name_image, int nb_col, int nb_lin);

//-----fin définitions des prototypes des fonctions--------------------------------------------------------------------------------------------------------

int main()
{

	sf::RenderWindow window(sf::VideoMode(TUILE_W*AGRANDISSEMENT*NB_WINDOW_TUILES_X, TUILE_H*AGRANDISSEMENT*NB_WINDOW_TUILES_Y), "SFML works!");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled (true); 	


	int a=0,b=0;//orientation perso et animatio sprite
	int compteurAnimation=0;
	int vitessePerso=5;


	Sprite perso1;

	Texture **texture=loadTexture("ressources/ennemi2.png",4,2);
	perso1.setTexture(texture[0][0]);
	perso1.setScale(AGRANDISSEMENT,AGRANDISSEMENT);



	Texture **texture_background =loadTexture("ressources/background_base1.png",9,1);
	int **tab_background=mappageBackground();
	Sprite **background = createSpritesBackground(tab_background,texture_background);


	int x,y;

	while (window.isOpen())
	{
		sf::Keyboard::Key direction;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed )
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

					//perso1.move((-1*sf::Keyboard::isKeyPressed(sf::Keyboard::Left)+1*sf::Keyboard::isKeyPressed(sf::Keyboard::Right))*vitessePerso, 0);
					//perso1.move(0,(-1*sf::Keyboard::isKeyPressed(sf::Keyboard::Up)+1*sf::Keyboard::isKeyPressed(sf::Keyboard::Down))*vitessePerso);

				if (event.key.code == sf::Keyboard::Left
					|| event.key.code == sf::Keyboard::Right
					|| event.key.code == sf::Keyboard::Up
					|| event.key.code == sf::Keyboard::Down
					)
				{
					direction = event.key.code;
				}
				//compteurAnimation++;
				//if(compteurAnimation == DIV_FREQ_ANIMATION) 
				//{
					b=!b;
				//	compteurAnimation=0;
				//}
			}
			else if(event.type == sf::Event::KeyReleased){
				if (event.key.code == sf::Keyboard::Left
					|| event.key.code == sf::Keyboard::Right
					|| event.key.code == sf::Keyboard::Up
					|| event.key.code == sf::Keyboard::Down
					)
				{
					if(direction == event.key.code)
						direction = sf::Keyboard::Unknown;
				}
			}
		}

		switch(direction){
			case sf::Keyboard::Left: perso1.move(-vitessePerso,0); break;
			case sf::Keyboard::Right: perso1.move(vitessePerso,0); break;
			case sf::Keyboard::Up: perso1.move(0,-vitessePerso); break;
			case sf::Keyboard::Down: perso1.move(0,vitessePerso); break;
		}

		perso1.setTexture(texture[a][b]);



		window.clear();

		drawBackground(&window, background);

		window.draw(perso1);

		window.display();
	}

	return 0;
}


//-----développement des fonctions--------------------------------------------------------------------------------------------------------

int** mappageBackground()
{
	int **tab=createTable(NB_WINDOW_TUILES_Y, NB_WINDOW_TUILES_X);

	cout<<endl;
	int i, j;
	for(i=0;i<NB_WINDOW_TUILES_Y;i++)
	{	
		for(j=0;j<NB_WINDOW_TUILES_X;j++)
		{
			if(i==0 && j!=0 && j!=NB_WINDOW_TUILES_X-1)//up
			{
				tab[i][j]=0;
			}
			else if(i==NB_WINDOW_TUILES_Y-1 && j!=0 && j!=NB_WINDOW_TUILES_X-1)//down
			{
				tab[i][j]=1;
			}
			else if(j==0 && i!=0 && i!=NB_WINDOW_TUILES_Y-1)//left
			{
				tab[i][j]=2;
			}
			else if(j==NB_WINDOW_TUILES_X-1 && i!=0 && i!=NB_WINDOW_TUILES_Y-1)//right
			{
				tab[i][j]=3;
			}
			else if(i==0 && j==0)//coin haut gauche
			{
				tab[i][j]=4;
			}
			else if(i==0 && j==NB_WINDOW_TUILES_X-1)//coin haut droit
			{
				tab[i][j]=5;
			}
			else if(j==0 && i==NB_WINDOW_TUILES_Y-1)//coin bas gauche
			{
				tab[i][j]=6;
			}
			else if(j==NB_WINDOW_TUILES_X-1 && i==NB_WINDOW_TUILES_Y-1)//coin bas droit
			{
				tab[i][j]=7;
			}
			else
			{
				tab[i][j]=9;
			}
			cout<<tab[i][j];
		}
		cout<<endl;

	}
	cout<<endl;
	return tab;
}


Sprite** createSpritesBackground(int **tab, Texture **texture)
{
	//background;

	Sprite** background = new Sprite*[NB_WINDOW_TUILES_Y];
	for (int o = 0; o < NB_WINDOW_TUILES_Y; o++)
		background[o] = new Sprite[NB_WINDOW_TUILES_X];

	//cout<<endl;
	int c, d;
	for(c=0;c<NB_WINDOW_TUILES_Y;c++)
	{	
		for(d=0;d<NB_WINDOW_TUILES_X;d++)
		{
			if(tab[c][d]==9)
			{
				background[c][d].setTexture(texture[0][0]);
			}
			else
			{
				background[c][d].setTexture(texture[tab[c][d]+1][0]);
			}
			background[c][d].setPosition (AGRANDISSEMENT*d*TUILE_W,AGRANDISSEMENT*c*TUILE_H);
			background[c][d].setScale(AGRANDISSEMENT,AGRANDISSEMENT);
			//cout<<tab[c][d];
		}
		//cout<<endl;
	}
	//cout<<endl;
	return background;
}

void drawBackground(RenderWindow *window, Sprite **sprite)
{
	int i,j;
	for(i=0;i<NB_WINDOW_TUILES_Y;i++)
	{	
		for(j=0;j<NB_WINDOW_TUILES_X;j++)
		{
			window->draw(sprite[i][j]);			
		}
	}
}

int **createTable(int nbLin, int nbCol)
{
	int **tableau = (int **)malloc(sizeof(int*)*nbLin);
	int *tableau2 = (int *)malloc(sizeof(int)*nbCol*nbLin);
	for(int i = 0 ; i < nbLin ; i++)
	{
		tableau[i] = &tableau2[i*nbCol];
	}
	return tableau;
}

void freeTable(int **tableau)
{
	free(tableau[0]);
	free(tableau);
}


Texture** loadTexture(string name_image, int nb_col, int nb_lin)
{

	Texture** texture = new Texture*[nb_col];
	for (int o = 0; o < nb_col; o++)
		texture[o] = new Texture[nb_lin];

	Image image;

	if (!image.loadFromFile(name_image)) // Si le chargement du fichier a échoué
	{
		cout<<"Erreur durant le chargement de l'image: "<< name_image <<endl;
	}
	else // Si le chargement de l'image a réussi
	{	
		Color bleu_transparence = Color(0,0,255);
		image.createMaskFromColor(bleu_transparence,0);

		int i,j;
		for(i=0;i<nb_col;i++)
		{	
			for(j=0;j<nb_lin;j++)
			{
				texture[i][j].loadFromImage(image,IntRect(i*(image.getSize().x/nb_col), j*(image.getSize().y/nb_lin), (image.getSize().x/nb_col) , (image.getSize().y/nb_lin)));
				texture[i][j].setSmooth(false);	
			}
		}
	}
	return texture;
}

//-----fin développement des fonctions--------------------------------------------------------------------------------------------------------
