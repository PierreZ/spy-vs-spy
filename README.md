
SPY VS SPY FOR ISEN !

It needs version 2.1 of the SFML.


exemple De Makefile:


all: spy-vs-spy

spy-vs-spy: event_loop.o FenetreJoueur.o personnage.o background.o level.o constantes.o 
	g++ event_loop.o FenetreJoueur.o personnage.o background.o level.o constantes.o -o spy-vs-spy -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

event_loop.o: event_loop.cpp
	g++ -c event_loop.cpp -L/usr/local/include

FenetreJoueur.o: FenetreJoueur.cpp FenetreJoueur.hpp
	g++ -c FenetreJoueur.cpp -L/usr/local/include

personnage.o: personnage.cpp personnage.hpp
	g++ -c personnage.cpp -L/usr/local/include

background.o: background.cpp background.hpp
	g++ -c background.cpp -L/usr/local/include

level.o: level.cpp level.hpp
	g++ -c level.cpp -L/usr/local/include

constantes.o: constantes.cpp constantes.hpp
	g++ -c constantes.cpp -L/usr/local/include

clean :
	rm *.o

# suppression de tous les fichiers, sauf les sources,
# en vue d'une reconstruction complète
mrproper: clean
	rm -rf spy-vs-spy
