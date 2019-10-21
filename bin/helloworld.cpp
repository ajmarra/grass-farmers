#include <SFML/Graphics.hpp>
#include <logic/item.h>
#include <view/item_view.h>

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Hello World - SFML");

  Item item = Item(-400, -300, 1, false);
  ItemView itemView = ItemView(item.getX(), item.getY(), 1, false);

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

	// Drawing an item
	App.draw(itemView.getItemShape());

    // display
    App.display();
  }

  // Done.
  return 0;
}
