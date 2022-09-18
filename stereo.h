/*
 * Program Name: stereo.h
 * Author:David Bommarito
 * Last Updated: 9/17/2022
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
        double Wattage;
        int Channel;
        string Band;
        double Frequency;
        int Volume;

    public: //method declarations to get and set different values
        string getBand();
        int getChannel();
        string getColor();
        double getFrequency();
        string getManufacturer();
        string getModel();
        bool getPower();
        string getSerialNumber();
        int getVolume();
        double getWattage();
        void setBand();
        void setChannel();
        void setColor();
        void setFrequency();
        void setManufacturer();
        void setModel();
        void setPower();
        void setSerialNumber();
        void setVolume();
        void setWattage();
        //constructor
        StereoReceiver();
        };
    };

#endif //M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H