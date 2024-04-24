#pragma once

class Player
{
public:
	Player();
	Player(int playerId);
	~Player();

	void UpdateDirection();
	void UpdatePhysics();
	void UpdateCollision();
	void Draw(RenderWindow* window);
	void DrawTrail(RenderWindow* window);

	float GetX();
	float GetY();

	float GetLastX();
	float GetLastY();

	void SetPos(float posX, float posY);
	void SetX(float posX);
	void SetY(float posY);

	enum
	{
		NONE,
		UP,
		DOWN,
		RIGHT,
		LEFT,
	};

private:
	string name;
	int m_r;
	int m_g;
	int m_b;
	int m_playerId;
	float m_posX;
	float m_posY;
	float m_last_posX;
	float m_last_posY;
	int m_direction;
	float m_vitesse = 50.0f;
	VertexBuffer m_buffer;
};
