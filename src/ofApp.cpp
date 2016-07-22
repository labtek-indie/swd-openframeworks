#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.setVerbose(true);
	video.initGrabber(1920,1080);

	colorImg.allocate(video.getWidth(), video.getHeight());
	greyImage.allocate(video.getWidth(), video.getHeight());
	greyImageSmall.allocate(120, 90);

	haarFinder.setup("haarcascade_frontalface_alt2.xml");
	//haarFinder.setup("haarcascade_frontalface_default.xml");

	darth.loadImage("Darth Vader.png");
	darth.setAnchorPercent(0.5, 0.5);
	trooper.loadImage("Stormtrooper.png");
	trooper.setAnchorPercent(0.5,0.5);

	ofEnableAlphaBlending();
	//ofSetFrameRate(60);

}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	if (video.isFrameNew()) {
		colorImg.setFromPixels(video.getPixels(), video.getWidth(), video.getHeight());
		colorImg.mirror(false, true);

		greyImage = colorImg;

		greyImageSmall.scaleIntoMe(greyImage);

		haarFinder.findHaarObjects(greyImageSmall);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());

	glPushMatrix();
		glScalef(ofGetWidth() / (float)greyImageSmall.getWidth(), ofGetHeight() / (float)greyImageSmall.getHeight(), 1);
		//    haarTracker.draw(0, 0);
		ofNoFill();
		//cout << "orang tracked: " << haarFinder.blobs.size() << " orang";
		for (int i = 0; i < haarFinder.blobs.size(); i++) {
			ofRectangle faces = haarFinder.blobs[i].boundingRect;
					ofRect(faces.x, faces.y, faces.width, faces.height);
			int widthScale = faces.width * 1.4;

			cout << " minX: " << faces.getMinX();
			cout << " maxX: " << faces.getMaxX();

			if (faces.getMinX() < 40) {
				darth.draw(haarFinder.blobs[i].centroid, widthScale, widthScale * darth.getHeight() / darth.getWidth());
			}
			else
			{
				trooper.draw(haarFinder.blobs[i].centroid, widthScale, widthScale * darth.getHeight() / darth.getWidth());
			}
		}
	glPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
