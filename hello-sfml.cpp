#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// Constantes
#define AGRANDISSEMENT 6


using namespace sf;
using namespace std;


int main()
{
    RenderWindow app(sf::VideoMode(800, 600), "SFML Window");

    Clock Clock;
    float Framerate = 1.f / Clock.GetElapsedTime();
    app.SetFramerateLimit(11); // Limite à 60 images par seconde 

    Image image;
    Sprite perso1[4][2];
    int a=0,b=0;//orientatio perso

    if (!image.LoadFromFile("ressources/ennemi.png")) // Si le chargement du fichier a échoué
    {
        cout<<"Erreur durant le chargement de l'image"<<endl;
     return EXIT_FAILURE; // On ferme le programme
    }
    else //  Si le chargement de l'image a réussi
    {

        image.SetSmooth(false);


        int i,j;
        for(i=0;i<4;i++)
        {
            for(j=0;j<2;j++)
            {
                perso1[i][j].SetImage(image);
                perso1[i][j].SetSubRect(IntRect((i*image.GetWidth())/4, (j*image.GetHeight())/2, ((i+1)*image.GetWidth())/4, ((j+1)*image.GetHeight())/2));  
                perso1[i][j].Resize(image.GetHeight()*AGRANDISSEMENT,image.GetWidth()*AGRANDISSEMENT);
            }
        }

                
        Color bleu_transparence = Color(0,0,255);
        image.CreateMaskFromColor(bleu_transparence,0);
       
    }

   float ElapsedTime = Clock.GetElapsedTime();


    // Boucle principale
    while (app.IsOpened())
    {
        Event event;
        while (app.GetEvent(event))
        {
            // Fenêtre fermée : on quitte
            if (event.Type == Event::Closed)
                app.Close();
        }

        // Efface l'écran (remplissage avec du noir)
        app.Clear();

        if(event.Type == sf::Event::KeyPressed)
        {
            if (app.GetInput().IsKeyDown(sf::Key::Left))  a=2;
            if (app.GetInput().IsKeyDown(sf::Key::Right)) a=3;
            if (app.GetInput().IsKeyDown(sf::Key::Up))    a=0;
            if (app.GetInput().IsKeyDown(sf::Key::Down))  a=1;

            
           // if(ElapsedTime>10)
            //{
                ElapsedTime = Clock.GetElapsedTime();
                Clock.Reset();
                if(b==0) b=1;
                else b=0;
           //}
            
        }
  
        
        // Affichage de nos parties de zozor
        app.Draw(perso1[a][b]);
 

        // Affichage du contenu de la fenêtre à l'écran
        app.Display();
    }
    return 0;
}
