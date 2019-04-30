//
// Created by pelluro on 29/04/19.
//

#ifndef SAMPLE_H
#define SAMPLE_H


class Sample {

public:
    //initialisation d'une liste
    int a;
    float b;
    char c;

    //initiation un const
    float const pi;


    Sample (int a1, float b1, char c1, float const f); //constructeur : lorsque la class est instancie', le constructeur est appele.
    ~Sample(void); //destructeur : quand la class est detruite, la ft de destruction est appele'.

    void funtion_inside_class(void) const; // ma func
    // const dans cette funtion veut dire que a aucun moment, dans le code de cette func membre ne sera modifie l'instance courant
    //de la classe

    int getFoo(void) const;
    void setFoo (int v);
// ces deux fonctions permet aux utilisateurs de ne pas avoir acces mais manipuler indirect ma instance private



    int compare( Sample * other) const;



private:

    int _privateA;
    int _foo;
    void _funtion_private(void) const;


};


/// la difference entre structure et class : Les deux sont declare exactement la meme facon
// sauf que : structure par defaut est public et class par defaut est privee.
// du coup vaut mieux utiliser class en cpp.

#endif //COMPUTOR1_SAMPLE_HPP
