//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_FPSCOUNTER_H
#define CMAKESFMLPROJECT_FPSCOUNTER_H


#include "../../../../Common/Base/Object.h"
#include "../../../../Common/Base/UITextElement.h"

class FPSCounter : public UITextElement {
public:

    explicit FPSCounter();

    void Update(float deltaTime) override;
};


#endif //CMAKESFMLPROJECT_FPSCOUNTER_H
