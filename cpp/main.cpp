
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
    return true;
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
	
	printTestPart("Adding media: 3 photos, 2 videos & 1 film");
	
	PhotoPtr p1 = MediaStorage::newPhoto("photo1", "media/thumb_up.jpg");
	PhotoPtr p2 = MediaStorage::newPhoto("photo2", "media/thumbup.png");
	MediaStorage::newPhoto("photo3", "media/fallout.jpg");
	VideoPtr v1 = MediaStorage::newVideo("vid1", "media/cd.mp4");
	VideoPtr v2 = MediaStorage::newVideo("vid2", "media/Paint.mp4");
	FilmPtr  f1 = MediaStorage::newFilm("film1", "media/Paint.mp4");
	
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
	
	
	printTestPart("Trying to print specific media");
	try {
		MediaStorage::printMedia("photo1");
	} catch(exception const& e) {
		cout  << e.what() << endl;
	}
	try {
		MediaStorage::printMedia("photo0");
	} catch(exception const& e) {
		cout  << e.what() << endl;
	}
	
	try {
		MediaStorage::printMedia("vid1");
	} catch(exception const& e) {
		cout  << e.what() << endl;
	}
	try {
		MediaStorage::printMedia("vid3");
	} catch(exception const& e) {
		cout << e.what() << endl;
	}
	
	printTestPart("Trying to play specific media");
	try {
		MediaStorage::playMedia("photo2");
	} catch(exception const& e) {
		cout  << e.what() << endl;
	}
	try {
		MediaStorage::playMedia("photo0");
	} catch(exception const& e) {
		cout  << e.what() << endl;
	}
	
	try {
		MediaStorage::playMedia("film1");
	} catch(exception const& e) {
		cout  << e.what() << endl;
	}
	try {
		MediaStorage::playMedia("film3");
	} catch(exception const& e) {
		cout << e.what() << endl;
	}
	
	
	printTestPart("Removing media");
	MediaStorage::removeMedia("photo2");
	MediaStorage::removeMedia("vid1");
	
	
	printTestPart("Adding other media");
	MediaStorage::newPhoto("photo4", "media/thumb_up.jpg");
	MediaStorage::newVideo("vid3", "media/cd.mp4");
	MediaStorage::newFilm("film2", "media/Paint.mp4");
	
	printTestPart("Printing stored data to check");
	
	MediaStorage::printAllMedia();
	MediaStorage::printAllGrp();
	
	
	printTestPart("Removing a group");
	MediaStorage::removeGroup("Group1");
	MediaStorage::printAllGrp();
	
	
	
	printTestPart("Creating object from serialized representation:");
	
	MediaStorage::fromString("Photo,serial_photo1,media/thumb_up.jpg,120,240");
	MediaStorage::fromString("Video,serial_vid1,media/Paint.mp4,120");
	MediaStorage::fromString("Film,serial_film1,media/Paint.mp4,120,2,3 5");
	
	printTestPart("Printing stored data to check");
	MediaStorage::printAllMedia();
	
	printTestPart("Serializing objects:");
	
	MediaStorage::findMedia("photo1")->serialize();
	MediaStorage::findMedia("vid3")->serialize();
	MediaStorage::findMedia("film2")->serialize();
	
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
