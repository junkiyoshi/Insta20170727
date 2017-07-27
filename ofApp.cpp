#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");
	
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	float angle, x, y;

	for (int r = 50; r <= 250; r += 25) {

		angle = ofNoise(0) * 360;
		x = r * cos(angle * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD);
		Particle* p = new Particle(ofVec3f(x, y, 0), 5, ofColor(255, 0, 0));
		this->particles.push_back(p);

		p = new Particle(ofVec3f(-x, -y, 0), 5, ofColor(255, 0, 0));
		this->particles.push_back(p);

		angle += 90;

		x = r * cos(angle * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD);
		p = new Particle(ofVec3f(x, y, 0), 5, ofColor(255, 0, 0));
		this->particles.push_back(p);

		p = new Particle(ofVec3f(-x, -y, 0), 5, ofColor(255, 0, 0));
		this->particles.push_back(p);

		angle += 30;
		x = r * cos(angle * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD);
		p = new Particle(ofVec3f(x, y, 0), 5, ofColor(0, 255, 0));
		this->particles.push_back(p);

		p = new Particle(ofVec3f(-x, -y, 0), 5, ofColor(0, 255, 0));
		this->particles.push_back(p);

		angle += 90;
		x = r * cos(angle * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD);
		p = new Particle(ofVec3f(x, y, 0), 5, ofColor(0, 255, 0));
		this->particles.push_back(p);

		p = new Particle(ofVec3f(-x, -y, 0), 5, ofColor(0, 255, 0));
		this->particles.push_back(p);
		
		angle += 30;
		x = r * cos(angle * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD);
		p = new Particle(ofVec3f(x, y, 0), 5, ofColor(0, 0, 255));
		this->particles.push_back(p);

		p = new Particle(ofVec3f(-x, -y, 0), 5, ofColor(0, 0, 255));
		this->particles.push_back(p);

		angle += 90;
		x = r * cos(angle * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD);
		p = new Particle(ofVec3f(x, y, 0), 5, ofColor(0, 0, 255));
		this->particles.push_back(p);

		p = new Particle(ofVec3f(-x, -y, 0), 5, ofColor(0, 0, 255));
		this->particles.push_back(p);

	}
}

//--------------------------------------------------------------
void ofApp::update() {

	int i = 0;
	for (int r = 50; r <= 250; r += 25) {
		float angle = ofNoise(ofGetFrameNum() * 0.005) * 360;
		float angle_2 = ofNoise(ofGetFrameNum() * 0.025) * 720;

		float x = r * cos(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		float y = r * sin(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		float z = r * cos(angle_2 * DEG_TO_RAD);

		this->particles[i + 0]->update(ofVec3f(x, y, z));
		this->particles[i + 1]->update(ofVec3f(-x, -y, -z));

		angle += 90;
		x = r * cos(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		z = r * cos(angle_2 * DEG_TO_RAD);

		this->particles[i + 2]->update(ofVec3f(x, y, z));
		this->particles[i + 3]->update(ofVec3f(-x, -y, -z));

		angle += 30;
		x = r * cos(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		z = r * cos(angle_2 * DEG_TO_RAD);
		
		this->particles[i + 4]->update(ofVec3f(x, y, z));
		this->particles[i + 5]->update(ofVec3f(-x, -y, -z));

		angle += 90;
		x = r * cos(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		z = r * cos(angle_2 * DEG_TO_RAD);

		this->particles[i + 6]->update(ofVec3f(x, y, z));
		this->particles[i + 7]->update(ofVec3f(-x, -y, -z));

		angle += 30;
		x = r * cos(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		z = r * cos(angle_2 * DEG_TO_RAD);

		this->particles[i + 8]->update(ofVec3f(x, y, z));
		this->particles[i + 9]->update(ofVec3f(-x, -y, -z));

		angle += 90;
		x = r * cos(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		y = r * sin(angle * DEG_TO_RAD) * sin(angle_2 * DEG_TO_RAD);
		z = r * cos(angle_2 * DEG_TO_RAD);

		this->particles[i + 10]->update(ofVec3f(x, y, z));
		this->particles[i + 11]->update(ofVec3f(-x, -y, -z));

		i += 12;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	//ofRotateX(90);
	//ofRotateZ(ofGetFrameNum() % 360);

	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->draw();
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}