#include "World.h"
#include "Organism.h"
#include "Swoopie.h"
#include "Zoomie.h"

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
}

// During one turn, all the Swoopies should move before the Zoomis do.
void World::SimulateOneStep() {
    // Implementation goes here
}
