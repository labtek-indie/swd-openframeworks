#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context  1024,768

    ofAppGLFWWindow win;
    win.setMultiDisplayFullscreen(true);
    ofSetupOpenGL(&win, 1920,1080, OF_FULLSCREEN);
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
