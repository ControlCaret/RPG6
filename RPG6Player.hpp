﻿#pragma once

class Player
{
private:
    std::string name;
    int health;
    int maxhealth;
    int damage;
    int level;
    int floor;
    int upgrade;
    int hgrade;
    int gold;
    int potion1;
    int potion2;
    int potion3;
    int shield;

public:
    Player(std::string name, int health, int maxhealth, int damage, int level, int floor, int upgrade, int hgrade, int gold, int potion1, int potion2, int potion3, int shield);
    std::string getName();
    int getHealth();
    int maxHealth();
    int getDamage();
    int getLevel();
    int getFloor();
    int getUpgrade();
    int getHgrade();
    int getGold();
    int getPotion1();
    int getPotion2();
    int getPotion3();
    int getShield();
    void setHealth(int health);
    void setDamage(int damage);
    void setLevel(int level);
    void nextFloor();
    void doUpgrade();
    void doHgrade();
    void setGold(int gold);
    void setPotion1(int potion1);
    void setPotion2(int potion2);
    void setPotion3(int potion3);
    void setShield(int shield);
};

Player::Player(std::string name, int health, int maxhealth, int damage, int level, int floor, int upgrade, int hgrade, int gold, int potion1, int potion2, int potion3, int shield)
{
    this->name = name;
    this->health = health;
    this->maxhealth = maxhealth;
    this->damage = damage;
    this->level = level;
    this->floor = floor;
    this->upgrade = upgrade;
    this->hgrade = hgrade;
    this->gold = gold;
    this->potion1 = potion1;
    this->potion2 = potion2;
    this->potion3 = potion3;
    this->shield = shield;
}

std::string Player::getName()
{
    return this->name;
}

int Player::getHealth()
{
    return this->health;
}

int Player::maxHealth()
{
    return this->maxhealth;
}

int Player::getDamage()
{
    return this->damage;
}

int Player::getLevel()
{
    return this->level;
}

int Player::getFloor()
{
    return this->floor;
}

int Player::getUpgrade()
{
    return this->upgrade;
}

int Player::getHgrade()
{
    return this->hgrade;
}

int Player::getGold()
{
    return this->gold;
}

int Player::getPotion1()
{
    return this->potion1;
}

int Player::getPotion2()
{
    return this->potion2;
}

int Player::getPotion3()
{
    return this->potion3;
}

int Player::getShield()
{
    return this->shield;
}

void Player::setHealth(int health)
{
    this->health += health;
}

void Player::setDamage(int damage)
{
    this->damage += damage;
}

void Player::setLevel(int level)
{
    this->level = level;
}

void Player::nextFloor()
{
    this->floor += 1;
}

void Player::doUpgrade()
{
    this->upgrade += 1;
    this->damage = this->damage + (int)(this->upgrade / 5 + 1);
}

void Player::doHgrade()
{
    this->hgrade += 1;
    this->maxhealth = this->maxhealth + (int)(this->hgrade / 5 + 1);
    this->health = this->health + (int)(this->hgrade / 5 + 1);
}


void Player::setGold(int gold)
{
    this->gold += gold;
}

void Player::setPotion1(int potion1)
{
    this->potion1 += potion1;
}
void Player::setPotion2(int potion2)
{
    this->potion2 += potion2;
}
void Player::setPotion3(int potion3)
{
    this->potion3 += potion3;
}

void Player::setShield(int shield)
{
    this->shield += shield;
}

void showPlayerStatus(Player player)
{
    std::cout << "\t==================================" << '\n';
    std::cout << "\t||         플레이어 정보        ||" << '\n';
    std::cout << "\t==================================" << '\n';
    std::cout << "\t|이름: " << "" << player.getName() << "" << "\t층: " << player.getFloor() << "\t\t | \n";
    std::cout << "\t|체력: " << "\t" << player.getHealth() << " / " << player.maxHealth() << "\t" << "\t | \n";
    std::cout << "\t|공격력: " << "\t"<< player.getDamage() <<"\t" << "\t | \n";
    std::cout << "\t|공격력 강화: " << "\t"<<player.getUpgrade() <<"\t" << "\t | \n";
    std::cout << "\t|체력 강화: " << "\t"<< player.getHgrade() <<"\t" << "\t | \n";
	std::cout << "\t|골드: " << "\t" << player.getGold() << "\t" << "\t\t | \n";
    std::cout << "\t==================================" << '\n';
    std::cout << '\n';
}

void showPlayerItem(Player player, bool showNum)
{
    std::cout << "\t==========================================" << '\n';
    std::cout << "\t|\t\t보유 아이템" << "\t\t | \n";
    std::cout << "\t==========================================" << '\n';
    std::cout << "\t| 1. " << "\t20 % 포션: " << player.getPotion1() << "\t\t\t | \n";
    std::cout << "\t| 2. " << "\t50 % 포션: " << player.getPotion2() << "\t\t\t | \n";
    std::cout << "\t| 3. " << "\t80 % 포션: " << player.getPotion3() << "\t\t\t | \n";
    std::cout << "\t| 4. " << "\t방패: " << player.getShield() << "\t\t\t\t | \n";
    std::cout << "\t==========================================" << '\n';
}

void showShop(Player player)
{
    std::cout << "\t==========================================" << '\n';
    std::cout << "\t| \t\t  상점 " << "\t\t\t |\n";
    std::cout << "\t==========================================" << '\n';
	std::cout << "\t| 1. 포션" << "\t\t\t\t | \n";
	std::cout << "\t| 2. 쉴드: 40골드" << "\t\t\t | \n";
	std::cout << "\t| 3. 무기 업그레이드: " << 20 * (player.getUpgrade() / 5 +1) << "\t\t | \n";
    std::cout << "\t| 4. 체력 업그레이드: " << 20 * (player.getHgrade() / 5 + 1) << "\t\t | \n";
    std::cout << "\t==========================================" << '\n';
	showPlayerItem(player, false);
    std::cout << "\t| 현재 골드: " << "\t" << player.getGold() << " \t" << "\t\t | \n";
    std::cout << "\t| 현재 무기 단계: " << player.getUpgrade() << " / 현재 공격력 " << player.getDamage() << "\t | \n";
    std::cout << "\t| 현재 체력 단계: " << player.getHgrade() << " / 현재 체력 " << player.getHealth() << "\t | \n";
    std::cout << "\t==========================================" << '\n';
}

void showPotion(Player player)
{
    std::cout << "\t==========================================" << '\n';
    std::cout << "\t| \t\t  상점 " << "\t\t\t |\n";
    std::cout << "\t==========================================" << '\n';
    std::cout << "\t| 1. 20 % 회복 포션 : 20골드 " << "\t\t | \n";
    std::cout << "\t| 2. 50 % 회복 포션 : 50골드 " << "\t\t | \n";
    std::cout << "\t| 3. 80 % 회복 포션 : 80골드 " << "\t\t | \n";
    std::cout << "\t==========================================" << '\n';
    showPlayerItem(player, false);
    std::cout << "\t| 현재 골드: " << "\t" << player.getGold() << " \t" << "\t\t | \n";
    std::cout << "\t| 현재 무기 단계: " << player.getUpgrade() << " / 현재 공격력 " << player.getDamage() << "\t | \n";
    std::cout << "\t| 현재 체력 단계: " << player.getHgrade() << " / 현재 체력 " << player.getHealth() << "\t | \n";
    std::cout << "\t==========================================" << '\n';
}