
#include "mediaStorage.h"

#include <memory>
#include <string>
#include <iostream>


void printTestPart(string s){
	cout << endl << "==========================================" << endl;
	cout << s << endl;
	cout << "==========================================" << endl;

	
}

int main(){
	
	// =============================
	// Testing the media storage
	// =============================
	
	printTestPart("Adding media: 3 photos, 2 videos & 2 films");
	
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
	
	// Annoying test part, it opens windows...
	
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
	MediaStorage::newFilm("film3", "media/Paint.mp4");
	
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
	
	
	
	return 0;


}
