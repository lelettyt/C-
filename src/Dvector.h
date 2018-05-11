/**
 * \file Dvector.h
 * \brief Classe Dvector.
 * \author Gardelle Clemence Le Letty Thomas
 * \version 1.0
 * \date Mai 2018
 *
 * Fichier definissant la classe Dvector, modelisant un vecteur.
 *
 */
 #include <iostream>
using namespace std;

#ifndef DVECTOR_HPP
#define DVECTOR_HPP


/**
 * \class Dvector
 * \brief Classe modelisant un vecteur.
 */
class Dvector{
    private:
    int taille; /*!< Taille du vecteur*/
    double * vect; /*!< Tableau de points du vecteur*/
    public:
    /*!
     *  \brief Constructeur par defaut
     *
     *  Constructeur de la classe Dvector
     *
     */
    Dvector();
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Dvector
     *
     *  \param t: taille du vecteur
     *  \param valeur: valeur des coordoonees du vecteur si non specifie vaut 0
     */
    Dvector(int t, double valeur=0.);
    /*!
     *  \brief Constructeur par copie
     *
     *  Constructeur de la classe Dvector
     *
     *  \param Vecteur: vecteur copie
     */
    Dvector(Dvector const & Vecteur);
    /*!
     *  \brief Constructeur par lecture de fichier
     *
     *  Constructeur de la classe Dvector
     *
     *  \param fichier: Flux dans lequel se trouve les coordonnees du vecteur
     */
    Dvector(std::string fichier);
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Dvector
     *
     */
    ~Dvector();

    /*!
     *  \brief Affichage du vecteur
     *
     *  Methode qui permet dafficher ke vecteur dans le flux specifie
     *
     *  \param str : Flux de sortie pour affichage du vecteur
     */
    void display( std::ostream & str);
    /*!
     *  \brief Getteur de l'attribut taille
     *
     *  Methode qui d'obtenur la taille du vecteur
     *
     *  \return la taille du vecteur
     */
    int size();
    /*!
     *  \brief Remplissage aleatoire du vecteur
     *
     *  Methode qui permet de remplir aleatoirement le vecteur
     *
     */
    void fillRandomly();

    /*!
     *  \brief Modification de la taille d'un vecteur
     *
     *  Methode qui permet de modifier la taille d'un vecteur, ajoute une valeur fixe si augmentation de la taille.
     *
     *  \param new_size : nouvelle taille
     *  \param val : valeur des nouvelles coordonnees s'il y en a
     */
    void resize(int new_size, double val);

    /*!
     *  \brief Methode equals
     *
     *  Methode qui permet de comparer deux vecteurs.
     *
     *  \param v : Vecteur a comparer avec l'objet courant.
     */
    bool equals(Dvector v);
};

/*!
 *  \brief Donne les valeurs du vecteur a un flux specifie
 *
 *  Methode qui permet de modifier la taille d'un vecteur, ajoute une valeur fixe si augmentation de la taille.
 *
 *  \param out : nouvelle taille
 *  \param v : valeur des nouvelles coordonnees s'il y en a
 */
ostream & operator << (ostream &out, const Dvector &v);

/*!
 *  \brief Modification d'un vecteur avec un flux
 *
 *  Methode qui permet de remplir un vecteur a partir d'un flux
 *
 *  \param in : flux d'entree
 *  \param v : vecteur qui sera rempli à partir du flux specifie
 */
istream & operator >> (istream &in, const Dvector &v);


#endif
