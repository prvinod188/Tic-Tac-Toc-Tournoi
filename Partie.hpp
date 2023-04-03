#ifndef PARTIE.HPP
#define PARTIE.HPP
#include<iostream>
#include<string>
#include"Joueur.hpp"
#include<vector>

using namespace std;

class Partie
{
private:
  Joueur *joueur_1;
  Joueur *joueur_2;
  vector <vector <int> >grille;
  int nbCouts;
  
  vector < vector <int> > zeroMatrix ();
  void afficherGrille ();
  bool grillePlein ();
  int getGagnant ();
  void terminePartie (int gagnant);
  float calculerScoreGagne ();

public:
    Partie (Joueur *j1, Joueur *j2);
    Joueur getJoueur1 ();
    Joueur getJoueur2 ();
    void lancePartie ();
    
};

ostream & operator<< (ostream & out, Partie & x);
#endif