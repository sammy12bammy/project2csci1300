#include<iostream>
#include <unistd.h>
#include "Player.h"

using namespace std;

Player::Player(){
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 0;
    _advisor = 0;
}

Player::Player(string name, int strength, int stamina, int wisdom){
    _pride_points = 0;
    _age = 1;
    _name = name;
    //strength
    if(strength > 1000 || strength < 100){
        _strength = 1000;
    } else {
        _strength = strength;
    }
    //stamina
    if(stamina > 1000 || stamina < 100){
        _stamina  = 1000;
    } else {
        _stamina = stamina;
    }
    //wisdom
    if(wisdom > 1000 || wisdom < 100){
        _wisdom = 1000;
    } else {
        _wisdom = wisdom;
    }
    _advisor = 0;
}
int Player::getAdvisor(){
    return _advisor;
}
void Player::setAdvisor(int n){
    _advisor = n;
}
string Player::getName(){
    return _name;
}

void Player::setName(string n){
    _name = n;
}

int Player::getStrength(){
    return _strength;
} 

void Player::setStrength(int s){
    if(s <= 1000 && s >= 100){
        _strength  = s;
    }
}

int Player::getStamina(){
    return _stamina;
} 

void Player::setStamina(int s){
    if(s <= 1000 && s >= 100){
        _stamina  = s;
    }
}

int Player::getWisdom(){
    return _wisdom;
} 

void Player::setWisdom(int w){
    if(w >= 100 && w <= 1000){
        _wisdom = w;
    }
}

int Player::getPridePoints(){
    return _pride_points;
}

void Player::setPridePoints(int p){
    _pride_points = p;
}

int Player::getAge(){
    return _age;
}  

void Player::setAge(int a){
    if(a >= 1 && a <= 20){
        _age = a;
    }
}

void Player::addStrength(int s){
    _strength += s;
}  

void Player::addStamina(int s){
    _stamina += s;
}  

void Player::addWisdom(int w){
    _wisdom += w;
} 
void Player::addPridePoints(int p){
    _pride_points += p;
}  

void Player::addAge(int a){
    _age += a;
}

void Player::trainCub(int strength, int stamina, int wisdom){
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
    _pride_points -= 5000;
}

void Player::toPrideLands(){
    _pride_points += 5000;
    _strength -= 2000;
    _wisdom -= 2000;
    _stamina -= 1000;
}

void Player::printStats(){
    //basic printing - boring
    cout<<_name<<" age "<<_age<<endl;
    cout<<"Strength: "<<_strength<<endl;
    cout<<"Stamina: "<<_stamina<<endl;
    cout<<"Wisdom "<<_wisdom<<endl;
    cout<<"Pride Points: "<<_pride_points<<endl;
    /*
    //animation printing
    //clears the screen
    cout<<"\033[2J"<<endl;
    int index = 0;
    for(int i = 0; i < 10000; ++i){
        //print single frame
        printFrame(index);
        index++;
        if(index == 10){
            index = 0;
        }
        cout<<endl;
        //printing stats
        cout<<_name<<" age "<<_age<<endl;
        cout<<"Strength: "<<_strength<<endl;
        cout<<"Stamina: "<<_stamina<<endl;
        cout<<"Wisdom "<<_wisdom<<endl;
        cout<<"Pride Points: "<<_pride_points<<endl;
        //sleep
        usleep(100000);
        cout<<"\033[2J"<<endl;
    }
    */
}
//animation frames
void Player::printFrame(int index){
    if(index == 0){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "      /|      |\\" << endl;
        cout << "     (/        \\)" << endl;
    } else if(index == 1){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "     / /|     |\\" << endl;
        cout << "    (/         \\)" << endl;
    } else if(index == 2){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "      /|       \\" << endl;
        cout << "     (/ \\      /)" << endl;
    } else if(index == 3){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "      / \\      |\\" << endl;
        cout << "     (   \\     /)" << endl;
    } else if(index == 4){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "       |/      |\\" << endl;
        cout << "      (         \\)" << endl;
    } else if(index == 5){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "       |       |\\" << endl;
        cout << "      ( \\       \\)" << endl;
    } else if(index == 6){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "      /|       |\\" << endl;
        cout << "     (/ \\      /)" << endl;
    } else if(index == 7){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "      /        |\\" << endl;
        cout << "     (/        \\)" << endl;
    } else if(index == 8){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "       /|      |\\" << endl;
        cout << "      (/        \\)" << endl;
    } else if(index == 9){
        cout << "         ____" << endl;
        cout << "       .^o o'^" << endl;
        cout << "      /_  _   \\" << endl;
        cout << "     /   V   |\\" << endl;
        cout << "     \\_~_____/  \\" << endl;
        cout << "       /      \\" << endl;
        cout << "      (        )" << endl;
        cout << "      /|       |\\" << endl;
        cout << "     (/         \\)" << endl;
    }
}
