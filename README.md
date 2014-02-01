calc
====

This is an old program made in C. I do not remember why I did it, but I think I had a reason :)

This program just do mathematic calcul, nothing special.

Compilation
===========

$ cd calc
$ make
$ make install

Usage
=====
$ calc "6*6*(1+3*tan(cos(0.5)))-0.218"
```
Resultat : 159
```
  
$ calc -s "6*6"
```
36
```

$calc -d "6*6"
```
############# Debut de l'analyse syntaxique #############
        Liste des tokens rencontres :
                TYPE : 3
                Real = 6.000000
                TYPE : 2
                OPERATOR : 0
                TYPE : 3
                Real = 6.000000

############# Debut de l'analyse Grammaticale #############
        Etat de la Pile
                REAL : 6.000000
                REAL : 6.000000
                OPERATEUR : 
Resultat : 36

```
