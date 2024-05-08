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

Organism* World::getAt(int x, int y) {
    // Implementation goes here
}

void World::setAt(int x, int y, Organism *org) {
    // Implementation goes here
}

void World::Display() {
    // Implementation goes here
}

// During one turn, all the Swoopies should move before the Zoomis do.
void World::SimulateOneStep() {
    // Implementation goes here
}
