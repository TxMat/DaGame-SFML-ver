//
// Created by uranus on 29/05/24.
//

#ifndef CMAKESFMLPROJECT_NETPACKET_H
#define CMAKESFMLPROJECT_NETPACKET_H

#include <chrono>
#include <vector>
#include "PacketType.h"

struct NetworkPacket {

    PacketType pt;
    std::chrono::nanoseconds ts{};
    std::vector<uint8_t> payload;

    NetworkPacket(PacketType pt, const std::vector<uint8_t> &payload) : pt(pt), payload(payload) {
        ts = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
    }

};

#endif //CMAKESFMLPROJECT_NETPACKET_H
