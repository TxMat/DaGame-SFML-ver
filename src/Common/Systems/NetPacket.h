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
    unsigned int id;
    std::vector<uint8_t> payload;

    NetworkPacket(PacketType pt, unsigned int object_id, const std::vector<uint8_t> &payload) : pt(pt), id(object_id), payload(payload) {
        ts = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch());
    }

    std::vector<char> ToVec() {
        std::vector<char> p;

        // Serialize pt
        const auto* ptt = reinterpret_cast<const char*>(&pt);
        p.insert(p.end(), ptt, ptt + sizeof(pt));

        // Serialize ts
        const auto* tst = reinterpret_cast<const char*>(&ts);
        p.insert(p.end(), tst, tst + sizeof(ts));

        // Serialize id
        const auto* idt = reinterpret_cast<const char*>(&id);
        p.insert(p.end(), idt, idt + sizeof(idt));

        // insert payload
        p.insert(p.end(), payload.begin(), payload.end());

        return p;
    }

    std::string ToString()
    {
        std::vector<uint8_t> p;

        // Serialize pt
        const auto* ptt = reinterpret_cast<const uint8_t*>(&pt);
        p.insert(p.end(), ptt, ptt + sizeof(pt));
        
        // Serialize ts
        const auto* tst = reinterpret_cast<const uint8_t*>(&ts);
        p.insert(p.end(), tst, tst + sizeof(ts));

        // insert payload
        p.insert(p.end(), payload.begin(), payload.end());
        
        std::string str(p.begin(), p.end());
        //std::string str = reinterpret_cast<char*>(p.data());

        return str;
    }
};

#endif //CMAKESFMLPROJECT_NETPACKET_H
