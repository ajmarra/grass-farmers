// #include <SFML/Graphics.hpp>
// #include "../include/view/options_view.h"
#include "screen_control.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv)
{
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Fred the Farmer");

   //for game clock
  sf::Clock clock;
  float delta;
  

  sf::Font font;
  if (!font.loadFromFile("../resources/bit5x3.ttf"))
  {
	  // error...
	  std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
  }

  // create main window
  ScreenController* ScreenControl = new ScreenController(App, font); //initiate start menu

  //displays the start menu until the user chooses an enemy difficulty or closes the menu
  //when the user chooses an enemy difficulty, it will automatically close the menu and open the pong game view
  while(App.isOpen())
      {
        //game loop
        delta = clock.getElapsedTime().asSeconds(); //can change to milliseconds if necessary
        clock.restart();

        ScreenControl->update(App);
        sf::Event Event;
        while(App.pollEvent(Event))

        {
          //close menu and exit game
           if(Event.type == sf::Event::Closed){
            App.close();
            return 0;
           }
           ScreenControl->switchScreens(App, Event, font, delta);
  }
  
      

      
      

      }

  // Done.
  return 0;
}
