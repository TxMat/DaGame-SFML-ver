//
// Created by uranus on 01/05/24.
//

#ifndef CMAKESFMLPROJECT_DT_H
#define CMAKESFMLPROJECT_DT_H


#include "../../../../Common/Base/Object.h"
#include "../../../../Common/Base/UITextElement.h"

class DT : public UITextElement {
public:

    explicit DT();

    void Update(float deltaTime) override;
};


#endif //CMAKESFMLPROJECT_DT_H
