#include "World.h"
#include "Organism.h"
#include "Predator.h"
#include "Prey.h"

World::World() {
    InitializeGame();
    GameLoop();
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
    Predators = NewPredators;
    SimulateOneStepPredators();
    Preys = NewPreys;
    std::cout << "Preys: " << Preys.size() << std::endl;
    SimulateOneStepPreys();
    Display();
}

void World::pushPredator(Organism* pred) {
    // Implementation goes here
    NewPredators.push_back(pred);
}

void World::pushPrey(Organism* prey) {
    // Implementation goes here
    NewPreys.push_back(prey);
}

void World::removePredator(Organism* pred) {
    for (int i = 0; i < NewPredators.size(); i++) {
        if (NewPredators[i] == pred) {
            NewPredators.erase(NewPredators.begin() + i);
            return;
        }
    }
}

void World::removePrey(Organism* prey) {
    std::cout << "removing prey..." << std::endl;
    for (int i = 0; i < NewPreys.size(); i++) {
        if (NewPreys[i] == prey) {
            NewPreys.erase(NewPreys.begin() + i);
            return;
        }
    }
}

void World::SimulateOneStepPredators() {
    for (auto & pred : Predators) {
        pred->move();
        pred->breed();
        pred->starve();
    }
}

void World::SimulateOneStepPreys() {
    for (auto & prey : Preys) {
        prey->move();
        prey->breed();
    }
}

void World::GameLoop() {
    while (true) {
        std::cout << "Press Enter to simulate one step." << std::endl;
        std::cin.get();
        SimulateOneStep();
    }
}

void World::InitializeGame() {
    int predCount, preyCount;
    
    std::cout << "Enter the number of predators: ";
    std::cin >> predCount;

    std::cout << std::endl << "Enter the number of preys: ";
    std::cin >> preyCount;

    if (predCount + preyCount > WORLDSIZE * WORLDSIZE)
    {
        std::cout << "ERROR: The number of predators and preys exceeds the maximum number of organisms allowed in the world." << std::endl;
    }

    std::cout << std::endl << "Initializing game with " << predCount << " predators and " << preyCount << " preys." << std::endl;
    
    Predators.reserve(predCount);
    NewPredators.reserve(predCount);
    Preys.reserve(preyCount);
    NewPreys.reserve(preyCount);

    for (int i = 0; i < predCount; i++) {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        while (getAt(x, y) != nullptr) {
            x = rand() % WORLDSIZE;
            y = rand() % WORLDSIZE;
        }
        setAt(x, y, new Predator(this, x, y));
    }

    for (int i = 0; i < preyCount; i++) {
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        while (getAt(x, y) != nullptr) {
            x = rand() % WORLDSIZE;
            y = rand() % WORLDSIZE;
        }
        setAt(x, y, new Prey(this, x, y));
    }

    std::cout << "Game Initialized" << std::endl << std::endl;
}