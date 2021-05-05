#include <sstream>
#include "SFML/Graphics.hpp"


int main(int argc, char const *argv[])
{
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
  window.setFramerateLimit(60);
  sf::Clock deltaClock;

  sf::Text clock_time;
  clock_time.setPosition(700, 50);
  sf::Font font;
  font.loadFromFile("/home/mogens/Downloads/font/Times New Roman/@font-face/32441506567156636049eb850b53f02a.ttf");
  clock_time.setFont(font);
  clock_time.setCharacterSize(34);
  clock_time.setFillColor(sf::Color::White);
  std::stringstream ss;


  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window.close();
    }

    // clear the window with black color
    window.clear();

    sf::Texture greenhouse_sprite;
    if(!greenhouse_sprite.loadFromFile("/home/mogens/CLionProjects/greenhouse-sim/sprites/greenhouse.png"))
        {
        return EXIT_FAILURE;
        }
    ss.str(std::string());
    sf::Sprite sprite(greenhouse_sprite);
    sf::Time elapTime1 = deltaClock.getElapsedTime();
    int minutes = elapTime1.asSeconds()/60;
    int hour = 0;
    if(minutes == 60) {
        deltaClock.restart();
        minutes = elapTime1.asSeconds() / 60;
        hour++;
    }
    if(hour == 24){
        hour = 0;
    }




    ss << std::to_string(hour) << ':' << std::to_string(minutes);
    clock_time.setString(ss.str());
    window.draw(sprite);
    window.draw(clock_time);

    // end the current frame
    window.display();
  }

  return 0;
}
