/**
 * @file Organism.h
 * @brief Defines the Organism class which represents a creature in the World grid.
 *
 * @class Organism
 *
 * @details Abstract base class representing an organism in the World. The Organism class defines 
 * the common interface for all concrete organism types (inheritors of Organism) that populate the World grid.
 * It declares several pure virtual functions to enforce a common interface in derived classes. 
 * The Organism has attributes defining its state and position within the World.
 */

#include "World.h"

class Organism
{
friend class World;                     // Allow world to affect organism
public:
        Organism();
        Organism(World *world, int x, int y);
        ~Organism();
        virtual void breed() = 0;       // Whether or not to breed
        virtual void move() = 0;        // Rules to move the critter
        virtual int getType() =0;       // Return if Swoopie or Zoomie
        virtual bool starve() = 0;      // Determine if organism starves
protected:
        int x,y;                        // Position in the world
        bool moved;                     // Bool to indicate if moved this turn
        int breedTicks;                 // Number of ticks since breeding
        World *world;
};