#pragma once
#include "Utils.h"
#include "Camera.h"
using namespace Utils::WowTypes;
namespace Wow
{
	class GameManager
	{
	
	public:

		GameManager(void);
		~GameManager(void);
		static Camera * GetCamera();
		static bool WorldToScreen(Position pos);
		static void ClickToMove(Position pos);
		static void RotatePlayer(WowObject * object);
		static float GetOrientationToTarget(Vector3 & position);
		static float GoStraighToPoint(Vector3 & point);
		static float GetDistanceToPoint(Vector3 & start, Vector3 & end);
		static void RotatePlayer(Vector3 & point);
		static void GoToPoint(Vector3 & point);
	};
}

