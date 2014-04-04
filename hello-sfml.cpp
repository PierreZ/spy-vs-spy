#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std; 

// Constantes
#define AGRANDISSEMENT 6
#define DIV_FREQ_ANIMATION 4

int main()
{


	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	
	Texture texture[4][2];
	Image image;
	Sprite perso1;


	int a=0,b=0;//orientatio perso
	int compteurAnimation=0;

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
			texture[i][j].loadFromImage(image,IntRect((i*image.getSize().x)/4, (j*image.getSize().y)/2, (image.getSize().x)/4, (image.getSize().y)/2));
			texture[i][j].setSmooth(false);	
		}
	}
}

perso1.setTexture(texture[0][0]);
perso1.setScale(AGRANDISSEMENT,AGRANDISSEMENT);

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
   			//character.move(1, 0);
			a=2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
    		// la touche "flèche droite" est enfoncée : on bouge le personnage
   			//character.move(1, 0);
			a=3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
    		// la touche "flèche haut" est enfoncée : on bouge le personnage
   			//character.move(1, 0);
			a=0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
    		// la touche "flèche bas" est enfoncée : on bouge le personnage
   			//character.move(1, 0);
			a=1;
		}

		compteurAnimation++;
		if(compteurAnimation == DIV_FREQ_ANIMATION) 
		{
			b=!b;
			compteurAnimation=0;
		}

		perso1.setTexture(texture[a][b]);
		
	}

	


	window.clear();

	window.draw(perso1);

	window.display();
}

return 0;
}
