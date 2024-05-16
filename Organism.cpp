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

    std::vector<std::pair<int, int>> adjacentCells = {
        std::make_pair(this->x, this->y + 1),
        std::make_pair(this->x, this->y - 1),
        std::make_pair(this->x + 1, this->y),
        std::make_pair(this->x - 1, this->y)
    };

    int random = rand() % adjacentCells.size();
    int newX = adjacentCells[random].first;
    int newY = adjacentCells[random].second;

    if (newX >= 0 
            && newX < world->WORLDSIZE 
            && newY >= 0 
            && newY < world->WORLDSIZE
            && world->getAt(newX, newY) == nullptr) {
        world->setAt(newX, newY, this);
        world->setAt(this->x, this->y, nullptr);
        this->x = newX;
        this->y = newY;
    }
}

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
    this->peripheral.push_back(world->getAt(x, y - 1) ? world->getAt(x, y - 1)->getType(): 0); // Check up
    this->peripheral.push_back(world->getAt(x, y + 1) ? world->getAt(x, y + 1)->getType(): 0); // Check down
    this->peripheral.push_back(world->getAt(x - 1, y) ? world->getAt(x - 1, y)->getType(): 0); // Check left
    this->peripheral.push_back(world->getAt(x + 1, y) ? world->getAt(x + 1, y)->getType(): 0); // Check right
    std::cout << "Organism at (" << x << ", " << y << ") has the following peripheral: ";
    for (auto & i : peripheral) {
        std::cout << i << " ";
    }
}

bool Organism::operator==(const Organism &rhs)
{
    return x == rhs.x &&
           y == rhs.y &&
           moved == rhs.moved &&
           breedTicks == rhs.breedTicks &&
           world == rhs.world;
}