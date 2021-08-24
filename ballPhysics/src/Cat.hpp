#pragma once
#include <string>
#include "ofImage.h"
#include "ofxBox2d.h"


using Circle = ofxBox2dCircle;
using CirclePtr = std::shared_ptr<Circle>;

class Cat
{
public:
    Cat(double x, double y, const std::string& file, b2World* world);

    void update();
    void draw();

    const b2Body* getBody() const;

    //tell the cat that it it something
    void hit();

private:


    ofImage catImg;
    ofSoundPlayer miau;
    CirclePtr collision;
};