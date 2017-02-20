#Travaux Pratiques C++/Objet

Réponses aux questions dans le fichier Reponses.md

## Logiciels utilisés :

Pour la visualisation de médias, j'utilise `ristretto` et `mpv`



#Description de la sérialisation des objets :

Les représentations suivent le format suivant :

> NomDeLaClasse,Attribut1, Attribut2,...

Avec l'ordre des attributs déterminés par la chaîne d'héritage.
Pour un objet "Film" (qui descend de Video, et donc de Media),
on va avoir les attributs de Media (nom & chemin), puis ceux de video
(durée), puis les attributs de Film (nombre de chapitres et leur longueur)


* Un objet "Photo" est représenté par une chaîne

> Photo,nom,chemin,latitude,longitude
	
par exemple :

> Photo,Vacances,/home/user/Photos/Juin 2016/vacances.jpg,34.5,65.4

* Pour un objet "Video" :

> Video,nom,chemin,durée (en secondes)

* Pour un objet "Film" :

> Film,nom,chemin,durée,nombre de chapitres,durée des chapitres

Exemple : 

> Film,LotR,/home/mitnick/Downloads/LotR1.mkv,10800,3,1000 1234 1235


	
#Procédure de test :
J'ai inclu un fichier `testing.cpp` qui teste pas mal de méthodes définies
dans ce TP, cela permet de vérifier assez rapidement que les méthodes
marchent (ou ont l'air de marcher)

Pour lancer ces tests : `make testing`

(Il peut y avoir des conflits de définition d'objet `main` car `main.cpp`
définit aussi un symbole de fonction `main`, donc si un conflit/une erreur 
apparaît, vous pouvez tenter un `make clean`.)
