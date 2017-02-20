
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

  /** Method called for each request
   * @param cnx:
   * @param request: the request sent by the client
   * @param response: the answer to send to the client
   * @returns true if everything went fine, 
   * 		or false if we want to end to end the connection.
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cout << "\nRequest: '" << request << "'" << endl;
		
	response = MediaStorage::handleRequest(request);
	
    cout << "response: " << response << endl;
    
    // renvoyer false si on veut clore la connexion avec le client
    return (request != "quit");
  }
};

void printTestPart(string s){
	cout << endl << "==========================================" << endl;
	cout << s << endl;
	cout << "==========================================" << endl;

	
}

int main(){
	
	// =============================
	// Testing the media storage
	// =============================
	
	printTestPart("Adding media: 3 photos, 2 videos & 2 film");
	
	PhotoPtr p1 = MediaStorage::newPhoto("photo1", "media/thumb_up.jpg");
	PhotoPtr p2 = MediaStorage::newPhoto("photo2", "media/thumbup.png");
	MediaStorage::newPhoto("photo3", "media/fallout.jpg");
	VideoPtr v1 = MediaStorage::newVideo("vid1", "media/cd.mp4");
	VideoPtr v2 = MediaStorage::newVideo("vid2", "media/Paint.mp4");
	FilmPtr  f1 = MediaStorage::newFilm("film1", "media/Paint.mp4");
	unsigned int chapters1[3] = {1,3,9};
	f1->setChapters(chapters1, 3);
	
	FilmPtr  f2 = MediaStorage::newFilm("film2", "media/cd.mp4");
	unsigned int chapters2[5] = {1,10,11,12,13};
	f2->setChapters(chapters2, 5);
	
	printTestPart("Checking the media stored");
	MediaStorage::printAllMedia();
		
	
	printTestPart("Adding 2 groups:");
	
	MediaGrpPtr mg = MediaStorage::newMediaGrp("Group1");
	mg->push_back(p1);
	mg->push_back(v1);
	mg->push_back(f1);
	
	MediaGrpPtr mg2 = MediaStorage::newMediaGrp("Group2");
	mg2->push_back(p2);
	mg2->push_back(v2);
	
	printTestPart("Checking the groups stored:");
	MediaStorage::printAllGrp();
	
	
	
	
	// =============================
	// 		Server part
	// =============================
	
	
	// cree le TCPServer
	shared_ptr<TCPServer> server(new TCPServer());

	// cree l'objet qui gère les données
	shared_ptr<MyBase> base(new MyBase());

	// le serveur appelera cette méthode chaque fois qu'il y a une requête
	server->setCallback(*base, &MyBase::processRequest);

	// lance la boucle infinie du serveur
	cout << "Starting Server on port " << PORT << endl;
	int status = server->run(PORT);

	// en cas d'erreur
	if (status < 0) {
	cerr << "Could not start Server on port " << PORT << endl;
	return 1;
	}
	
	
	return 0;


}
