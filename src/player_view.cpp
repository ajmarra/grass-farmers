#include "player_view.h"
#include "graphics.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include <math.h>
#define PI 3.14159265

PlayerView::PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Fred> fred, std::shared_ptr<sf::RenderWindow> window)
    : View(logic) {
    this->fred = fred;
    this->window = window;

    sky.setSize(sf::Vector2f(1200, 100));
    sky.setFillColor(sf::Color(25, 25, 112));

    darkness.setSize(sf::Vector2f(1200, 800));
    darkness.setPosition(0, 100);
    darkness.setFillColor(sf::Color(0, 0, 0, 150));

    portalSprite.spriteMap.loadFromFile("../resources/portalanim.png");
    portalSprite.spriteFrame.top = 0;//x
    portalSprite.spriteFrame.left = 0;//y
    portalSprite.spriteFrame.width = 128;
    portalSprite.spriteFrame.height = 128;


    // Play music
    cur_track.playNightTrack();

    // Load sprites    
    farm_image.spriteMap.loadFromFile("../resources/farmscreen.png");

    exit_image.spriteMap.loadFromFile("../resources/exit.png");

    gun1_image.spriteMap.loadFromFile("../resources/gun1.png");

    barn_image.spriteMap.loadFromFile("../resources/barn.png");

    health_image.spriteMap.loadFromFile("../resources/health_item.png");

    unused_trap_image.spriteMap.loadFromFile("../resources/unused_trap.png");

    trap_image.spriteMap.loadFromFile("../resources/trap.png");


    EnemySprite.spriteMap.loadFromFile("../resources/alienwalk.png");
    EnemySprite.spriteFrame.top = 64;//x
    EnemySprite.spriteFrame.left = 0;//y
    EnemySprite.spriteFrame.width = 64;
    EnemySprite.spriteFrame.height = 64;

    FredSprite.spriteMap.loadFromFile("../resources/fredWALK.png");
    FredSprite.spriteFrame.top = 64;//x
    FredSprite.spriteFrame.left = 0;//y
    FredSprite.spriteFrame.width = 64;
    FredSprite.spriteFrame.height = 64;

    if (!font.loadFromFile("../resources/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }

}

void PlayerView::pollInput() {
    sf::Event Event;

    // Use Item (mouse)
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->fred->getSelectedItem()) {
        if (this->fred->getSelectedItem()->getType() == ActorType::RANGEWEAPON) this->fred->useItem(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y);
        else if (this->elapsedTime > 0.5) {
            this->fred->useItem(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y);
            elapsedTime = 0;
        }
    }

    // Move
    int x = 0, y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x += 1;
    if (x == 0 && y == 0) fred->stop();
    else fred->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));
    
    // Open closet
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
        if (logic->isAtCloset()) {
//            while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//                drawScreen();
//                drawClosetMenu();
//            }
        }
    }
    
    // Pick up item
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) fred->addItem();

    // Drop item
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) fred->dropItem();

    // Temp button for testing Cheryl
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        this->logic->setNightCount(4); 
        this->switchToDay();
        this->logic->setDay(true);
    }

    // Inventory selection
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) fred->setSelectedIndex(0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) fred->setSelectedIndex(1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) fred->setSelectedIndex(2);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) fred->setSelectedIndex(3);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        //cur_track.stopCurrentTrack();
        this->logic->paused = true;
        this->logic->startPaused();
    }
}

