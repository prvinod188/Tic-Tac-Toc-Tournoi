#ifndef JOUEUR.HPP
#define JOUEUR.HPP
#include<iostream>
#include<string>
using namespace std;

class Joueur{
private:
    string idJoueur;
    float scoreTotal;
    float scoreTournoi;
public:
    Joueur(string idJoueur); 
    string getIdJoueur();
    float getScoreTournoi();
    float getScoreTotal();
    void majScores(float scoreGagne);
    void razScoreTournoi();
};
ostream& operator<<(ostream& out, Joueur &x);
#endif