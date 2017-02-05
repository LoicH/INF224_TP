#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "mediaGroup.h"

#define LIST_LENGTH 10

int main(){

	//~ Media * otherMedia = new Media("NAME", "PATH");
	//~ otherMedia->print(cout);


	cout << "Creating first photo" << endl;
	Photo p ;
	cout << "Creating second photo" << endl;
	Photo * otherPhoto = new Photo("YES", "~/Downloads/thumbsup.jpg");
	otherPhoto->print(cout);
	//~ otherPhoto->play();

	cout << "Creating first video" << endl;
	Video * v = new Video("Bunny", "~/Downloads/SampleVideo_640x360_1mb.mp4");



	Media * mediaList[LIST_LENGTH];

	mediaList[0] =  otherPhoto;
	mediaList[1] =  v;

	cout << "Playing all media" << endl;
	for(int i = 0; i<2; i++){
		mediaList[i]->print(cout);
	//~ mediaList[i]->play();
	}
	
	cout << "Creating first film" << endl;
	Film * f1 = new Film("Bunny", "~/Downloads/SampleVideo_640x360_1mb.mp4");
	cout << "Creating second film" << endl;
	Film * f2 = new Film();


	unsigned int chap[] = {0, 1, 3, 5, 7, 9};
	f1->printChapters();

	f1->setChapters(chap, 6);
	//~ f2->getChapters(chap);

	f1->printChapters();
	f2->printChapters();

	return 0;


}
