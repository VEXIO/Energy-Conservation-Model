//
// Created by Haotian on 2017/8/21.
//

#ifndef ENERGYCONSERVATIONMODEL_ANALYZETECHNIQUE_H
#define ENERGYCONSERVATIONMODEL_ANALYZETECHNIQUE_H

#include "Base.h"
#include <string>
#include <utility>
#include <map>

static const std::map<std::string, std::tuple<double, double, double>> EmissionList = {
        {"A_Corridor", {20.9622, 6.9, 27.8622}},
        {"A_Corridor_0", {24.1914, 6.9, 31.0914}},
        {"B_Corridor", {7.7142, 6.9, 14.6142}},
        {"C_Corridor", {8.832, 0, 8.832}},
        {"A_Elevator", {0, 3.7, 3.7}},
        {"A_AirCondition", {0, 1835.4, 1835.4}},
        {"BC_AirCondition", {0, 1104, 1104}},
};

class AnalyzeTechnique {
public:
    static double CheckStorey(const Student &student, const Classroom &classroom);
    static double CheckPlug(const Student &student, const Classroom &classroom);
    static double CheckCapacity(const Student &student, const Classroom &classroom);
    static double CheckPart(const Student &student, const Classroom &classroom);
};


#endif //ENERGYCONSERVATIONMODEL_ANALYZETECHNIQUE_H
