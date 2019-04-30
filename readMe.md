
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

    