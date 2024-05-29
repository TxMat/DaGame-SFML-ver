//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_NETWORKOBJECT_H
#define CMAKESFMLPROJECT_NETWORKOBJECT_H


#include "Object.h"
#include "../Systems/NetPacket.h"

class NetworkObject : public Object {

public:
    NetworkObject(sf::Shape *mShape, const std::string &name);

    virtual NetworkPacket GetNetworkPacket() = 0;

};


#endif //CMAKESFMLPROJECT_NETWORKOBJECT_H
