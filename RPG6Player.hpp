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
	this->damage = this->damage + (int)(this->upgrade * 0.2);
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
    std::cout << "========================" << '\n';
    std::cout << "플레이어 정보" << '\n';
    std::cout << "------------------------" << '\n';
    std::cout << "이름: " << player.getName()<< '\n';
    std::cout << "레벨: " << player.getLevel() << '\n';
    std::cout << "체력: " << player.getHealth() << '\n';
    std::cout << "공격력: " << player.getDamage() << '\n';
    std::cout << "층: " << player.getFloor() << '\n';
	std::cout << "강화: " << player.getUpgrade() << '\n';
	std::cout << "골드: " << player.getGold() << '\n';
    std::cout << "========================" << '\n';
    std::cout << '\n';
}

void showPlayerItem(Player player, bool showNum)
{
    std::cout << "========================" << '\n';
    std::cout << "보유 아이템" << '\n';
    std::cout << "------------------------" << '\n';
    std::cout << (showNum ? "1. " : "") << "포션: " << player.getPotion() << '\n';
    std::cout << (showNum ? "2. " : "") << "방패: " << player.getShield() << '\n';
    std::cout << "========================" << '\n';
}

void showShop(Player player)
{
	std::cout << "========================" << '\n';
	std::cout << "상점" << '\n';
	std::cout << "------------------------" << '\n';
	std::cout << "1. 포션: 20골드" << '\n';
	std::cout << "2. 쉴드: 40골드" << '\n';
	std::cout << "3. 무기 업그레이드: " << (player.getUpgrade() + 1) * 20 << '\n';
	std::cout << "========================" << '\n';
	showPlayerItem(player, false);
	std::cout << "현재 골드: " << player.getGold() << '\n';
	std::cout << "현재 무기 단계: " << player.getUpgrade() << '\n';
	std::cout << '\n';
}