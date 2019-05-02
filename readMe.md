
1. Mon executable attend une entree : ok
 Verifie si l'entree est valide ou pas


2. Detecter si un seul egal dans la fonction
3. Detecter le degre du polynome
- Split la fonction par + et -
ex: 5x^2 + 3x + 1 = 3x^2 => donne 3 morceaux cote gauche et 1 du cote droite du egale.
- Ensuite rassemble tout d'un seul cote.

- Exemple de l'executable:
````
./computor "5 + 4 * X + X^2= X^2"   
    Reduced form: 5 + 4 * X = 0
    Polynomial degree: 1
    The solution is:
    -1.25
`````

    
- a ne pas oublier:
- nombre complexe
- polynome de degre trois a reconnaitre

````
>./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
       Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
       Polynomial degree: 2
       Discriminant is strictly positive, the two solutions are:
       0.905239
       -0.475131
       $>./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
       Reduced form: 1 * X^0 + 4 * X^1 = 0
       Polynomial degree: 1
       The solution is:
       -0.25
       ./computor "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
       Reduced form: 5 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 0
       Polynomial degree: 3
       The polynomial degree is stricly greater than 2, I can't solve.``
```