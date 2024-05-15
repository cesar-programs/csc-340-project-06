#include "World.h"
#include "Organism.h"
#include "Predator.h"
#include "Prey.h"

World::World() {
    // Implementation goes here
}

World::~World() {
    // Implementation goes here
}

// Return the organism at a given location in the grid
Organism* World::getAt(int x, int y) {
    if (x < 0 || x >= WORLDSIZE || y < 0 || y >= WORLDSIZE) {
        return nullptr;
    }
    return grid[x][y];
}

// Set the organism at a given location in the grid
void World::setAt(int x, int y, Organism *org) {
    // Implementation goes here
    if (x < 0 || x >= WORLDSIZE || y < 0 || y >= WORLDSIZE) {
        return;
    }
    grid[x][y] = org;
}

void World::Display() {
    // Implementation goes here
    for (auto & i : grid) {
        for (int j = 0; j < WORLDSIZE; j++) {
            if (i[j] == nullptr) {
                std::cout << "_";
            } else {
                if (i[j]->getType() == 1) {
                    std::cout << "X";
                } else {
                    std::cout << "O";
                }
            }
        }
        std::cout << std::endl;
    }
}

// During one turn, all the Swoopies should move before the Zoomis do.
void World::SimulateOneStep() {
    SimulateOneStepPredators();
    SimulateOneStepPreys();
    Display();
}

void World::pushPredator(Organism* pred) {
    // Implementation goes here
    Predators.push_back(pred);
}

void World::pushPrey(Organism* prey) {
    // Implementation goes here
    Preys.push_back(prey);
}

void World::SimulateOneStepPredators() {
    // Implementation goes here
    for (auto & pred : Predators) {
        pred->move();
        pred->breed();
        pred->starve();
    }
}

void World::SimulateOneStepPreys() {
    // Implementation goes here
    for (auto & prey : Preys) {
        prey->move();
        prey->breed();
    }
}
