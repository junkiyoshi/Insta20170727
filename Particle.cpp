#include "particle.h"

Particle::Particle() : Particle(ofVec3f(0, 0, 0), 10, ofColor(255)) {

}

Particle::Particle(ofVec3f location, float radius, ofColor color) {
	this->locations.push_back(location);
	this->radius = radius;
	this->body_color = color;

	this->log_size = 14;
}

Particle::~Particle() {

}

void Particle::update(ofVec3f next) {
	this->locations.push_back(next);

	if (this->locations.size() > this->log_size) {
		this->locations.erase(this->locations.begin());
	}
}

void Particle::draw() {

	ofSetColor(this->body_color);

	//this->sphere.set(this->radius, 8);
	//this->sphere.setPosition(this->locations[this->locations.size() - 1]);
	//this->sphere.draw();

	for (int i = this->locations.size() - 1; i > 0; i--) {
		ofLine(this->locations[i], this->locations[i - 1]);
	}
}