#ifndef RPG_H
#define RPG_H

#include <string>

const int SKILL_SIZE = 2;

class RPG{
    public:

        RPG();
        RPG(std::string name, int health, int strength, int defense, std::string type);

        void setSkills();
        void printAction(std::string, RPG opponent);
        void updateHealth(int new_health);
        void attack(RPG *);
        void useSkill(RPG *);

        bool isAlive() const;
        std::string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getDefense() const;

    private:
        std::string name;
        int health;
        int strength;
        int defense;
        std::string type;
        std::string skills [SKILL_SIZE];

};
#endif