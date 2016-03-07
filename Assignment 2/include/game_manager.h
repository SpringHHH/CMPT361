//////////////////////////////////////////////////////////////////////////////
//
//  lib_consts.h
//
//  The header file for all global constants
//
//  Project         : FruitTetris
//  Name            : Chong Guo
//  Student ID      : 301295753
//  SFU username    : armourg
//  Instructor      : Thomas Shermer
//  TA              : Luwei Yang
//
//  Created by Armour on 2/3/2016
//  Copyright (c) 2016 Armour. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef FRUITTETRIS_GAME_MANAGER_H_
#define FRUITTETRIS_GAME_MANAGER_H_

#include <vector>
#include <stack>
#include "lib_gl.h"
#include "lib_consts.h"

enum class GameState {              // Game states
    GameStateEmpty,
    GameStateEasy,
    GameStateNormal,
    GameStateHard,
    GameStateInsane,
    GameStatePause,
    GameStateEnd
};

class GameManager {
private:
    int tick_interval_;             // Current tick interval
    int tile_current_shape_;        // Current tile shape
    int tile_current_orient_;       // Current tile orientation
    int tile_current_color_[libconsts::kCountCells];        // Current tile color
    int tile_current_state_;        // Current tile state
    glm::vec2 tile_current_position_;       // Current tile position
    glm::vec2 map_size_;
    glm::vec3 spawn_point_;           // The point that spawn tile

    std::stack<GameState> game_states_;     // Gamestate stack
    std::vector<std::vector<int>> map_;     // Map color data

private:
    int DropOneBlock();             // Drop one block
    int CheckBoundary();            // Check boundary
    bool CheckCollision();          // Check collision
    void CheckElimination();        // Check elimination
    void EliminateRow(int row);     // Eliminate one row
    void FillTileToMap();           // Fill current tile to map
    void ChangeGameMode(GameState state);

public:
    GameManager() {};

    void Init(int width, int height);

    void AddNewTile();                          // Generate new tile
    void Tick();                                // Time tick function
    int MoveTile(glm::vec2 direction);
    int RotateTile(int direction);
    void UpdateTilePosition();                  // Update tile position if in robot arm

    glm::vec3 CalculateFitPosition(glm::vec4 end_point);    // Get the block that fits the end point best

    void Easy();            // Game mode
    void Normal();
    void Hard();
    void Insane();

    void Pause();           // Game state
    void Resume();
    void Restart();

    inline int get_tick_interval() const {
        return tick_interval_;
    }

    inline int get_tile_current_shape() const {
        return tile_current_shape_;
    }

    inline int get_tile_current_orient() const {
        return tile_current_orient_;
    }

    inline int *get_tile_current_color() {
        return tile_current_color_;
    }

    inline glm::vec2 get_tile_current_position() const {
        return tile_current_position_;
    }

    inline int get_tile_current_state() const {
        return tile_current_state_;
    }

    inline GameState get_game_state() const {
        if (!game_states_.empty())
            return game_states_.top();
        else
            return GameState::GameStateEmpty;
    }

    inline glm::vec2 get_map_size() const {
        return map_size_;
    }

    inline std::vector<std::vector<int>> &get_map_data() {
        return map_;
    }

    inline void set_spawn_point(glm::vec3 point) {
        spawn_point_ = point;
    }

    inline void set_tile_state_on_air() {
        tile_current_state_ = libconsts::kStateOnAir;
    }

    inline bool IsDroppable() {
        return (CheckBoundary() == libconsts::kInBoundary && !CheckCollision());
    }
};

#endif //FRUITTETRIS_GAME_MANAGER_H_
