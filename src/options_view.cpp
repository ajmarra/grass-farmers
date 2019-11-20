#include "options_view.h"
#include "master_logic.h"
#include "master_view.h"
#include <iostream>

OptionsView::OptionsView(std::shared_ptr<MasterLogic> &logic,  std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
        this->window = window;

        options_image.spriteMap.loadFromFile("../resources/optionsscreen.png");
        if (!font.loadFromFile("../resources/Amatic-Bold.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    }

void OptionsView::configureKeys(sf::Event &Event){
    // std::cout << Event.text.unicode << std::endl;
    //std::cout << Event. << std::endl;
    std::cout << Event.key.code << std::endl;

    
    //if(Event == sf::Keyboard::Up){
        *selected = sf::Keyboard::Up;
        
        UpPress = Event.key.code;
        //UpPress_string;
        UpPress_string = "UP";   

}

void OptionsView::pollInput() {
    sf::Event Event;
    while (this->logic->options == true){
    while (window->pollEvent(Event)){

    std::cout << Event.text.unicode << std::endl;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = false;

    }//}

    if(Event.type == sf::Event::KeyPressed){
        if (Event.key.code == sf::Keyboard::Down) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = false;
        }
    }
    // if(Event.type == sf::Event::KeyPressed){
    //     if (Event.key.code == sf::Keyboard::M) {
    //     this->logic->paused = true;
    //     this->logic->playing = false;
    //     this->logic->options = false;
    //     }

    //     else if (Event.key.code == sf::Keyboard::Up)
    //     {
    //      std::cout << Event.key.code << std::endl;
    //     configureKeys(Event);
    break;
    }
    
    // }}
}}


void OptionsView::update(float delta){

    this -> pollInput();

    this-> drawScreen();

}

void OptionsView::drawScreen(){
    this->window->clear(sf::Color::Black);

    //sf::RectangleShape options;
    
    options.setSize(sf::Vector2f(1200, 900));
    options.setTexture(&options_image.spriteMap);
    

    //sf::Text options_message;
    options_message.setFont(font);
    options_message.setString("OPTIONS MENU");
    options_message.setCharacterSize(100); // in pixels, not points!
    options_message.setFillColor(sf::Color::White);
    options_message.setStyle(sf::Text::Bold);
    options_message.setPosition(400, 50);

    UpPress_message.setFont(font);
    UpPress_message.setString("UP KEY:"+ UpPress_string);
    UpPress_message.setCharacterSize(100); // in pixels, not points!
    UpPress_message.setFillColor(sf::Color::White);
    UpPress_message.setStyle(sf::Text::Bold);
    UpPress_message.setPosition(200, 200);
    

    this->window->draw(options);
    this->window->draw(options_message);
    this->window->draw(UpPress_message);
    this->window->display();
}