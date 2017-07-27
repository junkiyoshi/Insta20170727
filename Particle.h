
#pragma once

#include "ofMain.h"

class Particle {
public:
	Particle();
	Particle(ofVec3f location, float radius, ofColor color);
	~Particle();
	void update(ofVec3f next);
	void draw();

private:
	vector<ofVec3f> locations;
	float radius;
	float log_size;
	ofColor body_color;

	ofSpherePrimitive sphere;
};