void PlayerView::drawActor(Actor& a) {
    switch (a.getType()) {
        case ActorType::FRED:
        {
            sf::RectangleShape fredShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            fredShape.setTexture(&FredSprite.spriteMap);
            fredShape.setTextureRect(FredSprite.spriteFrame);
            fredShape.setPosition(a.getX(), a.getY());
            FredSprite.setFredSprite(fred->getDirection());
            this->window->draw(fredShape);
        }
            break;
        case ActorType::RANGEWEAPON:
        {
            sf::RectangleShape itemShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            itemShape.setTexture(&gun1_image.spriteMap);
            itemShape.setPosition(a.getX(), a.getY());
            this->window->draw(itemShape);
        }
            break;

        case ActorType::MELEEWEAPON:
        {
            sf::RectangleShape itemShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            itemShape.setFillColor(sf::Color::Magenta);
            itemShape.setPosition(a.getX(), a.getY());
            this->window->draw(itemShape);
        }
            break;

        case ActorType::ENEMY:
        {
            sf::RectangleShape enemyShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            enemyShape.setTexture(&EnemySprite.spriteMap);
            enemyShape.setTextureRect(EnemySprite.spriteFrame);
            enemyShape.setPosition(a.getX(), a.getY());
            EnemySprite.setEnemySprite(a.getDirection());
            this->window->draw(enemyShape);
        }
            break;
        case ActorType::BULLET:
        {
            sf::CircleShape bulletShape(a.getWidth());
            bulletShape.setFillColor(sf::Color::Green);
            bulletShape.setPosition(a.getX(), a.getY());
            this->window->draw(bulletShape);
        }
            break;
        case ActorType::BED:
        {
            sf::RectangleShape bedShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            bedShape.setFillColor(sf::Color::Magenta);
            bedShape.setPosition(a.getX(), a.getY());
            this->window->draw(bedShape);
        }
            break;
        case ActorType::CLOSET:
        {
            sf::RectangleShape closetShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            closetShape.setFillColor(sf::Color::Red);
            closetShape.setPosition(a.getX(), a.getY());
            this->window->draw(closetShape);
        }
            break;
        case ActorType::HEALTH:
        {
            sf::RectangleShape itemShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            itemShape.setTexture(&health_image.spriteMap);
            itemShape.setPosition(a.getX(), a.getY());
            this->window->draw(itemShape);
        }
            break;
        case ActorType::TRAP:
        {
            sf::RectangleShape itemShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            itemShape.setPosition(a.getX(), a.getY());
            itemShape.setTexture(&unused_trap_image.spriteMap);
            this->window->draw(itemShape);
        }
            break;
        case ActorType::EXIT:
        {
            if (this->logic->getCurrentRoom()->getFred()->getCenterX() < a.getCenterX()) {
                sf::RectangleShape itemShape(sf::Vector2f(a.getWidth(), a.getHeight()));
                itemShape.setTexture(&exit_image.spriteMap);
                itemShape.setPosition(a.getX(), a.getY());
                this->window->draw(itemShape);
            }
            else if (this->logic->getCurrentRoom()->getFred()->getCenterX() > a.getCenterX()) {
                sf::RectangleShape itemShape(sf::Vector2f(a.getWidth(), a.getHeight()));
                itemShape.setTexture(&exit_image.spriteMap);
                itemShape.setPosition(a.getX(), a.getY());

                sf::Transform transform;
                transform.rotate(180, a.getCenterX(), a.getCenterY());
                this->window->draw(itemShape, transform);
            }
        }
            break;
        case ActorType::PORTAL:
        {
            sf::RectangleShape sp1(sf::Vector2f(a.getWidth(), a.getHeight()));
            sp1.setTexture(&portalSprite.spriteMap);
            sp1.setTextureRect(portalSprite.spriteFrame);
            sp1.setPosition(a.getX(), a.getY());
            this->window->draw(sp1);
        }
            break;
        case ActorType::CHERYL:
        {
            sf::RectangleShape enemyShape(sf::Vector2f(a.getWidth(), a.getHeight()));
            enemyShape.setTexture(&EnemySprite.spriteMap);
            enemyShape.setTextureRect(EnemySprite.spriteFrame);
            enemyShape.setPosition(a.getX(), a.getY());
            EnemySprite.setEnemySprite(a.getDirection());
            this->window->draw(enemyShape);
        }
            break;
    }
}

