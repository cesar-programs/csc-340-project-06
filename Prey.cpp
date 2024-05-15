#include "Prey.h"

#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>

Prey::Prey()
{
    // Initialize Prey-specific attributes here, if they exist
}

Prey::Prey(World *world, int x, int y) : Organism(world, x, y)
{
    // Additional initialization for Prey-specific attributes here, if they exist
}

Prey::~Prey()
{
    // Destruction/cleanup logic specific to Prey goes here, if needed
}

// Breed. If a Prey survives for three time steps,
// then at the end of the time step (that is, after moving) the Prey will breed.
// This is simulated by creating a new Prey in an adjacent (up, down, left, or right) cell that is empty.
// If there is no empty cell available, then no breeding occurs. 
// Once an offspring is produced,  a Prey cannot produce an offspring until three more time steps have elapsed.
void Prey::breed()
{
    while (breedTicks >= 3) {
        std::vector<std::pair<int, int>> adjacentCells = {
            std::make_pair(this->x, this->y + 1),
            std::make_pair(this->x, this->y - 1),
            std::make_pair(this->x + 1, this->y),
            std::make_pair(this->x - 1, this->y)
        };

        int random = floor(rand() * adjacentCells.size());
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
            breedTicks = 0;
            return;
        } else {
            adjacentCells[random] = adjacentCells[adjacentCells.size() - 1];
            adjacentCells.pop_back();
        }
    }

    breedTicks++;
}

// Move. At every time step, randomly try to move up, down, left, or right. 
// If the neighboring cell in the selected direction is occupied or would
// move the Prey off the grid, then the Prey stays in the current cell.
void Prey::move()
{
    int random = floor(rand() * 4);
    int newX;
    int newY;

    switch (random) {
    case 0:
        newX = this->x;
        newY = this->y + 1;
        break;
    case 1:
        newX = this->x;
        newY = this->y - 1;
        break;
    case 2:
        newX = this->x + 1;
        newY = this->y;
        break;
    case 3:
        newX = this->x - 1;
        newY = this->y;
        break;
    }

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

int Prey::getType()
{
    return 1;
}