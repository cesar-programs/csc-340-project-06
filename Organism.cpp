#include "Organism.h"

// Both constructors should initialize the world, x, y, moved, and breedTicks attributes
Organism::Organism()
{
    // Implementation goes here
    this->world = nullptr;
    this->x = 0;
    this->y = 0;
    moved = false;
    breedTicks = 0;
}

Organism::Organism(World *world, int x, int y) 
{
    this->world = world;
    this->x = x; // Set the x coordinate
    this->y = y; // Set the y coordinate
    moved = false; // Set moved to false
    breedTicks = 0; // Set breedTicks to 0
}

Organism::~Organism() 
{

    // Implementation goes here
}

// Definitions for breed, move, getType, and starve will go into derived classes
void Organism::move() {

} // Overriden in derived classes

void Organism::breed() {

} // Overriden in derived classes

int Organism::getType() {
    return 0;
} // Default return type is 0

// Call getAt to check what type of organism is there, if none, return nullptr
void Organism::checkPeripheral() {
    // Check the four cardinal directions for Prey / Predator / Empty
    // Prey = 1, Predator = 2, Empty / Out of bounds = 0 // Need to add conditional to check for out of bounds in other functions
    this->peripheral.clear();
    // Check up
    if (y - 1 < 0) {
        this->peripheral.push_back(-1);
    } else {
        this->peripheral.push_back(world->getAt(x, y - 1) ? world->getAt(x, y - 1)->getType() : 0);
    }
    // Check down
    if (y + 1 >= World::WORLDSIZE) {
        this->peripheral.push_back(-1);
    } else {
        this->peripheral.push_back(world->getAt(x, y + 1) ? world->getAt(x, y + 1)->getType() : 0);
    }
    // Check left
    if (x - 1 < 0) {
        this->peripheral.push_back(-1);
    } else {
        this->peripheral.push_back(world->getAt(x - 1, y) ? world->getAt(x - 1, y)->getType() : 0);
    }
    // Check right
    if (x + 1 >= World::WORLDSIZE) {
        this->peripheral.push_back(-1);
    } else {
        this->peripheral.push_back(world->getAt(x + 1, y) ? world->getAt(x + 1, y)->getType() : 0);
    }
}

std::vector<int> Organism::getPeripheral() {
    return this->peripheral;
}