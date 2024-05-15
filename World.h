/**
 * @file World.h
 * @brief Defines the World class which manages a 2D grid of Organism objects.
 *
 * @class World
 *
 * @details World is managed via various public methods, with access provided 
 * to Organism, Predator and Prey. It includes grid access, display functionality,
 * and simulation step methods. The size of the grid is defined by the private constant WORLDSIZE.
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

// These are forward declarations; they are used because World uses pointers to these classes, but does not need to know their internal details.
class Organism; 
class Predator;
class Prey;

class World
{
    friend class Organism;
    friend class Predator;
    friend class Prey;

    std::vector<Organism*> Predators;
    std::vector<Organism*> Preys;

public:
    World();
    ~World();
    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org); // If organism is predator, add to Predators vector. If organism is prey, add to Preys vector.
    void Display();
    void SimulateOneStep(); // First call simulateOneStepPredators, then simulateOneStepPreys
    void pushPredator(Organism* pred); // Adds predator to Predators vector
    void pushPrey(Organism* prey); // Adds prey to Preys vector
    void SimulateOneStepPredators(); // Simulates one step for all predators
    void SimulateOneStepPreys(); // Simulates one step for all preys
    void InitializeGame(); // Initializes the game by user inputting an amount of predators and preys
    void GameLoop(); // Runs the game loop
private:
    static constexpr int WORLDSIZE = 30;
    Organism* grid[WORLDSIZE][WORLDSIZE];
};

#endif // WORLD_H