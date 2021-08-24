#include "ofMain.h"
#include "App.hpp"

//========================================================================
int main( ){
	ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context
    ofSetLogLevel(OF_LOG_NOTICE);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(std::make_shared<App>());

}
