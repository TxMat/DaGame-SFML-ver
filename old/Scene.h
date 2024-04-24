#pragma once

class Scene
{
public:
	Scene();
	Scene(Grid* grid, Player* player1, Player* player2, sf::RenderWindow* window);
	~Scene();

public:
	bool IsPlaying();
	void SetPlaying(bool flag);
	void Start();
	void CheckPos();
	void CheckCollision();
	void CheckPlayerCollision(Player* player);
	void PlacePlayer();
	void Update();
	void DrawScene();
	void Render();

	Grid* GetGrid();

private:
	Grid* m_grid;
	Player* m_player1;
	Player* m_player2;
	sf::RenderWindow* m_window;
	bool m_isPlaying;

};
