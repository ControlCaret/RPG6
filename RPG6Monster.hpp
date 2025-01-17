﻿#pragma once

class Monster
{
private:
    std::string name;
    int health;
    int damage;
public:
    Monster(std::string name, int health, int damage);
    Monster(const Monster&);
    Monster();
    std::string getName();
    int getHealth();
    int getDamage();
    void setHealth(int health);
    void setDamage(int damage);
};

Monster::Monster(std::string name, int health, int damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
}

Monster::Monster(const Monster& monster)
{
    this->name = monster.name;
    this->health = monster.health;
    this->damage = monster.damage;
}

Monster::Monster()
{
    this->name = "null";
}

std::string Monster::getName()
{
    assert(name != "null");
    return this->name;
}

int Monster::getHealth()
{
    return this->health;
}

int Monster::getDamage()
{
    return this->damage;
}

void Monster::setHealth(int health)
{
    this->health += health;
}

void Monster::setDamage(int damage)
{
    this->damage += damage;
}

const int MONSTER = 10;

enum MonsterName
{
    SLIME,
    WORM,
    MOLE,
    SPIDER,
    ROACH,
    ZOMBIE,
    SKELETON,
    GHOST,
    GOBLIN,
    RACOON,
};

const int BOSS = 4;

enum BossPrefix
{
    STRONG,
    POWERFUL,
    HEAVY,
    REVIVAL,
    STRONGER
};

Monster slime("슬라임", 10, 1);
Monster worm("벌레", 20, 3);
Monster mole("두더지", 30, 4);
Monster spider("거미", 40, 5);
Monster roach("바선생", 50, 10);
Monster zombie("좀비", 60, 6);
Monster skeleton("스켈레톤", 70, 7);
Monster ghost("유령", 80, 8);
Monster goblin("고블린", 90, 9);
Monster racoon("너구Lee", 100, 10);

void showMonsterStatus(Monster monster)
{
    std::cout << "\t==================================" << '\n';
    std::cout << "\t||         몬스터 정보          ||" << '\n';
    std::cout << "\t==================================" << '\n';
    std::cout << "\t| 이름: " << monster.getName() << "\t\t\t | \n";
    std::cout << "\t| 체력: " << monster.getHealth() << "\t\t\t | \n";
    std::cout << "\t| 공격력: " << monster.getDamage() << "\t\t\t | \n";
    std::cout << "\t==================================" << '\n';
}