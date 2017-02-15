#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "mediaGroup.h"
#include "mediaStorage.h"

#define LIST_LENGTH 10


int main(){

	//~ Media * otherMedia = make_shared<Media>("NAME", "PATH");
	//~ otherMedia->print(cout);


	cout << "Creating first photo" << endl;
	Photo p ;
	cout << "Creating second photo" << endl;
	PhotoPtr otherPhoto = make_shared<Photo>("YES", "~/Downloads/thumbsup.jpg");
	otherPhoto->print(cout);
	//~ otherPhoto->play();

	cout << "Creating first video" << endl;
	VideoPtr v = make_shared<Video>("Bunny", "~/Downloads/SampleVideo_640x360_1mb.mp4");



	MediaPtr mediaList[LIST_LENGTH];

	mediaList[0] =  otherPhoto;
	mediaList[1] =  v;

	cout << "Playing all media" << endl;
	for(int i = 0; i<2; i++){
		mediaList[i]->print(cout);
	//~ mediaList[i]->play();
	}
	
	cout << "Creating first film" << endl;
	FilmPtr f1 = make_shared<Film>("Bunny2", "~/Downloads/SampleVideo_640x360_1mb.mp4");
	cout << "Creating second film" << endl;
	FilmPtr f2 = make_shared<Film>();


	unsigned int chap[] = {0, 1, 3, 5, 7, 9};
	f1->printChapters();

	f1->setChapters(chap, 6);
	//~ f2->getChapters(chap);

	f1->printChapters();
	f2->printChapters();
	
	MediaGrpPtr mg = make_shared<MediaGroup>();
	cout << mg->getName() << endl;
	mg->setName("Group1bis");
	cout << mg->getName() << endl;
	
	MediaStorage::insertMedia(f1);
	MediaStorage::insertMedia(f2);
	
	return 0;


}
