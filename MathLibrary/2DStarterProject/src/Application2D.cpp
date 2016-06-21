#include "Application2D.h"
#include <GLFW/glfw3.h>
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include <fstream>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	nodes.push_back(new Node());
	nodes.push_back(new Node());
	nodes.push_back(new Node());
	nodes.push_back(new Node());
	nodes[0]->setParent(nodes[1]);
	nodes[1]->setParent(nodes[2]);
	nodes[2]->setParent(nodes[3]);
	nodes[3]->m_localTransform = Matrix3(.3, 0, 0, 0, .3, 0, 600, 350, .3);
	nodes[2]->m_localTransform = Matrix3(1, 0, 0, 0, 1, 0, 600, 0, 1);
	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	static float i, k;
	i += .01;
	Matrix3 rotate, rotate2;
	rotate.setRotateZ(i * deltaTime);
	nodes[3]->m_localTransform = nodes[3]->m_localTransform * rotate;
	nodes[1]->m_localTransform = nodes[1]->m_localTransform * rotate;
	nodes[0]->m_localTransform = nodes[0]->m_localTransform * Matrix3(0.99995, 0, 0, 0, 1.0003, 0, 0, 0, 1);
	nodes[3]->UpdateTransforms();




	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	//press 1 to save and 2 to load

	if (isKeyPressed(GLFW_KEY_1))
	{
		std::ofstream savedFile;
		savedFile.open("Saved Position.txt");
		for (int i = 0; i < nodes.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					savedFile << nodes[i]->m_globalTransform(j, k) << " ";
				}
			}
		}
		savedFile.close();
	};
	
	
	if (isKeyPressed(GLFW_KEY_2))
	{
		std::ifstream savedFile;
		savedFile.open("Saved Position.txt");
		for (int i = 0; i < nodes.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					savedFile >> nodes[i]->m_globalTransform(j, k);
				}
			}
		}
		savedFile.close();
	};

	// the applciation closes if we return false

	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	m_spriteBatch->drawSpriteTransformed3x3(m_texture, nodes[0]->m_globalTransform);
	m_spriteBatch->drawSpriteTransformed3x3(m_texture, nodes[3]->m_globalTransform);


	// done drawing sprites
	m_spriteBatch->end();
}