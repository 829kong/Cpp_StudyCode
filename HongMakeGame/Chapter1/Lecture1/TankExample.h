#pragma once

#include "Game2D.h"

namespace jm
{
	using namespace std;
	class MyTank
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				drawFilledBox(Colors::green, 0.25f, 0.1f); // body
				translate(-0.02f, 0.1f);
				drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
				translate(0.15f, 0.0f);
				drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
			}
			endTransformation();
		}
	};

	class MyBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt*0.1;
		}
	};

	class TankExample : public Game2D
	{
	private:
		int n;

	public:
		MyTank tank;

		//MyBullet *bullet = nullptr;
		vector<MyBullet*> bullets ;
		//TODO: allow multiple bullets
		//TODO: delete bullets when they go out of the screen

	public:
		TankExample()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2),n(0)
		{}

		~TankExample()
		{
			/*if (bullet != nullptr)
			{
				delete bullet;
			}*/
		}

		void update() override
		{
			// move tank
			if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_RIGHT))	tank.center.x += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_UP))		tank.center.y += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_DOWN))	tank.center.y -= 0.5f * getTimeStep();

			// shoot a cannon ball
			if (isKeyPressedAndReleased(GLFW_KEY_SPACE))
			{
				bullets.push_back(new MyBullet);
				bullets.back()->center = tank.center;
				bullets.back()->center.x += 0.2f;
				bullets.back()->center.y += 0.1f;
				bullets.back()->velocity = vec2(2.0f, 0.0f);
				cout << bullets.size() << endl;
				
			}

			if (!bullets.empty())
			{
				for (int i = 0; i < bullets.size(); ++i)
				{

					bullets.at(i)->update(getTimeStep());
					bullets.at(i)->draw();
					/*if (bullets.front()->center.x > 1.4f)
					{
						delete bullets.front();
						bullets.erase(bullets.begin());
						cout << "delete bullets" << endl;
					}*/
				}
			}
			// rendering
			tank.draw();
			if (!bullets.empty())
			{
				for (int i = 0; i < bullets.size(); i++)
				{
					if (bullets[i]->center.x > 1.5f)   
					{
						delete bullets[i];                  
						bullets.erase(bullets.begin() + i); 
					}
				}
			}
		}
	};
}