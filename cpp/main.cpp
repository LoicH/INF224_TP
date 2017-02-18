#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "mediaGroup.h"
#include "mediaStorage.h"

#define LIST_LENGTH 10


int main(){

	typedef shared_ptr<Photo> PhotoPtr;
	typedef shared_ptr<Video> VideoPtr;
	typedef shared_ptr<Film> FilmPtr;

	// =============================
	// Testing basic types
	// =============================
	
	//~ cout << "Creating first photo" << endl;
	//~ Photo p ;
	//~ cout << "Creating second photo" << endl;
	//~ PhotoPtr otherPhoto = make_shared<Photo>("YES", "media/thumbup.jpg");
	//~ otherPhoto->print(cout);
	//~ otherPhoto->play();
	
	//~ cout << "Creating first video" << endl;
	//~ VideoPtr v = make_shared<Video>("Paint", "media/Paint.mp4");

	// =============================
	// Testing the film class
	// =============================
	
	//~ cout << "Creating first film" << endl;
	//~ FilmPtr f1 = make_shared<Film>("CD", "media/cd.mp4");
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
	
	PhotoPtr p = MediaStorage::newPhoto("newPhoto", "media/thumb_up.jpg");
	VideoPtr v = MediaStorage::newVideo("newVideo", "media/cd.mp4");
	FilmPtr  f = MediaStorage::newFilm("newFilm", "media/Paint.mp4");
	
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
	
	MediaStorage::printMedia("newVideo");
	MediaStorage::printMedia("noVideo");
	
	
	MediaStorage::playMedia("newFilm");
	MediaStorage::playMedia("noFilm");
	
	MediaStorage::removeMedia("newFilm");
	MediaStorage::removeMedia("noFilm");
	
	MediaStorage::playMedia("newFilm");
	MediaStorage::playMedia("noFilm");
	
	MediaStorage::printGroup("Group1");
	MediaStorage::printGroup("Group3");
	
	
	
	return 0;


}
