/**
 * @file World.h
 * @brief Defines the World class which manages a 2D grid of Organism objects.
 *
 * @class World
 *
 * @details World is managed via various public methods, with access provided 
 * to Organism, Swoopie and Zoomie. It includes grid access, display functionality, 
 * and simulation step methods. The size of the grid is defined by the private constant WORLDSIZE.
 */

// These are forward declarations; they are used because World uses pointers to these classes, but does not need to know their internal details.
class Organism; 
class Swoopie;
class Zoomie;

class World
{
    friend class Organism;
    friend class Swoopie;
    friend class Zoomie;
public:
    World();
    ~World();
    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org);
    void Display();
    void SimulateOneStep(); 
private:
    static constexpr int WORLDSIZE = 30;
    Organism* grid[WORLDSIZE][WORLDSIZE];
};
