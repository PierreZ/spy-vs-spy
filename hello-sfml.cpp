#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std; 

// Constantes
#define AGRANDISSEMENT 6

int main()
{


	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	
	Texture texture;
	Image image;
	Sprite perso1[4][2];
	int a=0,b=0;//orientatio perso

if (!image.loadFromFile("ressources/ennemi.png")) // Si le chargement du fichier a échoué
{
	cout<<"Erreur durant le chargement de l'image"<<endl;
return EXIT_FAILURE; // On ferme le programme
}
else // Si le chargement de l'image a réussi
{	
	Color bleu_transparence = Color(0,0,255);
	image.createMaskFromColor(bleu_transparence,0);
	texture.loadFromImage(image);//faire un tableau de textre
	texture.setSmooth(false);

	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{

			perso1[i][j].setTexture(texture);
			perso1[i][j].setTextureRect(IntRect((i*texture.getSize().y)/4, (j*texture.getSize().x)/2, ((i+1)*texture.getSize().x)/4, ((j+1)*texture.getSize().y)/2));
			perso1[i][j].setScale(AGRANDISSEMENT,AGRANDISSEMENT);
			
		}
	}
}

while (window.isOpen())
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		/*if (window.getInput().IsKeyDown(sf::Key::Left)) a=2;
		if (window.getInput().IsKeyDown(sf::Key::Right)) a=3;
		if (window.getInput().IsKeyDown(sf::Key::Up)) a=0;
		if (window.getInput().IsKeyDown(sf::Key::Down)) a=1;


		if(b==0) b=1;
		else b=0;*/
	}

	window.clear();

	window.draw(perso1[a][b]);

	window.display();
}

return 0;
}
