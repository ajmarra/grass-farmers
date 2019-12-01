#include "iostream"

#include "actor.h"
#include "item.h"
#include "melee_weapon.h"
#include "room.h"
#include "enemy_view.h"

#include <math.h>
#define PI 3.14159265

MeleeWeapon::MeleeWeapon(double x, double y, double width, double height, int damage, int speed, std::shared_ptr<Character> character) :
	Item(ActorType::MELEEWEAPON, x, y, width, height, 1, false, character) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->speed = speed;
	
}

void MeleeWeapon::use(int x, int y) {
	
	double direction = atan2(y - this->character->getCurrentRoom()->getFred()->getCenterY(), x - this->character->getCurrentRoom()->getFred()->getCenterX())*180/PI;
	if (!loading){			

	if (this->character->getCurrentRoom()->getEnemyList().size() > 0) {
		for (std::shared_ptr<Enemy> enemy : this->character->getCurrentRoom()->getEnemyList()) {
			
			//up sweep
			if (direction >= -135.0 && direction < -45.0){
				if ((enemy->getCenterY() < this->character->getCurrentRoom()->getFred()->getCenterY()) ){
					if (abs(enemy->getCenterY() - this->character->getCurrentRoom()->getFred()->getCenterY()) <= distance){
						enemy->damage(20);

			}}}

			//left sweep
			else if ((direction < -135.0 && direction >= -180.0 )||( direction <= 180.0 && direction > 135.0)) {
				if (enemy->getCenterX() < this->character->getCurrentRoom()->getFred()->getCenterX()){
					if (abs((enemy->getCenterX() - this->character->getCurrentRoom()->getFred()->getCenterX())) <= distance)
					{
						enemy->damage(20);

			}}}

			// //down sweep
    		else if (direction <= 135.0 && direction > 45.0) {
				if (enemy->getCenterY() > this->character->getCurrentRoom()->getFred()->getCenterY()){
					if (abs( enemy->getCenterY() - this->character->getCurrentRoom()->getFred()->getCenterY()) <= distance){
							enemy->damage(20);
					}}}

			//right sweep
   			else if ((direction < 45.0 && direction > 0.0) || (direction >= -45.0 && direction < 0.0)){
				if (enemy->getCenterX() > this->character->getCurrentRoom()->getFred()->getCenterX()){
					if (abs(enemy->getCenterX() - this->character->getCurrentRoom()->getFred()->getCenterX()) <= distance) 
					{
							enemy->damage(20);
				}}}
			loading = true;
			elapsedTime = 0;
			std::cout << "GOODBYE" <<std::endl;
}}}}

void MeleeWeapon::update(float delta) {
	elapsedTime = elapsedTime + delta;
	if (elapsedTime >= reloadRate){
		//std::cout << "HELLO" <<std::endl;
		loading = false;
	}

}