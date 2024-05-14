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
    void pushPredator(Organism* pred);
    void pushPrey(Organism* prey);
    void SimulateOneStepPredators();
    void SimulateOneStepPreys();
private:
    static constexpr int WORLDSIZE = 30;
    Organism* grid[WORLDSIZE][WORLDSIZE];
};
