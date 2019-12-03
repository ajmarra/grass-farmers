#include "story_view.h"

StoryView::StoryView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window)
: View(logic) {
    this->window = window;
    
    if (!font.loadFromFile("../resources/Amatic-Bold.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    inFile.open("../resources/story.txt");
    if (!inFile) {
        std::cout << "Unable to open story.txt";
        exit(1);
    }
    
    fade.setPosition(sf::Vector2f(0,0));
    fade.setFillColor(sf::Color(0,0,0,244));
    fade.setSize(sf::Vector2f(1200,1200));
    fadeCoefficient = 500;
}

void StoryView::pollInput() {
    sf::Event Event;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->logic->story = false;
    }
}

void StoryView::updateText() {
    std::string str = "";
    std::string curStr;
    curHeight = 180;
    
    textList.clear();
    std::shared_ptr<sf::Text> curText = std::make_shared<sf::Text>();
    textList.push_back(curText);
    std::list<std::shared_ptr<sf::Text>>::iterator it = textList.begin();
    
    it->get()->setPosition(180, curHeight);
    it->get()->setFont(font);
    it->get()->setFillColor(sf::Color::White);
    it->get()->setStyle(sf::Text::Bold);
    it->get()->setCharacterSize(80);
    it->get()->setString(str);
    
    while (inFile >> curStr && curStr != ".?") {
        str.append(curStr);
        str.append(" ");
        it->get()->setString(str);
        sf::FloatRect endTextPos = it->get()->getGlobalBounds();
        if (endTextPos.left + endTextPos.width >= 950) {
            curText = std::make_shared<sf::Text>();
            textList.push_back(curText);
            
            curHeight += 100;

            std::advance(it, 1);

            str = "";

            it->get()->setPosition(180, curHeight);
            it->get()->setFont(font);
            it->get()->setFillColor(sf::Color::White);
            it->get()->setStyle(sf::Text::Bold);
            it->get()->setCharacterSize(80);
            it->get()->setString(str);
        }
    }
    
//    if (inFile >> str) {
//        // Do nothing
//    }
}

void StoryView::update(float delta) {
    this->window->clear(sf::Color::Black);
    
    for (std::shared_ptr<sf::Text> curText : this->textList) {
        this->window->draw(*curText);
    }
    
    if (fadeCoefficient > 0) {
        fadeCoefficient--;
        fade.setFillColor(sf::Color(0,0,0,fadeCoefficient));
    }
    
    this->window->draw(fade);
    this->pollInput();
}
