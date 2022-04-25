#pragma once

#include "Game2D.h"

namespace jm
{
	std::random_device rd;
	std::mt19937 num(rd());
	std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
	/*
	TODO:
	- add left arm and left leg
	- make a Person class and use it to draw many people.
	- make an Ironman and allow for him to shoot repulsor beam with his right hand
	*/
	class Person
	{
	private:
		float time = 0.0f;
		float m_x = 0.0f;

	public:
		void draw(const float& dt)
		{
			// gold face
	
			beginTransformation();
			translate(0.0f, 0.12f);
			drawFilledCircle(Colors::gold, 0.08f);
			translate(0.05f, 0.03f);
			drawFilledCircle(Colors::white, 0.01f); // while eye
			endTransformation();

			// yellow left arm
			beginTransformation();
			rotate(-sin(time * 5.0f) * 30.0f);					// animation!
			scale(1.0f, 2.0f);
			translate(0.0f , -0.1f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// green left leg
			beginTransformation();
			translate(0.0f, -0.6f);
			translate(0.0f, 0.2f);
			rotate(-sinf(time * 5.0f + 3.141592f) * 30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();


			// red body
			beginTransformation();
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::red, 0.13f, 0.2f);
			endTransformation();

			// yellow right arm 
			beginTransformation();
			rotate(sin(time * 5.0f) * 30.0f);					// animation!
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// green right leg
			beginTransformation();
			translate(0.0f, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * 5.0f + 3.141592f) * 30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();
			
			time += dt;
		}

	};

	class WalkingPerson : public Game2D
	{
	private:
		std::vector<Person*> person;
		float m_x = 0.0f;
		


	public:
		WalkingPerson()
		{
			/*for (int i = 0; i < 5; i++)
			{
				p[i] = new Person();              
			}*/
		}

		~WalkingPerson()
		{
			/*for (int i = 0; i < 5; i++)
			{
				delete p[i];                
				p[i] = nullptr;
			}*/
		}

		void update() override 
		{
			//Ground
			beginTransformation();
			translate(0.0f, -0.8f);
			drawFilledBox(Colors::black, 3.0f, 0.4f);
			endTransformation();

			if (isKeyPressedAndReleased(GLFW_KEY_SPACE))
			{
				person.push_back(new Person);
				cout << person.size() << endl;
				
				
			}

			if (isKeyPressedAndReleased(GLFW_KEY_0))
			{	
				if (!person.empty())
				{
					delete person.front();
					person.erase(person.begin());
					cout << "delete Person" << endl;
				}
			}

			if (!person.empty())
			{
				//translate(m_x, 0.0f);
				person.back()->draw(getTimeStep());
			
				//m_x += 0.1f;
			}
			

			//for (int i = 0; i < 5; i++)
			//{
			//	translate(0.3f, 0.0f);
			//	p[i]->draw(getTimeStep());    // 각 사람을 그려준다. 
			//}
		}
			
	};

	
}