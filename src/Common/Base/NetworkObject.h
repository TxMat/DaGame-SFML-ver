//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_NETWORKOBJECT_H
#define CMAKESFMLPROJECT_NETWORKOBJECT_H


#include "Object.h"

class NetworkObject : public Object {

public:
    NetworkObject(sf::Shape *mShape, const std::string &name);

    virtual void GetNetworkPacket() = 0;

};


#endif //CMAKESFMLPROJECT_NETWORKOBJECT_H
