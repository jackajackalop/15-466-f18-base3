#pragma once

#include "Mode.hpp"

#include "MeshBuffer.hpp"
#include "GL.hpp"

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>

// The 'GameMode' mode is the main gameplay mode:

struct GameMode : public Mode {
	GameMode();
	virtual ~GameMode();

	//handle_event is called when new mouse or keyboard events are received:
	// (note that this might be many times per frame or never)
	//The function should return 'true' if it handled the event.
	virtual bool handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) override;

    virtual void select(uint32_t);
    virtual void clear_selection();
	//update is called at the start of a new frame, after events are handled:
	virtual void update(float elapsed) override;

	//draw is called after update:
	virtual void draw(glm::uvec2 const &drawable_size) override;

    //for managing game state
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                            'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                            't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<uint32_t> correct;
    std::vector<bool> selected = {false, false, false, false, false, false,
                            false, false, false, false, false, false, false,
                            false, false, false, false, false, false, false,
                            false, false, false, false, false, false};

    std::vector<uint32_t> current;
    std::vector<uint32_t> cube_order;
    std::vector<uint32_t> to_show;
    bool win = false;
    uint32_t level = 1;
    float total_time = 0.0f;

	float camera_spin = 0.0f;
	float spot_spin = 0.0f;
};
