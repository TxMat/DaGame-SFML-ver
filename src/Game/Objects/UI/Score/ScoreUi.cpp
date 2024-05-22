//
// Created by uranus on 04/05/24.
//

#include "ScoreUi.h"


ScoreUi::ScoreUi() : UITextElement() {

}

void ScoreUi::AddPointsToPlayers()
{
	player_.playerScore++;
}

void ScoreUi::ResetScore()

{
	player_.playerScore = 0;
}

void ScoreUi::UpdateScores()
{

}

void ScoreUi::Update(float deltaTime) {

}