void PlayerView::drawScreen(void) {
    this->window->clear(sf::Color::Black);

    this->window->draw(sky);

    //Timer
    sf::CircleShape clock;
    clock.setRadius(45);
    clock.setPosition(600, 5);
    clock.setFillColor(sf::Color::White);
    this->window->draw(clock);

    sf::RectangleShape clockMarker(sf::Vector2f(5, 10));
    clockMarker.setPosition(642.5, 7);
    clockMarker.setFillColor(sf::Color::Red);
    this->window->draw(clockMarker);

    sf::Transform transform;
    transform.rotate(this->logic->getTimer()->getCurTime(), { 645, 50 });
    sf::RectangleShape clockHand(sf::Vector2f(5, 42.5));
    clockHand.setPosition(642.5, 10);
    clockHand.setFillColor(sf::Color::Black);
    this->window->draw(clockHand, transform);

    //Current room
    sf::RectangleShape room;
    room.setSize(sf::Vector2f(logic->getCurrentRoom()->getWidth(), logic->getCurrentRoom()->getHeight()));
    room.setPosition(logic->getCurrentRoom()->getX(), logic->getCurrentRoom()->getY());
    if (logic->getCurrentRoom()->getHeight() >= 800) room.setTexture(&farm_image.spriteMap);
    else room.setTexture(&barn_image.spriteMap);
    this->window->draw(room);

    if (night) this->window->draw(darkness);

    //Fred's Health Bar
    sf::RectangleShape healthBar(sf::Vector2f(5 * fred->getHealth(), 20));
    healthBar.setPosition(10, 20);
    healthBar.setFillColor(sf::Color::Blue);

    this->window->draw(healthBar);

    //Fred's Busy Bar
    sf::RectangleShape busyBar(sf::Vector2f(logic->getCurrentRoom()->getFred()->getSleepTime() * 50, 20));
    busyBar.setPosition(10, 60);
    busyBar.setFillColor(sf::Color::Yellow);

    this->window->draw(busyBar);

    // Hard coded inventory blocks
    sf::RectangleShape inventoryBlock1(sf::Vector2f(75, 75));
    sf::RectangleShape inventoryBlock2(sf::Vector2f(75, 75));
    sf::RectangleShape inventoryBlock3(sf::Vector2f(75, 75));
    sf::RectangleShape inventoryBlock4(sf::Vector2f(75, 75));

    if (fred->getSelectedIndex() == 0) inventoryBlock1.setOutlineColor(sf::Color::Red);
    else inventoryBlock1.setOutlineColor(sf::Color::White);
    inventoryBlock1.setPosition(800, 12);
    inventoryBlock1.setOutlineThickness(5);
    inventoryBlock1.setFillColor(sf::Color::Black);
    if (fred->getSelectedIndex() == 1) inventoryBlock2.setOutlineColor(sf::Color::Red);
    else inventoryBlock2.setOutlineColor(sf::Color::White);
    inventoryBlock2.setPosition(900, 12);
    inventoryBlock2.setOutlineThickness(5);
    inventoryBlock2.setFillColor(sf::Color::Black);
    if (fred->getSelectedIndex() == 2) inventoryBlock3.setOutlineColor(sf::Color::Red);
    else inventoryBlock3.setOutlineColor(sf::Color::White);
    inventoryBlock3.setPosition(1000, 12);
    inventoryBlock3.setOutlineThickness(5);
    inventoryBlock3.setFillColor(sf::Color::Black);
    if (fred->getSelectedIndex() == 3) inventoryBlock4.setOutlineColor(sf::Color::Red);
    else inventoryBlock4.setOutlineColor(sf::Color::White);
    inventoryBlock4.setPosition(1100, 12);
    inventoryBlock4.setOutlineThickness(5);
    inventoryBlock4.setFillColor(sf::Color::Black);

    this->window->draw(inventoryBlock1);
    this->window->draw(inventoryBlock2);
    this->window->draw(inventoryBlock3);
    this->window->draw(inventoryBlock4);

    // draw fred's inventory
    for (int i = 0; i < 4; i++) {
        if (this->fred->getInventory()[i]) {
            this->drawActor(*this->fred->getInventory()[i]);

            // draw reload bar
            sf::RectangleShape reloadBar(sf::Vector2f(this->fred->getInventory()[i]->getReloading() / this->fred->getInventory()[i]->getLoadTime() * 30.0, 5));
            reloadBar.setPosition(this->fred->getInventory()[i]->getCenterX() - 15, this->fred->getInventory()[i]->getY() + this->fred->getInventory()[i]->getHeight() + 5);
            reloadBar.setFillColor(sf::Color::Yellow);
            this->window->draw(reloadBar);

            if (this->fred->getInventory()[i] && this->fred->getInventory()[i]->getQuantity() > 1) {
                sf::Text numText;
                numText.setFont(font);
                numText.setString(std::to_string(this->fred->getInventory()[i]->getQuantity()));
                numText.setCharacterSize(25); // in pixels, not points!
                numText.setFillColor(sf::Color::White);
                numText.setStyle(sf::Text::Bold);
                numText.setPosition(this->fred->getInventory()[i]->getCenterX() - 3, this->fred->getInventory()[i]->getCenterY() + 5);
                this->window->draw(numText);
            }
        }
    }

    // draw portals
    for (std::shared_ptr<Actor> actor : this->logic->getCurrentRoom()->getPortalList()) this->drawActor(*actor);

    // draw items
    for (std::shared_ptr<Item> actor : this->logic->getCurrentRoom()->getItemList()) {
        this->drawActor(*actor);
    }


    // draw set traps
    for (std::shared_ptr<Item> item : this->logic->getCurrentRoom()->getItemList()) {
        if (item->getType() == ActorType::TRAP && !item->getCanPickUp()) {
            sf::RectangleShape itemShape(sf::Vector2f(item->getWidth(), item->getHeight()));
            itemShape.setPosition(item->getX(), item->getY());
            itemShape.setTexture(&trap_image.spriteMap);
            this->window->draw(itemShape);
        }
    }

    // draw exits
    for (std::shared_ptr<Actor> actor : this->logic->getCurrentRoom()->getExitList()) this->drawActor(*actor);

    // draw bullets
    for (std::shared_ptr<Actor> actor : this->logic->getCurrentRoom()->getBulletList()) this->drawActor(*actor);

    // draw enemies
    for (std::shared_ptr<Enemy> actor : this->logic->getCurrentRoom()->getEnemyList()) {
        this->drawActor(*actor);
        
        if (actor->getHealth() != actor->getMaxHealth()) {
            // draw health bars
            sf::RectangleShape healthBar(sf::Vector2f(float(actor->getHealth()) / float(actor->getMaxHealth()) * 30.0, 5));
            healthBar.setPosition(actor->getCenterX() - 15, actor->getY() - 10);
            healthBar.setFillColor(sf::Color::Red);
            this->window->draw(healthBar);
            
            sf::RectangleShape fullHealthBar(sf::Vector2f(30, 5));
            fullHealthBar.setPosition(actor->getCenterX() - 15, actor->getY() - 10);
            fullHealthBar.setFillColor(sf::Color::Transparent);
            fullHealthBar.setOutlineThickness(1.5);
            fullHealthBar.setOutlineColor(sf::Color::Black);
            
            this->window->draw(fullHealthBar);
        }
    }
    
    // draw furniture
    for (std::shared_ptr<Actor> actor : this->logic->getCurrentRoom()->getActorList()) {
        if (actor->getType() == ActorType::BED || actor->getType() == ActorType::CLOSET) {
            this->drawActor(*actor);

            
        }
    }

    // draw Fred
    this->drawActor(*this->logic->getCurrentRoom()->getFred());
}

