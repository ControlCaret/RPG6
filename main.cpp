#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <time.h>
#include <iostream>
#include <string>
#include "RPG6Player.hpp"
#include "RPG6Monster.hpp"
#include "RPG6.hpp"

int main()
{
    std::cout << "========================" << '\n';
    std::cout << "여기에 게임 이름을 입력해 주세요." << '\n';
    std::cout << "========================" << '\n';

    int highScore;
    FILE* fp = fopen("rpg6.txt", "r+");
    if(fp == NULL)
    {
        fp = fopen("rpg6.txt", "w");
        fprintf(fp, "0");
        fclose(fp);
        fp = fopen("rpg6.txt", "r+");
    }
    fscanf(fp, "%d", &highScore);
    std::cout << "최고 기록: " << highScore << "층" << '\n';
    std::cout << '\n';
    fclose(fp);

    std::string name;
    std::cout << "이름을 입력해 주세요: ";
    std::cin >> name;
    Player player(name, 100, 10, 1, 1, 0, 100, 5, 5);
    srand(static_cast<unsigned int>(time(NULL)));

    showPlayerStatus(player);
    //showPlayerItem(player);

    while(true)
    {
        std::cout << '\n';
        std::cout << "현재 층: " << player.getFloor() << '\n';

        Monster monster;

        int randomMonster = rand() % MONSTER;

        switch(randomMonster)
        {
        case SLIME:
            monster = Monster(slime);
            break;
        case WORM:
            monster = Monster(worm);
            break;
        case MOLE:
            monster = Monster(mole);
            break;
        case SPIDER:
            monster = Monster(spider);
            break;
        case ROACH:
            monster = Monster(roach);
            break;
        case ZOMBIE:
            monster = Monster(zombie);
            break;
        case SKELETON:
            monster = Monster(skeleton);
            break;
        case GHOST:
            monster = Monster(ghost);
            break;
        case GOBLIN:
            monster = Monster(goblin);
            break;
        case RACOON:
            monster = Monster(racoon);
            break;
        default:
            assert(false);
        }

        bool isBoss = false;
        std::string bossPrefix = "";

        if(player.getFloor() % 10 == 0)
        {
            isBoss = true;
            int randomBoss = rand() % BOSS;

            switch(randomBoss)
            {
                case HEAVY:
                    bossPrefix = "강인한 ";
                    monster.setHealth(+(int)(monster.getHealth() * 0.5));
                    break;
                case STRONG:
                    bossPrefix = "힘센 ";
                    monster.setDamage((int)(monster.getDamage() * 1.5));
                    break;
                case POWERFUL:
                    bossPrefix = "최강의 ";
                    monster.setHealth(+(int)(monster.getHealth() * 0.2));
                    monster.setDamage((int)(monster.getDamage() * 1.2));
                    break;
                case SPEEDY:
                    bossPrefix = "재빠른 ";
                    break;
                default:
                    assert(false);
            }
        }

        if(isBoss)
        {
            std::cout << bossPrefix;
        }
        std::cout << monster.getName() << "이(가) 나타났다!" << '\n';

        //bool useShield = false;

        while(true)
        {
            std::cout << '\n';
            std::cout << "1. 공격  2. 플레이어 정보  3. 아이템 사용  4. 몬스터 정보" << '\n';
			
            int input;

            std::cin >> input;

            if(input == 1)
            {
                monster.setHealth(-player.getDamage());
                std::cout << monster.getName() << "에게 " << player.getDamage() << "의 데미지를 주었다!" << '\n';
                std::cout << monster.getName() << "의 체력: " << monster.getHealth() << '\n';

                if(monster.getHealth() <= 0)
                {
                    std::cout << monster.getName() << "을(를) 처치했다!" << '\n';
                    int gold = (rand() % 100 + 50) * (int)(1 + player.getFloor() * 0.2);
                    player.setGold(gold);
                    std::cout << gold << "골드를 획득했다!" << '\n';
                    std::cout << '\n';
                    
                    while(true)
                    {
                        showShop(player);
                        int buy;
                        std::cout << "아이탬 구매(0: 나가기)" << '\n';
                        std::cin >> buy;
                        if(buy == 1)
                        {
                            if(player.getGold() >= 20)
                            {
                                player.setGold(-20);
                                player.setPotion(1);
                                std::cout << "포션을 구매했습니다." << '\n';
                            }
                            else
                            {
                                std::cout << "골드가 부족합니다." << '\n';
                            }
                        }
                        else if(buy == 2)
                        {
                            if(player.getGold() >= 40)
                            {
                                player.setGold(-40);
                                player.setShield(1);
                                std::cout << "쉴드를 구매했습니다." << '\n';
                            }
                            else
                            {
                                std::cout << "골드가 부족합니다." << '\n';
                            }
                        }
                        else if(buy == 3)
                        {
                            if(player.getGold() >= player.getUpgrade() * 20)
                            {
                                player.setGold(-20);
                                player.doUpgrade();
                                std::cout << "무기를 업그레이드했습니다." << '\n';
                            }
                            else
                            {
                                std::cout << "골드가 부족합니다." << '\n';
                            }
                        }
                        else if(buy == 0)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    player.nextFloor();
                    break;
                }

                /*if (useShield == true)
                {
                    std::cout << "방어했다!" << '\n';
                    useShield = false;
                    continue;
                }*/

                player.setHealth(-monster.getDamage());
                std::cout << monster.getName() << "에게 " << monster.getDamage() << "의 데미지를 받았다!" << '\n';
                std::cout << "남은 체력: " << player.getHealth() << '\n';

                if(player.getHealth() <= 0)
                {
                    std::cout << "당신은 죽었습니다." << '\n';
                    std::cout << "도달 층: " << player.getFloor() << '\n';
                    if(player.getFloor() > highScore)
                    {
                        fp = fopen("rpg6.txt", "w");
                        fprintf(fp, "%d", player.getFloor());
                        fclose(fp);
                    }
					
                    return 0;
                }
            }
            else if(input == 2)
            {
                showPlayerStatus(player);
            }
            else if(input == 3)
            {
                int item;
                showPlayerItem(player, true);
				std::cout << "아이템 선택(0: 뒤로가기)" << '\n';
                std::cin >> item;
                if(item == 1)
                {
                    if(player.getPotion() > 0)
                    {
                        player.setHealth(25);
                        player.setPotion(-1);
                        std::cout << "체력을 25 회복했다." << '\n';
                    }
                    else
                    {
                        std::cout << "포션이 없습니다." << '\n';
                    }
                }
                else if(item == 2)
                {
                    if(player.getShield() > 0)
                    {
                        //useShield = true;
                        player.setShield(-1);
                        std::cout << "쉴드를 사용했다. 이번 턴의 공격을 막는다." << '\n';
                        std::cout << "방어했다!" << '\n';
                    }
                    else
                    {
                        std::cout << "쉴드가 없습니다." << '\n';
                    }
                }
                else if (item == 0)
                {
                    continue;
                }
            }
            else if (input == 4)
            {
                showMonsterStatus(monster);
            }
            else
            {
                continue;
            }
        }
    }

    return 0;
}
