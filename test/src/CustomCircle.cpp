//
//  CustomCircle.cpp
//  test
//
//  Created by Emiko Namikawa on 2016/01/08.
//
//

#include "CustomCircle.h"

void CustomCircle::draw(){
    float radius = getRadius();
    ofPushMatrix();
    ofTranslate(getPosition().x, getPosition().y);
    ofFill();
    ofSetColor(31, 127, 255, 100);
    ofCircle(0, 0, radius);
    ofSetColor(31, 127, 255, 200);
    ofCircle(0, 0, radius * 0.7);
    ofPopMatrix();
}
