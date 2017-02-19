
#include "mediaStorage.h"

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"

using namespace cppu;
const int PORT = 3331;

class MyBase {
public:

  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cout << "\nRequest: '" << request << "'" << endl;
		
	response = MediaStorage::handleRequest(request);
	
    cout << "response: " << response << endl;
    
    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
};

int main(){
	
	// =============================
	// Testing the media storage
	// =============================
	
	cout << "Adding newPhoto, newVideo, newFilm" << endl;
	
	PhotoPtr p = MediaStorage::newPhoto("newPhoto", "media/thumb_up.jpg");
	VideoPtr v = MediaStorage::newVideo("newVideo", "media/cd.mp4");
	FilmPtr  f = MediaStorage::newFilm("newFilm", "media/Paint.mp4");
	
	MediaStorage::printAllMedia();
		
		
	cout << "Storing newPhoto and newVideo in Group1" << endl;
	MediaGrpPtr mg = MediaStorage::newMediaGrp("Group1");
	mg->push_back(p);
	mg->push_back(v);
	
	cout << "Storing newFilm and newPhoto in Group2" << endl;
	MediaGrpPtr mg2 = MediaStorage::newMediaGrp("Group2");
	mg2->push_back(f);
	mg2->push_back(p);
	
	MediaStorage::printAllGrp();
	
	//~ MediaPtr pSearch = MediaStorage::findMedia("newPhoto");
	//~ if (pSearch != nullptr){
		//~ pSearch->print(cout);
	//~ } else {
		//~ cout << "Photo newPhoto not found..." << endl;
	//~ }
	//~ pSearch = MediaStorage::findMedia("noPhoto");
	//~ if (pSearch != nullptr){
		//~ pSearch->print(cout);
	//~ } else {
		//~ cout << "Photo noPhoTo not found..." << endl;
	//~ }
	
	//~ MediaStorage::printMedia("newVideo");
	//~ MediaStorage::printMedia("noVideo");
	
	
	//~ MediaStorage::playMedia("newFilm");
	//~ MediaStorage::playMedia("noFilm");
	
	
	cout << "Removing newFilm and noFilm" << endl;
	MediaStorage::removeMedia("newFilm");
	MediaStorage::removeMedia("noFilm");
	
	MediaStorage::printAllGrp();
	
	cout << "Adding Photo2, newVideo and newFilm" << endl;
	MediaStorage::newPhoto("Photo2", "media/thumb_up.jpg");
	MediaStorage::newVideo("newVideo", "media/cd.mp4");
	MediaStorage::newFilm("newFilm", "media/Paint.mp4");
	
	
	MediaStorage::printAllGrp();
	
	cout << "Removing Group1" << endl;
	MediaStorage::removeGroup("Group1");
	MediaStorage::printAllGrp();
	
	
	//~ MediaStorage::playMedia("newFilm");
	//~ MediaStorage::playMedia("noFilm");
	
	//~ MediaStorage::printGroup("Group1");
	//~ MediaStorage::printGroup("Group3");
	
	
	// =============================
	// 		Server part
	// =============================
	
	
	// cree le TCPServer
	shared_ptr<TCPServer> server(new TCPServer());

	// cree l'objet qui gère les données
	shared_ptr<MyBase> base(new MyBase());

	// le serveur appelera cette méthode chaque fois qu'il y a une requête
	server->setCallback(*base, &MyBase::processRequest);

	// lance la boucle infinie du serveur
	cout << "Starting Server on port " << PORT << endl;
	int status = server->run(PORT);

	// en cas d'erreur
	if (status < 0) {
	cerr << "Could not start Server on port " << PORT << endl;
	return 1;
	}
	
	
	return 0;


}
