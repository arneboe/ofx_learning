#include "Cat.hpp"

Cat::Cat(double x, double y, const std::string& file, b2World* world)
{
    catImg.loadImage(file);
    collision = std::make_shared<Circle>();
    collision->setPhysics(1.0, 0.6, 0.1);
    collision->setup(world, x, y, catImg.getWidth() / 2.0);
    collision->setAngularDamping(4.0);
    miau.loadSound("/home/arne/miau.wav");
    miau.setMultiPlay(true);
    miau.setSpeed(1.25);
}

void Cat::update()
{
    // const ofVec2f mouse(mouseX, mouseY);
    // const ofVec2f dist = collision->getPosition() - mouse - radius;
    // if(dist.length() < collision->getRadius() + radius)
    // {
    //     collision->addImpulseForce(ofVec2f{0, 0}, dist);
    //     miau.play();
    // }
}

const b2Body* Cat::getBody() const
{
    return collision->body;
}

void Cat::hit()
{
    miau.play();
}

void Cat::draw()
{
    ofPushMatrix();
        ofTranslate(collision->getPosition());
        ofRotateDeg(collision->getRotation());//rotate from centre
        catImg.draw(- catImg.getWidth()/2.0, - catImg.getHeight()/2);//move back by the centre offset
    ofPopMatrix();    
}