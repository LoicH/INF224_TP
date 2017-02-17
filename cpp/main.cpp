#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "mediaGroup.h"
#include "mediaStorage.h"

#define LIST_LENGTH 10


int main(){

	// =============================
	// Testing basic types
	// =============================
	
	//~ cout << "Creating first photo" << endl;
	//~ Photo p ;
	//~ cout << "Creating second photo" << endl;
	//~ PhotoPtr otherPhoto = make_shared<Photo>("YES", "~/Downloads/thumbsup.jpg");
	//~ otherPhoto->print(cout);
	//~ otherPhoto->play();
	
	//~ cout << "Creating first video" << endl;
	//~ VideoPtr v = make_shared<Video>("Bunny", "~/Downloads/SampleVideo_640x360_1mb.mp4");

	// =============================
	// Testing the film class
	// =============================
	
	//~ cout << "Creating first film" << endl;
	//~ FilmPtr f1 = make_shared<Film>("Bunny2", "~/Downloads/SampleVideo_640x360_1mb.mp4");
	//~ cout << "Creating second film" << endl;
	//~ FilmPtr f2 = make_shared<Film>();

	//~ unsigned int chap[] = {2, 3, 7};
	
	//~ cout << "Chapters of f1:" << endl;
	//~ f1->printChapters();

	//~ f1->setChapters(chap, 3);
	//~ f2->getChapters(chap);

	//~ cout << "Chapters of f1:" << endl;
	//~ f1->printChapters();
	//~ cout << "Chapters of f2:" << endl;
	//~ f2->printChapters();

	// =============================
	// Testing a handmade media list
	// =============================
	
	//~ MediaPtr mediaList[LIST_LENGTH];

	//~ mediaList[0] =  otherPhoto;
	//~ mediaList[1] =  v;

	//~ cout << "Playing all media" << endl;
	//~ for(int i = 0; i<2; i++){
		//~ mediaList[i]->print(cout);
	//~ mediaList[i]->play();
	//~ }
	
	

	// =============================
	// Testing the list of media
	// =============================
	
	//~ MediaGrpPtr mg = make_shared<MediaGroup>();
	//~ cout << mg->getName() << endl;
	//~ mg->setName("Group1bis");
	//~ cout << mg->getName() << endl;
	
	//~ mg->push_back(f1);
	
	//~ mg->printAll();
	
	// =============================
	// Testing the media storage
	// =============================
	
	PhotoPtr p = MediaStorage::newPhoto("newPhoto", "pathToNewPhoto");
	VideoPtr v = MediaStorage::newVideo("newVideo", "pathToNewVideo");
	FilmPtr  f = MediaStorage::newFilm("newFilm", "pathToNewFilm");
	
	MediaStorage::printAllMedia();
		
	MediaGrpPtr mg = MediaStorage::newMediaGrp("Group1");
	MediaStorage::printAllGrp();
	mg->push_back(p);
	mg->push_back(v);
	MediaStorage::printAllGrp();
	
	MediaGrpPtr mg2 = MediaStorage::newMediaGrp("Group2");
	MediaStorage::printAllGrp();
	mg2->push_back(f);
	mg2->push_back(p);
	MediaStorage::printAllGrp();
	
	MediaPtr pSearch = MediaStorage::findMedia("newPhoto");
	if (pSearch != nullptr){
		pSearch->print(cout);
	} else {
		cout << "Photo newPhoto not found..." << endl;
	}
	pSearch = MediaStorage::findMedia("noPhoto");
	if (pSearch != nullptr){
		pSearch->print(cout);
	} else {
		cout << "Photo noPhoTo not found..." << endl;
	}
	
	return 0;


}
