#pragma once
#include <Matrix3.h>
#include "../2DStarterProject/Node.h"
#include "BaseApplication.h"
#include <vector>
class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();



protected:

	std::vector<Node*> nodes;
	SpriteBatch*	m_spriteBatch;
	Texture*		m_texture;
	Font*			m_font;
	Matrix3			m_matrix;
};