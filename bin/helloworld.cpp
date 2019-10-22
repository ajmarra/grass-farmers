// #include <SFML/Graphics.hpp>
// #include "../include/view/options_view.h"
#include "view/menu_view.h"


// int main(int argc, char** argv)
// {
  

// //start menu for game

// //initiate menuView - dummy initiator
//   // create main window
//   MenuView* menuView = new MenuView(); //initiate start menu


//   // start main loop
//   while(menuView-> menu_view.isOpen())
//   {
//     // process events
//     sf::Event Event;
//     while(menuView->menu_view.pollEvent(Event))
//     {
//       // Exit
//       if(Event.type == sf::Event::Closed)
//         menuView->menu_view.close();
//         return 0;

//       //menuView->goToOptionsMenu();
      

//     }

//     menuView->updateMenuView();
//   }

//   delete menuView;

//   // Done.
//   return 0;
// }

#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
  // create main window
   MenuView* menuView = new MenuView(); //initiate start menu

  //displays the start menu until the user chooses an enemy difficulty or closes the menu
  //when the user chooses an enemy difficulty, it will automatically close the menu and open the pong game view
  while(menuView->menuView.isOpen())
      {
        sf::Event Event;
        while(menuView->menuView.pollEvent(Event))

        {
          //close menu and exit game
           if(Event.type == sf::Event::Closed){
            menuView->menuView.close();
            return 0;
           }

    menuView->updateMenuView();
  }
      }
  // Done.
  return 0;
}
