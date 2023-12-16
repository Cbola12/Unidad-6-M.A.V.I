#pragma once

#include "stdafx.h"

using namespace sf;

class Enemigo
{
	Texture tex_enemigo;
	Sprite enemigo;
	bool estaVivo;
	bool visible;

	Vector2f randomPos(Vector2u maxPos) {
		Vector2f random((float)(rand() % maxPos.x), (float)(rand() % maxPos.y));
		return random;
	}

	sf::Clock reloj;
	float tiempoVisible;
	float tiempoApagado;

	
	float velocidad;
	
	float aceleracion;
	
	

public:

	Enemigo(){

		tex_enemigo.loadFromFile("et.png");
		enemigo.setTexture(tex_enemigo);
		enemigo.setScale(0.1f, 0.1f);
		estaVivo = true;
		visible = false;
		tiempoVisible = 1.0f;
		tiempoApagado = 0.8f;
		velocidad = 0.08f;
		

		
	}


	bool Vivo() {

		return estaVivo;

	}

	bool activo () {

		return estaVivo && visible;
	}

	bool Encima(float x, float y) {
		FloatRect bounds = enemigo.getGlobalBounds();

		return bounds.contains(x, y);
	}

	void MuerteEnemy() {

		estaVivo = false;
	}

	void Dibujar(RenderWindow& wnd) {
		wnd.draw(enemigo);
	}

	void Actualizar(RenderWindow& wnd) {
		if (!estaVivo)
			return;


		



		if (!visible) {
			if (reloj.getElapsedTime().asSeconds() > tiempoApagado) {

				reloj.restart();

				if (rand() % 100 < 25) {
					visible = true;
					enemigo.setPosition(randomPos(wnd.getSize()));
				}

			}
		}
		else {
			


			
			enemigo.move(velocidad, 0.0f);



			if (reloj.getElapsedTime().asSeconds() > tiempoVisible) {
				visible = false;
				reloj.restart();
			}
		}


	}

	


};