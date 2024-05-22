//
// Created by uranus on 04/05/24.
//

#ifndef CMAKESFMLPROJECT_SCOREUI_H
#define CMAKESFMLPROJECT_SCOREUI_H


#include "../../../../Common/Base/UITextElement.h"
#include "../../../../Common/Player.h"

class ScoreUi : UITextElement {

public:
    Player player_;

    ScoreUi();

    void AddPointsToPlayers();
    void ResetScore();
    void UpdateScores();

private:
    void Update(float deltaTime) override;

};


#endif //CMAKESFMLPROJECT_SCOREUI_H
