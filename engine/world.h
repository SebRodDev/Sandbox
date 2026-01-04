#include <vector>
#include "entity.h"

class World {
public:
    World();
    void tick(float time);
    std::vector<Entity> getWorldState();
    // may want to change the velocity
    void applyInput(int elementId, float dx, float dy); 
private:
    std::vector<Entity> entities;
};
