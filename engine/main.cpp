#include <iostream>
#include <thread>
#include <chrono>
#include "world.cpp"

void printState(World currentWorld) {
    std::vector<Entity> entities = currentWorld.getWorldState();
    for (Entity entity : entities) {
        std::cout << "id: " << entity.id << "(" << entity.x << ", " << entity.y << ")\n"; 
    }
}

int main() {
    World world;
    while (true) {
        // 0.016 corresponds to 60 fps
        world.tick(0.016);
        printState(world);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
