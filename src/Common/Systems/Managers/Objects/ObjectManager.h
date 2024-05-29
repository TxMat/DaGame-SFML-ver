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

    explicit ObjectManager(SceneManager* mSm) : BaseManager(mSm) {}

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
    std::vector<Object *> m_globalObjectList = std::vector<Object *>();
    std::vector<Object *> m_fastGlobalObjectList = std::vector<Object *>();

    // todo store a physics object list for better perf and increased ram usage

    static void TickInternal(float deltaTime, const std::vector<Object *> &objectList);
};


#endif //CMAKESFMLPROJECT_OBJECTMANAGER_H
