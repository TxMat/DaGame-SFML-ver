//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_PACKETTYPE_H
#define CMAKESFMLPROJECT_PACKETTYPE_H

enum PacketType : char {
    Conn = 0,
    ConnAck = 1,
    PosSync = 2,
};

#endif //CMAKESFMLPROJECT_PACKETTYPE_H
