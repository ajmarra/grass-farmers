// #include <SFML/Graphics.hpp>
// #include "../include/view/options_view.h"
#include "view/screen_control.h"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Fred the Farmer");
  // create main window
  ScreenController* ScreenControl = new ScreenController(App); //initiate start menu

  //displays the start menu until the user chooses an enemy difficulty or closes the menu
  //when the user chooses an enemy difficulty, it will automatically close the menu and open the pong game view
  while(App.isOpen())
      {
        sf::Event Event;
        while(App.pollEvent(Event))

        {
          //close menu and exit game
           if(Event.type == sf::Event::Closed){
            App.close();
            return 0;
           }
           ScreenControl->switchScreens(App, Event);
  }
  
      }
  // Done.
  return 0;
}
