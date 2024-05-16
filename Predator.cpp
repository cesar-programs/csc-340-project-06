#include "Predator.h"
#include <cmath>

Predator::Predator()
{
    // Initialize Predator-specific attributes here, if any
}

Predator::Predator(World *world, int x, int y) : Organism(world, x, y)
{
    breedUpperBound = 8;
    world->setAt(x, y, this);
    world->pushPredator(this);
}

Predator::~Predator()
{
    std::cout << "Predator starved at (" << this->x << ", " << this->y << ")!" << std::endl;
    world->setAt(this->x, this->y, nullptr);
    world->removePredator(this);
}

// Breed. If a Predator survives for eight time steps,
// then at the end of the time step it will spawn off a new Predator in the same manner as the Prey.
void Predator::breed()
{
    std::vector<std::pair<int, int>> adjacentCells = {
        std::make_pair(this->x, this->y + 1),
        std::make_pair(this->x, this->y - 1),
        std::make_pair(this->x + 1, this->y),
        std::make_pair(this->x - 1, this->y)
    };

    while (breedTicks >= 8) {

        int random = rand() % adjacentCells.size();
        int newX = adjacentCells[random].first;
        int newY = adjacentCells[random].second;

        if (newX >= 0 
                && newX < world->WORLDSIZE 
                && newY >= 0 
                && newY < world->WORLDSIZE
                && world->getAt(newX, newY) == nullptr) {
            world->setAt(newX, newY, new Predator(world, newX, newY));
            breedTicks = 0;
            return;
        } else {
            adjacentCells[random] = adjacentCells[adjacentCells.size() - 1];
            adjacentCells.pop_back();

            if (adjacentCells.size() == 0) {
                breedTicks = 0;
                return;
            }
        }
    }

    breedTicks++;
}

// Move. Every time step, if there is an adjacent Prey (up, down, left, or right),
// then the Predator will move to that cell and eat the Prey.
// Otherwise, the Predator moves according to the same rules as the Zoomies.
// Note that a Predator cannot eat other Swoopies.
void Predator::move()
{
    std::vector<std::pair<int, int>> adjacentCells = {
        std::make_pair(this->x, this->y + 1),
        std::make_pair(this->x, this->y - 1),
        std::make_pair(this->x + 1, this->y),
        std::make_pair(this->x - 1, this->y)
    };

    for (auto &cell : adjacentCells) {
        if (cell.first >= 0 
                && cell.first < world->WORLDSIZE 
                && cell.second >= 0 
                && cell.second < world->WORLDSIZE
                && world->getAt(cell.first, cell.second) != nullptr
                && world->getAt(cell.first, cell.second)->getType() == 1) {
            
            delete world->getAt(cell.first, cell.second);
            std::cout << "Predator ate Prey at (" << cell.first << ", " << cell.second << ")" << std::endl;
            world->setAt(cell.first, cell.second, this);
            world->setAt(this->x, this->y, nullptr);
            this->x = cell.first;
            this->y = cell.second;
            starveTicks = 0;
            return;
        }
    }

    Organism::move();
}

int Predator::getType()
{
    // Return Predator-specific type identifier here
    return 2;
}

// Starve. If a Predator has not eaten a Prey within the last three time steps,
// then at the end of the third time step it will starve and die. 
// The Predator should then be removed from the grid of cells.
bool Predator::starve()
{
    if (starveTicks >= 3) {
        delete this;
        return true;
    }

    starveTicks++;
    return false;
}

