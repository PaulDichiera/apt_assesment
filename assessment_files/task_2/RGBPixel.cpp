#include <exception>
#include <stdexcept>
#include "RGBPixel.h"

RGBPixel::RGBPixel(){
    this->r = ZERO;
    this->g = ZERO;
    this->b = ZERO;

    //Build constructor, sets rgb all to 0
}

RGBPixel::RGBPixel(unsigned int r, unsigned int g, unsigned int b){
    this->r = r;
    this->g = g;
    this->b = b;

    //Build set channels to rgb
}

RGBPixel::~RGBPixel(){
    //deconstructor
}

unsigned int RGBPixel::getBrightness() const {
    //Return brightness of pixel
    // brightness (r + g + b) / 3
    return (r + g + b) / 3;
}

unsigned int& RGBPixel::operator[](const char channel){
    //shoudl retrurn a reference to the corresponding channel of that pixel
    // r <- red channel 
    // g <- green channel
    // b <- blue channel

    switch(channel){
        case 'r': return this->r;
        case 'g': return this->g;
        case 'b': return this->b;
        default: return;
    }

}