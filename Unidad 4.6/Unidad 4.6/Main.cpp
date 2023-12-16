//Bibliotecas//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Juego.h"
#include "stdafx.h"

using namespace sf;


//Entrada//

int main(int argc, char* argv[])
{


	Juego myJuego;
	myJuego.Loop();

	return 0;

}

//Utilice el mismo codigo agregando modificaciones para el trabajo de la unidad 6.4