//
// Created by minau on 4/23/2023.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H

#include <iostream>
#include <SFML/Graphics.hpp>

enum stateEnum
{
    IS_FILE,
    IS_FOLDER,
    HIDDEN,
    SHOWN,
    CLICKED,
    HIGHLIGHTED,
    DISABLED,
    ENABLED,
    LASTSTATE

};

class States
{
private:
    std::map<stateEnum, bool> map;
    void load();
    void enableAllStates();
    void disableAllStates();
public:
    States();
    bool checkState(stateEnum state) const;
    void enableState(stateEnum state);
    void disableStates(stateEnum state);
    void setState(stateEnum state, bool value);
    void toggleState(stateEnum states);
};


#endif //SFML_PROJECT_STATES_H
