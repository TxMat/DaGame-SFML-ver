//
// Created by uranus on 15/05/24.
//

#ifndef CMAKESFMLPROJECT_DTFIXEDTIME_H
#define CMAKESFMLPROJECT_DTFIXEDTIME_H


#include "../../../../Common/Base/UITextElement.h"

class DTFixedTime : public UITextElement{

public:
    DTFixedTime();

    void Update(float deltaTime) override;

};


#endif //CMAKESFMLPROJECT_DTFIXEDTIME_H
