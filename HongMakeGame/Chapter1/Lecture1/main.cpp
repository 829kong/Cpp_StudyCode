#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"
namespace jm
{
	class RotatingStarExample : public Game2D
	{
		float time = 0.0f;

	public:
		void update() override
		{
			rotate(time * 180.0f);
			drawFilledStar(Colors::gold, 0.4f, 0.25f);

			time += this->getTimeStep();
		}
	};
};

int main(void)
{
	//jm::mouseexample().init("this is my digital canvas!", 1000, 1000, false).run();
	//jm::game2d().init("this is my digital canvas!", 1280, 960, false).run();
	jm::RotatingStarExample().init("Rotating Star Example", 1280, 960, false).run();
	//jm::primitivesgallery().init("primitive gallery", 1280, 960, false).run();
	//jm::solarsystem().run();
	//jm::faceexample().run();
	//jm::walkingperson().run();
	//jm::tankexample().run();

	return 0;
}
