//
// Created by Haotian on 2017/8/20.
//

#include "Preprocessor.h"
#include <iostream>

bool Preprocessor::Init(const std::string &classFileName, const std::string &studentFileName) {
    finClass.open(classFileName);
    if (finClass.fail()) {
        std::cerr << "Fail to open class data file." << std::endl;
        return false;
    }

    finStudent.open(studentFileName);
    if (finStudent.fail()) {
        std::cerr << "Fail to open student data file." << std::endl;
        return false;
    }

    initialized = true;
    return true;
}

bool Preprocessor::Load() {
    if (!initialized) {
        std::cerr << "Not initialized yet." << std::endl;
        return false;
    }
    if (!LoadStudent()) {
        std::cerr << "Fail to load student data." << std::endl;
        return false;
    }

    if (!LoadClassroom()) {
        std::cerr << "Fail to load student data." << std::endl;
        return false;
    }
    return true;
}

bool Preprocessor::LoadStudent() {
    Student student;
    int currentCapacity, preferedCapacity, capacity;

    while (!finStudent.eof()) {
        finStudent >> student.grade >> student.gender >> student.storey >> student.plug;
        finStudent >> student.prefer[0] >> student.prefer[1] >> student.prefer[2];
        finStudent >> currentCapacity >> preferedCapacity >> capacity;
        student.capacity = static_cast<double>(preferedCapacity) / capacity;

        students.push_back(student);
    }
    return true;
}

bool Preprocessor::LoadClassroom() {
    Classroom classroom;
    while (!finClass.eof()) {
        finClass >> classroom.id >> classroom.capacity >> classroom.plug;
        finClass >> classroom.walts >> classroom.lightEmission >> classroom.airEmission >> classroom.combEmission;
        classroom.initialize();
        classrooms.push_back(classroom);
    }
    return true;
}
