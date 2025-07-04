#pragma once
#include <SDL3/SDL.h>
#include <cstdint>

class Time {
private:
	// Frame timing
	uint64_t frameCount = 0;
	float deltaTime = 0.0f;
	float lastFrameTime = 0.0f;
	float currentFrameTime = 0.0f;

	// Frame rate control
	float targetFrameRate = 60.0f; // Target frame rate in FPS
	int targetFrameTimeMs = 0;
	float targetFrameTime = 0.0f;

	// Time scaling
	float timeScale = 1.0f; // Default time scale is 1.0 (normal speed)

	// State
	bool isPaused = false; // Pause state

public:
	Time(float targetFPS = 30.0f);
	~Time() = default;

	//void start();
	//void update();
	//bool shouldProcessFrame() const;
	//void frameEnd();
	//void delay() const;

	//// Getters
	//float GetDeltaTime() const { return deltaTime * timeScale; }
	//float GetRawDeltaTime() const { return deltaTime; }
	//float GetTimeScale() const { return timeScale; }
	//uint64_t GetFrameCount() const { return frameCount; }
	//float GetCurrentTime() const { return currentTime; }
	//float GetTargetFrameRate() const { return targetFrameRate; }

	//// Setters
	//void SetTimeScale(float scale) { timeScale = scale; }
	//void SetTargetFrameRate(float fps);

	//// State control
	//void Pause() { isPaused = true; }
	//void Resume() { isPaused = false; lastFrameTime = SDL_GetTicks(); }
	//bool IsPaused() const { return isPaused; }



};

