#include "App.hpp"

App::App()
{
}

void App::setup()
{
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetWindowTitle("Ball Physics");
    ofSetBackgroundColor(ofColor::black);

    b2dWorld.init(60, 0, 9.81);
    b2dWorld.createBounds();

    catImg.loadImage("/home/arne/3mbcatfmII.png");
    for(int i = 0; i < 20; ++i)
    {
        circles.push_back(std::make_shared<Circle>());
        circles.back()->setPhysics(1.0, 0.6, 0.1);
        circles.back()->setup(b2dWorld.getWorld(), ofRandomWidth(), ofRandomHeight(), catImg.getWidth() / 2.0);
        rots.push_back(0);
    }

    miau.loadSound("/home/arne/miau.wav");
    miau.setMultiPlay(true);
    miau.setSpeed(1.25);


}

void App::update()
{
    b2dWorld.update();
    ofVec2f mouse(mouseX, mouseY);
    for(int i = 0; i < circles.size(); i++)
    {
        const CirclePtr& c = circles[i];
        const ofVec2f dist = c->getPosition() - mouse;
        if(dist.length() < c->getRadius())
        {
            c->addImpulseForce(ofVec2f{0, 0}, dist);
            rots[i] = 20;
            miau.play();
        }
    }
}

void App::draw()
{
    ofSetColor(ofColor::white);
    ofNoFill();

    for(int i = 0; i < circles.size(); i++)
    {
        const CirclePtr& c = circles[i];

        ofPushMatrix();
            ofTranslate(c->getPosition());
            ofRotateRad(rots[i]);//rotate from centre
            rots[i] *= 0.95;
            if(rots[i] < 0) rots[i] = 0;
            catImg.draw(- catImg.getWidth()/2.0, - catImg.getHeight()/2);//move back by the centre offset
        ofPopMatrix();
        // 

        // ofPushMatrix();
        // ofRotateDeg(12);
        // 
        // catImg.draw(0, 0);
        // ofPopMatrix();
        // c->draw();
    }
    ofFill();
    ofSetColor(ofColor::magenta);
    ofCircle(mouseX, mouseY, mouseRadius);
}

void App::keyPressed(int key)
{
}

void App::keyReleased(int key)
{
}

void App::mouseMoved(int x, int y)
{    

}

void App::mouseDragged(int x, int y, int button)
{

}

void App::mousePressed(int x, int y, int button)
{

}

void App::mouseReleased(int x, int y, int button)
{
}

void App::mouseEntered(int x, int y)
{
}

void App::mouseExited(int x, int y)
{
}

void App::windowResized(int w, int h)
{
}

void App::gotMessage(ofMessage msg)
{
}

void App::dragEvent(ofDragInfo dragInfo)
{
}
