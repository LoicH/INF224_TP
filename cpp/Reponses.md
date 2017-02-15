## Question 4 :

**Comme pour la fonction d'affichage, la fonction pour jouer l'objet ne modifie pas l'objet et elle doit être déclarée dans les classes Photo et Video et dans la classe de base afin de permettre un appel polymorphique sur la hiérarchie de classes. Cependant, contrairement à la fonction d'affichage, elle ne peut pas avoir d'implementation au niveau de la classe de base (car a priori chaque type d'objet nécessite un utilitaire différent pour être joué). Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?**

Ce type de fonction est appelé "virtuelle pure".
On la définit comme ceci : `virtual typeRenvoyé nomDeLaFonction(arguments) = 0;` pour ensuite l'implémenter dans les bonnes classes.

**Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?**

Une classe qui déclare une fonction virtuelle pure est une classe abstraite, non instanciable.



## Question 5 : 

**On veut maintenant pouvoir traiter génériquement une liste comprenant à la fois des photos et des vidéos. Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau (ou de les "jouer"). Cette boucle n'a pas besoin de connaître le type des élements : elle doit pouvoir traiter de la même manière tous les objets dérivant de la classe de base. **

**Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?**

Grâce aux fonctions virtuelles pures et aux classes abstraites, on peut appeler des méthodes sur des objets qui sont de types différents, mais qui ont une classe mère en commun : c'est le polymorphisme.

**Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.**

Il faut allouer un tableau de pointeurs vers des objets `Media` : `Media * mediaList[LIST_LENGTH];`

Le tableau contient des pointeurs vers les objets, car comme on ne connaît pas la taille en mémoire des objets, ou si elle est variable, il vaut mieux considérer une case en mémoire comme un pointeur qui pointe vers l'objet voulu.

En Java ce comportement est assez opaque, le développeur n'a pas à se soucier de pointeurs/références, il alloue un tableau d'objets : `String[] myStringArray = new String[]{"abra", "ca", "dabra"};`


## Question 6 :
**Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ? (c'est l'objet qui doit pouvoir modifier ce qui lui appartient, pas les autres !)**

On peut recopier le tableau des durées en mémoire à un autre endroit, pour que l'objet ait son propre tableau, sans que personne ne puisse le modifier.

**Attention, le même problème se pose si un accesseur retourne directement ce tableau sans prendre les précautions nécessaires : la encore le contenu du tableau n'est pas récopié et l'appelant peut le modifier à sa guise. Quelle est la solution très simple que propose C/C++ pour éviter ce problème ?**
Pour renvoyer un tableau et une longueur on peut faire quelque chose comme

	size_t getChapters(unsigned int * destination){
			//on recopie le tableau des durées dans destination
			...
			return f_length; 
		}

## Question 7 : 
**Contrairement à Java ou C#, C/C++ ne gère pas la mémoire dynamique automatiquement (*) : comme il n'y a pas de ramasse miettes, tout ce qui a été créé avec new doit être détruit avec delete sinon on aura des fuites mémoires. Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?**

On utilise `new` seulement pour créer le tableau de durées de chapitres : 

	film.h:21: f_chapters = new unsigned int[length];

Donc il faut rajouter `delete[] f_chapters;` à `~Film()`.


**De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?**


## Question 8 :
**On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.**

Comme une liste est en fait une région de la mémoire, avec des cases contiguës, il est plus pratique de stocker les pointeurs vers les objets (les pointeurs sont de taille fixe donc occupent une place fixe en mémoire) plutôt que de stocker les objets directement.

En Java ce mécanisme est opaque et le développeur n'a pas à se poser la question :

	String hi[] = {"hello","world","!"};


