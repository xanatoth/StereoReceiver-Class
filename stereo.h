/*
 * Program Name: stereo.h
 * Author:David Bommarito
 * Last Updated: 9/9/2022
 * Purpose: Stereo Receiver class header file with declarations
 */

#ifndef M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H
#define M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H


#include <string>
#include <iostream>



using namespace std;
namespace Stereo {
    class StereoReceiver {
    private:
        bool Power;
        string Manufacturer;
        string Model;
        string Color;
        string SerialNumber;
        float Wattage;
        int Channel;
        string Band;
        float Frequency;
        int Volume;

    public: //method declarations to get and set different values
        void setPower();
        int getPower();
        void setManufacturer();
        string getManufacturer();
        void setModel();
        string getModel();
        string getSerialNumber();
        void setSerialNumber();
        void setWattage();
        int getWattage();
        void setFrequency(StereoReceiver& receiver);
        float getFrequency();
        int getChannel();
        void setVolume();
        void setChannel();
        int getVolume();
        string getColor();
        void setColor();
        string getBand();
        void setBand();
        void createReceiver();
        StereoReceiver();
    };
}
#endif //M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H