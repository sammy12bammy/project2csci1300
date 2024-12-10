#include<string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age, _advisor;
    public:
        //constructers
        Player();
        Player(string, int, int ,int);
        //getter and setter methods for variables
        string getName();
        void setName(string);
        int getStrength();
        void setStrength(int);
        int getStamina();
        void setStamina(int);
        int getWisdom();
        void setWisdom(int);
        int getPridePoints();
        void setPridePoints(int);
        int getAge();
        void setAge(int);
        int getAdvisor();
        void setAdvisor(int);
        //adder methods
        void addStrength(int);
        void addStamina(int);
        void addWisdom(int);
        void addPridePoints(int);
        void addAge(int);
        //other funciton
        void trainCub(int, int, int);
        void toPrideLands();
        void printStats();
        //animation for printStats
        void printFrame(int);
};

#endif
