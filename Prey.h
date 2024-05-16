/**
 * @file Prey.h
 * @brief Defines the Prey class, a type of Organism and a prey in the World grid.
 *
 * @class Prey
 *
 * @details Prey is a concrete implementation of the Organism class. It populates the World grid
 * and follows its own specific set of rules for movement and breeding - reflecting its behavior 
 * as prey in the ecosystem.
 */

#include "Organism.h"

class Prey : public Organism
{
public:
	Prey();
	Prey(World *world, int x, int y);
	~Prey();

	// Implementing Organism's pure virtual functions
	virtual void breed() override;
	virtual void move() override;
	virtual int getType() override;
	virtual bool starve() override;

	// You can add more Prey-specific methods here if needed

protected:
	// Prey-specific variables can go here, if any
};
