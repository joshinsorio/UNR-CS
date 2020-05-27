#include <iostream>

#include "Sensor.h"
#include "Proj4.h"

using namespace std;

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

//Constructors
Sensor::Sensor() 
{
    setType("none");
};
Sensor::Sensor(const char * type) 
{
    setType(type);
};
Sensor::Sensor(const Sensor & sensor) 
{
    setType(sensor.m_type);
};

//Get methods
char * Sensor::getType() 
{ 
    return m_type; 
};

float Sensor::getExtraCost() 
{ 
    return m_extracost; 
};

//Set methods
void Sensor::setType(const char * type) 
{
    if (!myStringCompare(type, "gps")) 
    {
        Sensor::gps_cnt++;
        setExtraCost(5.0);
    } 

    else if (!myStringCompare(type, "camera")) 
    {
        Sensor::camera_cnt++;
        setExtraCost(10.0);
    } 
    else if (!myStringCompare(type, "lidar")) 
    {
        Sensor::lidar_cnt++;
        setExtraCost(15.0);
    } 
    else if (!myStringCompare(type, "radar")) 
    {
        Sensor::radar_cnt++;
        setExtraCost(20.0); 
    } 
    else 
    {
        // "none" type
        setExtraCost(0);
    }
        myStringCopy(m_type, type);
    
};

void Sensor::setExtraCost(const float extracost) 
{ 
    m_extracost = extracost; 
};

int Sensor::getGPSCnt() 
{ 
    return Sensor::gps_cnt; 
};

int Sensor::getCameraCnt() 
{ 
    return Sensor::camera_cnt; 
};

int Sensor::getLidarCnt() 
{ 
    return Sensor::lidar_cnt; 
};

int Sensor::getRadarCnt() 
{ 
    return Sensor::radar_cnt; 
};

void Sensor::resetGPSCnt() 
{ 
    Sensor::gps_cnt = 0; 
};

void Sensor::resetCameraCnt() 
{ 
    Sensor::camera_cnt = 0; 
};

void Sensor::resetLidarCnt() 
{ 
    Sensor::lidar_cnt = 0; 
};

void Sensor::resetRadarCnt() 
{ 
    Sensor::radar_cnt = 0; 
};

bool operator ==(Sensor & s1, Sensor & s2) {
    return !myStringCompare(s1.getType(), s2.getType());
}

