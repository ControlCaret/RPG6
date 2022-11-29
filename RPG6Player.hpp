#pragma once

class Player
{
private:
    std::string name;
    int health;
    int damage;
    int level;
    int floor;
    int upgrade;
    int gold;
    int potion;
    int shield;

public:
    Player(std::string name, int health, int damage, int level, int floor, int upgrade, int gold, int potion, int shield);
    std::string getName();
    int getHealth();
    int getDamage();
    int getLevel();
    int getFloor();
    int getUpgrade();
    int getGold();
    int getPotion();
    int getShield();
    void setHealth(int health);
    void setDamage(int damage);
    void setLevel(int level);
    void nextFloor();
    void doUpgrade();
    void setGold(int gold);
    void setPotion(int potion);
    void setShield(int shield);
};

Player::Player(std::string name, int health, int damage, int level, int floor, int upgrade, int gold, int potion, int shield)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
    this->level = level;
    this->floor = floor;
    this->upgrade = upgrade;
    this->gold = gold;
    this->potion = potion;
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

int Player::getGold()
{
    return this->gold;
}

int Player::getPotion()
{
    return this->potion;
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
    this->damage = damage;
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
}

void Player::setGold(int gold)
{
    this->gold += gold;
}

void Player::setPotion(int potion)
{
    this->potion += potion;
}

void Player::setShield(int shield)
{
    this->shield += shield;
}

void showPlayerStatus(Player player)
{
    std::cout << "========================" << std::endl;
    std::cout << "이름: " << player.getName()<< std::endl;
    std::cout << "레벨: " << player.getLevel() << std::endl;
    std::cout << "체력: " << player.getHealth() << std::endl;
    std::cout << "공격력: " << player.getDamage() << std::endl;
    std::cout << "층: " << player.getFloor() << std::endl;
	std::cout << "강화: " << player.getUpgrade() << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << std::endl;
}

void showPlayerItem(Player player)
{
    std::cout << "========================" << std::endl;
    std::cout << "1. 포션: " << player.getPotion() << std::endl;
    std::cout << "2. 방패: " << player.getShield() << std::endl;
    std::cout << "========================" << std::endl;
}