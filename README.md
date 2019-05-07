
- Makefile



1. Mon executable attend une entree
	*	String
	*	Si c'est un polynome valide (format ax^n +bx^n-1 = 0)
			2. Exclure si pas '=' dans la string
			1. si le degree est <= 2	 
2. Traitement le string:
	*	spliter en fonction du '='	
	*	reecrire en reduce form et afficher
			2. Ajouter le + avant chaque -
			1. Split la fonction par +
			3. Rassembler tout d'un seul cote
	*	Detecter le degre du polynome et afficher 
			
3. Resoudre le polynome:
	*	Calculer discriminant
			*	discriminant = 0 > 0 < 0
	*	Calculer racine
		
4. A ne pas oublier:
	*	Nombre complexe racine irrelle
	*	Polynome de degre trois a reconnaitre

5. Exemple de l'executable:
````
./computor "5 + 4 * X + X^2= X^2"   
    Reduced form: 5 + 4 * X = 0
    Polynomial degree: 1
    The solution is:
    -1.25
`````
    


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
       The polynomial degree is stricly greater than 2, I can't solve.
       ``
      