void PlayerView::switchToDay() {
    cur_track.stopCurrentTrack();
    cur_track.playDayTrack();
    sky.setFillColor(sf::Color(0, 191, 255));
    night = false;
}

void PlayerView::switchToNight() {
    cur_track.stopCurrentTrack();
    cur_track.playNightTrack();
    sky.setFillColor(sf::Color(25, 25, 112));
    night = true;
}

void PlayerView::update(float delta) {

    elapsedTime += delta;

    this->pollInput();

    FredSprite.updateFred(delta);
    portalSprite.updatePortal(delta);

    EnemySprite.updateEnemy(delta);
    this->drawScreen();
}

void PlayerView::drawClosetMenu() {
//    sf::RectangleShape closetBlock1(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock2(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock3(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock4(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock5(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock6(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock7(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock8(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock9(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock10(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock11(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock12(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock13(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock14(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock15(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock16(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock17(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock18(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock19(sf::Vector2f(75, 75));
//    sf::RectangleShape closetBlock20(sf::Vector2f(75, 75));
//
//    if (fred->getSelectedClosetIndex() == 0) inventoryBlock1.setOutlineColor(sf::Color::Red);
//    else inventoryBlock1.setOutlineColor(sf::Color::White);
//    inventoryBlock1.setPosition(400, 75);
//    inventoryBlock1.setOutlineThickness(5);
//    inventoryBlock1.setFillColor(sf::Color::Black);
//    if (fred->getSelectedClosetIndex() == 1) inventoryBlock2.setOutlineColor(sf::Color::Red);
//    else inventoryBlock2.setOutlineColor(sf::Color::White);
//    inventoryBlock2.setPosition(500, 75);
//    inventoryBlock2.setOutlineThickness(5);
//    inventoryBlock2.setFillColor(sf::Color::Black);
//    if (fred->getSelectedClosetIndex() == 2) inventoryBlock3.setOutlineColor(sf::Color::Red);
//    else inventoryBlock3.setOutlineColor(sf::Color::White);
//    inventoryBlock3.setPosition(600, 100);
//    inventoryBlock3.setOutlineThickness(5);
//    inventoryBlock3.setFillColor(sf::Color::Black);
//    if (fred->getSelectedClosetIndex() == 3) inventoryBlock4.setOutlineColor(sf::Color::Red);
//    else inventoryBlock4.setOutlineColor(sf::Color::White);
//    inventoryBlock4.setPosition(700, 75);
//    inventoryBlock4.setOutlineThickness(5);
//    inventoryBlock4.setFillColor(sf::Color::Black);
//
//    this->window->draw(inventoryBlock1);
//    this->window->draw(inventoryBlock2);
//    this->window->draw(inventoryBlock3);
//    this->window->draw(inventoryBlock4);
    
//    if (fred->getSelectedClosetIndex() == 4) inventoryBlock1.setOutlineColor(sf::Color::Red);
//    else inventoryBlock1.setOutlineColor(sf::Color::White);
//    inventoryBlock1.setPosition(800, 12);
//    inventoryBlock1.setOutlineThickness(5);
//    inventoryBlock1.setFillColor(sf::Color::Black);
//    if (fred->getSelectedClosetIndex() == 5) inventoryBlock2.setOutlineColor(sf::Color::Red);
//    else inventoryBlock2.setOutlineColor(sf::Color::White);
//    inventoryBlock2.setPosition(900, 12);
//    inventoryBlock2.setOutlineThickness(5);
//    inventoryBlock2.setFillColor(sf::Color::Black);
//    if (fred->getSelectedClosetIndex() == 6) inventoryBlock3.setOutlineColor(sf::Color::Red);
//    else inventoryBlock3.setOutlineColor(sf::Color::White);
//    inventoryBlock3.setPosition(1000, 12);
//    inventoryBlock3.setOutlineThickness(5);
//    inventoryBlock3.setFillColor(sf::Color::Black);
//    if (fred->getSelectedClosetIndex() == 7) inventoryBlock4.setOutlineColor(sf::Color::Red);
//    else inventoryBlock4.setOutlineColor(sf::Color::White);
//    inventoryBlock4.setPosition(1100, 12);
//    inventoryBlock4.setOutlineThickness(5);
//    inventoryBlock4.setFillColor(sf::Color::Black);
}
