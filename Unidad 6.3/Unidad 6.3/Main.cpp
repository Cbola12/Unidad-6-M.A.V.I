#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
	//crear ventana SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Caida Libre");

	//definir posicion inicial y velocidad inicial 
	sf::Vector2f position(300.0f, 50.0f);
	sf::Vector2f velocity(0.0f, 0.0f);

	//constante de gravedad para la caida libre

	const float gravity = 0.000098f;

	const float rebote = 0.7f;

	//bucle principal juego

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//actualizar velocidad segub la gravedad

		velocity.y += gravity;

		// actualizar posicion en funcion a la gravedad

		position += velocity;

		//comprobar si la bola llego al suelo

		if (position.y > 600.0f)
		{

			position.y = 600.0f;
			velocity.y = -velocity.y * rebote;
		}

		//limpiar ventana
		window.clear();

		//dibujar bola pos actual
		sf::CircleShape ball(30.0f);
		ball.setFillColor(sf::Color::Blue);
		ball.setPosition(position);
		window.draw(ball);

		//mostrar todo en ventana
		window.display();
	}
	return 0;
}
