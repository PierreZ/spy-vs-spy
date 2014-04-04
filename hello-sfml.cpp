#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>



using namespace sf;
using namespace std; 

// Constantes
#define AGRANDISSEMENT 6
#define DIV_FREQ_ANIMATION 4

#define TUILE_W 16
#define TUILE_H 24

#define NB_WINDOW_TUILES_X 16
#define NB_WINDOW_TUILES_Y 8




//-----définitions des prototypes des fonctions--------------------------------------------------------------------------------------------------------

int** mappageBackground();
Sprite** createSpritesBackground(int **tab, Texture *texture);
void drawBackground(RenderWindow *window, Sprite **sprite);

int **createTable(int nbLin, int nbCol); 
void freeTable(int **tableau);

Sprite **createSpriteTable(int nbLin, int nbCol); 
void freeSpriteTable(Sprite **tableau);

//-----fin définitions des prototypes des fonctions--------------------------------------------------------------------------------------------------------

int main()
{

	sf::RenderWindow window(sf::VideoMode(TUILE_W*AGRANDISSEMENT*NB_WINDOW_TUILES_X, TUILE_H*AGRANDISSEMENT*NB_WINDOW_TUILES_Y), "SFML works!");
	window.setFramerateLimit(60);


	int a=0,b=0;//orientatio perso et animatio sprite
	int compteurAnimation=0;
	int vitessePerso=5;


	Texture texture[4][2];
	Image image;
	Sprite perso1;


	if (!image.loadFromFile("ressources/ennemi.png")) // Si le chargement du fichier a échoué
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		return EXIT_FAILURE; // On ferme le programme
	}
	else // Si le chargement de l'image a réussi
	{	
		Color bleu_transparence = Color(0,0,255);
		image.createMaskFromColor(bleu_transparence,0);

		int i,j;
		for(i=0;i<4;i++)
		{	
			for(j=0;j<2;j++)
			{
				texture[i][j].loadFromImage(image,IntRect(i*TUILE_W, j*TUILE_H, TUILE_W , TUILE_H));
				texture[i][j].setSmooth(false);	
			}
		}
	}


	Texture texture_background[4];
	Image image_background;
	
	if (!image_background.loadFromFile("ressources/background_base1.png")) // Si le chargement du fichier a échoué
	{
		cout<<"Erreur durant le chargement de l'image"<<endl;
		return EXIT_FAILURE; // On ferme le programme
	}
	else // Si le chargement de l'image a réussi
	{	
		int k;
		for(k=0;k<5;k++)
		{
			texture_background[k].loadFromImage(image_background,IntRect(k*TUILE_W, 0, TUILE_W , TUILE_H));
			texture_background[k].setSmooth(false);	
		}
	}
	int **tab_background=mappageBackground();
	Sprite **background=createSpritesBackground(tab_background, texture_background);

	perso1.setTexture(texture[0][0]);
	perso1.setScale(AGRANDISSEMENT,AGRANDISSEMENT);
	
	int x,y;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
    			// la touche "flèche gauche" est enfoncée : on bouge le personnage
				perso1.move(-vitessePerso, 0);
				a=2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
    			// la touche "flèche droite" est enfoncée : on bouge le personnage
				perso1.move(vitessePerso, 0);
				a=3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
    			// la touche "flèche haut" est enfoncée : on bouge le personnage
				perso1.move(0, -vitessePerso);
				a=0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
    			// la touche "flèche bas" est enfoncée : on bouge le personnage
				perso1.move(0, vitessePerso);
				a=1;
			}

			compteurAnimation++;
			if(compteurAnimation == DIV_FREQ_ANIMATION) 
			{
				b=!b;
				compteurAnimation=0;
			}

			perso1.setTexture(texture[0][0]);//le putain de perso charge ue sprite du background en 0 0 ?????!!! wtf!!!

		}

		window.clear();

		window.draw(perso1);

		//		window.draw(background[0][0]);	//-->seg fault revoir le chargement des sprites		

		window.display();
	}

	return 0;
}


//-----développement des fonctions--------------------------------------------------------------------------------------------------------

int** mappageBackground()
{
	int **tab=createTable(NB_WINDOW_TUILES_X, NB_WINDOW_TUILES_Y);


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
	return tab;
}


Sprite** createSpritesBackground(int **tab, Texture *texture)
{
	Sprite **Sprite=createSpriteTable(NB_WINDOW_TUILES_X, NB_WINDOW_TUILES_Y);
	int i, j;
	for(i=0;i<NB_WINDOW_TUILES_Y;i++)
	{	
		for(j=0;j<NB_WINDOW_TUILES_X;j++)
		{
			if(tab[i][j]==0)
			{
				Sprite[i][j].setTexture(texture[1]);
			}
			else if(tab[i][j]==1)
			{
				Sprite[i][j].setTexture(texture[2]);
			}
			else if(tab[i][j]==2)
			{
				Sprite[i][j].setTexture(texture[3]);
			}
			else if(tab[i][j]==3)
			{
				Sprite[i][j].setTexture(texture[4]);
			}
			else
			{
				Sprite[i][j].setTexture(texture[0]);
			}
			Sprite[i][j].setPosition (i*TUILE_H,j*TUILE_W);
		}
	}
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
	for(int i = 0 ; i < nbLin ; i++){
		tableau[i] = &tableau2[i*nbCol];
	}
	return tableau;
}

void freeTable(int **tableau)
{
	free(tableau[0]);
	free(tableau);
}

Sprite **createSpriteTable(int nbLin, int nbCol)
{
	Sprite **tableau = (Sprite **)malloc(sizeof(Sprite*)*nbLin);
	Sprite *tableau2 = (Sprite *)malloc(sizeof(Sprite)*nbCol*nbLin);
	for(int i = 0 ; i < nbLin ; i++){
		tableau[i] = &tableau2[i*nbCol];
	}
	return tableau;
}

void freeSpriteTable(Sprite **tableau)
{
	free(tableau[0]);
	free(tableau);
}

//-----fin développement des fonctions--------------------------------------------------------------------------------------------------------
