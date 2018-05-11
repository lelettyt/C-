#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <iomanip>
#include "Dvector.h"

using namespace std;

Dvector::Dvector()
{
  taille = 0;
  vect = new double[0];
}

Dvector::Dvector(int t, double valeur)
{
  taille = t;
  vect = new double[t];
  for(int i(0); i<taille; i++){
    vect[i] = valeur;
  }
}

Dvector::Dvector(Dvector const & Vecteur)
{
  taille = Vecteur.taille;
  vect = new double[taille];
  for(int i(0); i<taille; i++){
    vect[i] = Vecteur.vect[i];
  }
}

Dvector::Dvector(std::string fichier)
{
  //getting size
  ifstream file1 (fichier);
  string line;
  int t = 0;
  if(file1.is_open()){
    while(getline(file1, line)){
      t++;
    }
  }
  else {
    Dvector();
  }

  //creating vector
  taille = t;
  vect = new double[taille];

  ifstream file2 (fichier);
  if(file2.is_open()){
    for(int i(0); i<taille; i++){
      getline(file2, line);
      vect[i] = atof(line.c_str());
    }
  }
  else {
    cout << "Unable to open" ;
  }
}

Dvector::~Dvector()
{
  delete[] vect;
}

void Dvector::display( std::ostream & str)
{
  for(int i(0); i< taille; i++){
    str<< vect[i]<<"\n";
  }
  str << endl;
}

int Dvector::size ()
{
  return this->taille;
}

void Dvector::fillRandomly()
{
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0,1.0);

  for(int i=0;i<this->taille;i++){
    this->vect[i] = distribution(generator);
  }
}
