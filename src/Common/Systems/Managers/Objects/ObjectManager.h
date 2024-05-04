//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_OBJECTMANAGER_H
#define CMAKESFMLPROJECT_OBJECTMANAGER_H


#include <vector>
#include "../Base/BaseManager.h"
#include "../../../Base/Object.h"

class ObjectManager : public BaseManager {

public:

    ObjectManager();

    void FixedTick(float deltaTime) override;

    void Render(sf::RenderWindow &window) override;

    void AddObject(Object *object);

    void UnrestrictedTick(float deltaTime) override;

//    void Destroy(Object *object) {
//        delete object;
//        m_globalObjectList.erase(std::remove(m_globalObjectList.begin(), m_globalObjectList.end(), object),
//                                 m_globalObjectList.end());
//    }

protected:
    std::vector<Object *> m_globalObjectList;
    std::vector<Object *> m_fastGlobalObjectList;

    // todo store a physics object list or better perf and increased ram usage

    sf::Clock inner;
    sf::Time m_tickFramerate = sf::seconds(1.f / 144);

    static void TickInternal(float deltaTime, const std::vector<Object *> &objectList);
};


#endif //CMAKESFMLPROJECT_OBJECTMANAGER_H
