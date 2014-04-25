/*
    This program is a clone of Spy vs Spy
    Copyright (C) 2014 Corentin RAOULT - Pierre ZEMB

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "level.hpp"
#include "constantes.hpp"

    Level::Level()
    {
    	//nomBackground_bases[0]="ressources/background_base1.png";
    	//nomBackground_bases[1]="ressources/background_base2.png";

    	//Background *salle1=new Background("ressources/background_base1.png",0,1,0,0);
    	//Background *salle2=new Background("ressources/background_base2.png",1,0,0,0);



    	string nomImage1="ressources/background_base1.png";   
    	string nomImage2="ressources/background_base2.png";
    	//Background *test = new Background();
    	//test->loadImage(nomImage1);	    

    	tabBackground=fonction_allocation(4,2);


    	tabBackground[0][0].loadImage( nomImage1);
    	tabBackground[0][0].createBackground(0,1,0,1);
    	
    	tabBackground[0][1].loadImage( nomImage1);
    	tabBackground[0][1].createBackground(1,0,0,1);

    	tabBackground[1][0].loadImage( nomImage1);
    	tabBackground[1][0].createBackground(0,1,1,0);
    	
    	tabBackground[1][1].loadImage( nomImage1);
    	tabBackground[1][1].createBackground(1,0,1,0);

   }

    Level::~Level()
    {

    }

    Background ** Level::getTabBackground()
    {
    	return tabBackground;//return
    }



    Background ** Level::fonction_allocation(int nb_col, int nb_lin)
    {
    	Background** tab = new Background*[nb_col];
    	for (int o = 0; o < nb_col; o++)
    		tab[o] = new Background[nb_lin];

		return tab;//retour du pointeur sur l'espace alloué
	}