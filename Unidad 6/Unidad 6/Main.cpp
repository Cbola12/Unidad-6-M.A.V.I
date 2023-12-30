//Bibliotecas
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {

	//crer ventana sfml
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ejercicio 1");

	//definir pos inicial
	sf::Vector2f position(100.0f, 250);
	float velocidadInicial = 3.5f;
	float velocidad = velocidadInicial;
	float incrementoVelocidad = 10.0f;

	


	//bucle principal del juego
	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				App.close();

		}

		
		float deltaTime = 0.50f / 60.0f; //suponiendo q el juego corra a 60 fps

		position.x += velocidad * deltaTime;

		if (position.x > App.getSize().x)
		{

			position.x = -50.0f;

			velocidad += incrementoVelocidad;
		}




		//limpiar ventana
		App.clear();

		//dibujar objeto

		sf::CircleShape object(50.0f);
		object.setPosition(position);
		object.setFillColor(sf::Color::Blue);
		App.draw(object);

		//mostrar todo en la ventana
		App.display();

	}
	return 0;
}